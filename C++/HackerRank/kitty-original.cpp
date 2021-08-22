#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;

struct euler_path {
    vector<long> path;
    unordered_map<long, long> indexes;
    unordered_map<long, long> levels;

    void add_node(long data, long level) {
        this->path.push_back(data);
        if(indexes.find(data) == indexes.end()) {
            indexes[data] = path.size() - 1;
        }
        if(levels.find(data) == levels.end()) {
            levels[data] = level;
        }
    }
};

class Node {
public:
    vector<Node*> children;
    Node* parent;
    long data;
    Node();
    Node(long, Node*);
};

Node::Node() {
    parent = NULL;
    data = -1;
    children = vector<Node*>{};
}

Node::Node(long d, Node* p) {
    parent = p;
    data = d;
    children = vector<Node*>{};
}

map<long, vector<long>> generate_graph(vector<vector<long>> edges) {
    map<long, vector<long>> adjancy_list;
    for(long i = 0; i < edges.size(); i++) {
        vector<long> edge = edges[i];

        if(adjancy_list.find(edge[0]) == adjancy_list.end())
            adjancy_list[edge[0]] = vector<long>{};
        adjancy_list[edge[0]].push_back(edge[1]);

        if(adjancy_list.find(edge[1]) == adjancy_list.end())
            adjancy_list[edge[1]] = vector<long>{};
        adjancy_list[edge[1]].push_back(edge[0]);
    }
    return adjancy_list;
}

Node* generate_tree(vector<vector<long>> edges) {
    map<long, vector<long>> graph = generate_graph(edges);
    Node* root = new Node(graph.begin()->first, NULL);
    queue<Node*> q;
    unordered_map<long, bool> visited;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        visited[node->data] = true;
        vector<long> adj_nodes = graph[node->data];
        for(long i = 0; i < adj_nodes.size(); i++) {
            if(visited.find(adj_nodes[i]) == visited.end()) {
                node->children.push_back(new Node(adj_nodes[i], node));
            }
        }

        for(long i = 0; i < node->children.size(); i++) {
            q.push(node->children[i]);
        }
    }

    /*unordered_map<long, Node*> nodes;
    
    for(long i = 0; i < edges.size(); i++) {
        vector<long> edge = edges[i];

        if(nodes.find(edge[0]) == nodes.end()) {
            nodes.insert(pair<long, Node*>{edge[0], new Node(edge[0], NULL)});
        }
        Node* parent = nodes.find(edge[0])->second;

        if(nodes.find(edge[1]) == nodes.end()) {
            nodes.insert(pair<long, Node*>{edge[1], new Node(edge[1], parent)});
        }
        Node* child = nodes.find(edge[1])->second;

        if(i == 0) root = parent;
        parent->children.push_back(child);
    }*/
    return root;
}

euler_path get_euler_path(Node* root) {
    
    Node* node = root;
    euler_path ep;
    unordered_map<long, queue<Node*>*> uvc;
    long level = 1;

    while(node != NULL) {
        ep.add_node(node->data, level);
        if(uvc.find(node->data) == uvc.end()) {
            queue<Node*>* q = new queue<Node*>;
            for(long i = 0; i < node->children.size(); i++) {
                q->push(node->children[i]);
            }
            uvc[node->data] = q;
        }
        queue<Node*>* uv = uvc[node->data];
        if(!uv->empty()) {
            node = uv->front();
            uv->pop();
            level++;
        } else {
            node = node->parent;
            level--;
        }
    }

    return ep;
}

vector<long> get_log_table(vector<long> v) {
    vector<long> log_table(v.size() + 1, 0);
    for (long i = 2; i < log_table.size(); i++) 
        log_table[i] = log_table[i/2] + 1;
    return log_table;
}

vector<vector<long>> get_sparse_table(vector<long> v, vector<long> log_table) {
    vector<vector<long>> sparse_table(log_table.back() + 1, vector<long>(v.size()));
    sparse_table[0] = v;
    for (long row = 1; row < sparse_table.size(); row++) {
        for (long i = 0; i + (1 << row) <= v.size(); i++) {
            sparse_table[row][i] = min(sparse_table[row-1][i], sparse_table[row-1][i+(1<<(row-1))]);
        }
    }
    return sparse_table;
}

vector<long> explodeStringBySpace(string s) {
    stringstream ssin(s);
    vector<long> nodes;
    string node;
    while (ssin.good()){
        ssin >> node;
        nodes.push_back(stol(node));
    }
    return nodes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long number_of_nodes;
    long number_of_edges;
    long number_of_sets;
    long line_count = 0;

    vector<vector<long>> sets;
    vector<vector<long>> edges;

    ifstream infile("input07.txt");
    string line;

    while(getline(infile, line)) {
        if(line_count == 0) {
            vector<long> counts = explodeStringBySpace(line);
            number_of_nodes = counts[0];
            number_of_sets = counts[1];
            number_of_edges = number_of_nodes - 1;
        }

        if(line_count > 0 && line_count <= number_of_edges) {
            edges.push_back(explodeStringBySpace(line));
        }

        if(line_count > number_of_edges) {
            if(line_count % 2 != 0) {
                sets.push_back(explodeStringBySpace(line));
            }
        }

        line_count++;
    }
   

    /** Actual Solution Starts **/
   
    Node* root = generate_tree(edges);
    euler_path ep = get_euler_path(root);
    cout << endl;
    vector<long> log_table = get_log_table(ep.path);
    vector<vector<long>> sparse_table = get_sparse_table(ep.path, log_table);

    for(long i = 0; i < sets.size(); i++) {
        if(sets[i].size() > 1) {
            long sum = 0;
            for(long j = 0; j < sets[i].size() ; j++) {
                for(long k = j + 1; k < sets[i].size() ; k++) {
                    long n1 = sets[i][j];
                    long n2 = sets[i][k];
                    cout << "node 1: " << n1 << ", node 2: " << n2 << endl;
                    long n1_index = ep.indexes.find(n1)->second;
                    long n2_index = ep.indexes.find(n2)->second;
                    long l = n1_index < n2_index ? n1_index : n2_index;
                    long r = n1_index > n2_index ? n1_index : n2_index;
                    long log = log_table[r - l];
                    long lca = min(sparse_table[log][l], sparse_table[log][r - (1 << log)]);
                    //cout << "lca of " << n1 << " with index " << n1_index << " and " << n2 << " with index " << n2_index << " is " << lca << endl;
                    
                    long level_of_lca = ep.levels.find(lca)->second;
                    long level_of_n1 = ep.levels.find(n1)->second;
                    long level_of_n2 = ep.levels.find(n2)->second;
                    long dist = (level_of_n1 - level_of_lca) + (level_of_n2 - level_of_lca);
                    sum = sum + ((n1 * n2) * dist);
                }
            }
            cout << sum % 1000000007 << endl;
        } else {
            cout << 0 << endl;
        }
    }


    /** Actual Solution Ends **/

    return 0;
}
