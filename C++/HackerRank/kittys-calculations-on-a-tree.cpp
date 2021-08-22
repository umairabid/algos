#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

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

int main() {
	vector<vector<long>> edges;
	edges.push_back(vector<long> {1, 2});
	edges.push_back(vector<long> {1, 3});
	edges.push_back(vector<long> {1, 4});
	edges.push_back(vector<long> {3, 5});
	edges.push_back(vector<long> {3, 6});
	edges.push_back(vector<long> {3, 7});
	Node* root = generate_tree(edges);
	euler_path ep = get_euler_path(root);
	for(long i = 0; i < ep.path.size(); i++) {
		cout << ep.path[i] << " ";
	}
	cout << endl;
	vector<long> log_table = get_log_table(ep.path);
	vector<vector<long>> sparse_table = get_sparse_table(ep.path, log_table);
	vector<vector<long>> sets = {
		vector<long>{2, 4},
		vector<long>{5},
		vector<long>{2, 4, 5}
	};


	for(long i = 0; i < sets.size(); i++) {
        if(sets[i].size() > 1) {
            long sum = 0;
            vector<pair<long, long>> pairs;
            for(long j = 0; j < sets[i].size() ; j++) {
                for(long k = j + 1; k < sets[i].size() ; k++) {
                    pairs.push_back(pair<long, long>{sets[i][j], sets[i][k]});
                }
            }
            for(long m = 0; m < pairs.size(); m++) {
                long n1 = pairs[m].first;
                long n2 = pairs[m].second;
                long n1_index = ep.indexes.find(n1)->second;
                long n2_index = ep.indexes.find(n2)->second;
                long l = n1_index < n2_index ? n1_index : n2_index;
                long r = n1_index > n2_index ? n1_index : n2_index;
                long log = log_table[r - l];
        		long lca = min(sparse_table[log][l], sparse_table[log][r - (1 << log)]);
        		cout << "lca of " << n1 << " with index " << n1_index << " and " << n2 << " with index " << n2_index << " is " << lca << endl;
                
                long level_of_lca = ep.levels.find(lca)->second;
                long level_of_n1 = ep.levels.find(n1)->second;
                long level_of_n2 = ep.levels.find(n2)->second;
                long dist = (level_of_n1 - level_of_lca) + (level_of_n2 - level_of_lca);
                sum = sum + ((n1 * n2) * dist);
            }
            cout << sum % 1000000007 << endl;
        } else {
            cout << 0 << endl;
        }
    }
	
	return 0;
}