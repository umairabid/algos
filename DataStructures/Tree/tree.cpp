#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include "tree.h"

using namespace std;

Tree::Tree() { }

Tree::Tree(const Tree &t) {
    nodes = t.nodes;
}

void Tree::addEdge(int p, int n) {
    if(nodes.find(p) == nodes.end()) {
        nodes[p] = vector<int>();
    }

    if(nodes.find(n) == nodes.end()) {
        nodes[n] = vector<int>();
    }

    nodes[p].push_back(n);
    nodes[n].push_back(p);
}

void Tree::traverse() {
    for(auto it = nodes.begin(); it != nodes.end(); it++) {
        cout << it->first << ":\t";
        for(auto c: it->second) {
            cout << c << "\t";
        }
        cout << endl;
    }
}

void Tree::fill(string filename) {
    nodes = unordered_map<int, vector<int>>();
    ifstream stream(filename);
    string line;

    while(getline(stream, line)) {
        stringstream ss(line);
        string numbers;
        getline(ss, numbers, ' ');
        int a = stoi(numbers);
        getline(ss, numbers, ' ');
        int b = stoi(numbers);
        addEdge(a, b);
    }
}

// should only be used for leaf nodes
void Tree::removeNode(int node) {
    for_each(nodes[node].begin(), nodes[node].end(), [&](int c) {
        vector<int>::iterator it = find(nodes[c].begin(), nodes[c].end(), node);
        nodes[c].erase(it); 
    });
    nodes.erase(node);
}

int Tree::size() {
    return nodes.size();
}

vector<int> Tree::getHeights(int root) {
    vector<int> heights(nodes.size());
    function<int(int, int)> getNodeHeight = [&](int node, int parent){
        vector<int> childrenHeights;
        for(int c : nodes[node]) {
            if (c == parent) continue;
            childrenHeights.push_back(getNodeHeight(c, node));
        }
        int height = 0;
        if (childrenHeights.size() > 0) {
            height = *max_element(childrenHeights.begin(), childrenHeights.end()) + 1;
        } 
        heights[node] = height;
        return height;
    };
    getNodeHeight(root, -1);
    return heights;
}

vector<int> Tree::dfs(int root) {
    vector<int> nodesByDfs;
    function<void(int, int)> dfsTree = [&](int node, int parent) {
        nodesByDfs.push_back(node);
        for(auto c : nodes[node]) {
            if (c == parent) continue;
            dfsTree(c, node);
        }
    };
    dfsTree(root, -1);
    return nodesByDfs;
}

vector<int> Tree::bfs(int root) {
    vector<int> nodesByBfs;
    queue<int> q;
    vector<int> visited(nodes.size(), -1);
    q.push(root);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        nodesByBfs.push_back(node);
        visited[node] = true;
        for(int c : nodes[node]) {
            if (visited[c] != -1) continue;
            q.push(c);
        }
    }
    return nodesByBfs;
}

pair<int, int> Tree::findFarthest(int root) {
    unordered_map<int, int> distances;
    queue<int> q;

    int maxDistance = 0;
    q.push(root);
    distances[root] = 0;

    while(!q.empty()) {
        int node = q.front();
        int distance = distances[node];
        q.pop();

        for(int c : nodes[node]) {
            if (distances.find(c) != distances.end()) continue;
            distances[c] = distance + 1;
            if (distances[c] > maxDistance)
                maxDistance = distances[c];
            q.push(c);
        }
    }

    int farthestNode;
    for(int i = 0; i < distances.size(); i++) {
        if(distances[i] == maxDistance) {
            farthestNode = i;
            break;
        }
    }

    return make_pair(farthestNode, maxDistance);
}

vector<int> Tree::getLeafNodes() {
    vector<int> leafs;
    for(auto it = nodes.begin(); it != nodes.end(); it++) {
        if (it->second.size() <= 1) leafs.push_back(it->first);
    }
    return leafs;
}

vector<int> Tree::findCenters() {
    vector<int> leafs = getLeafNodes();
    if (leafs.size() == size())
        return leafs;
    else {
        Tree clone = *this;
        for (int l: leafs) {
            clone.removeNode(l);
        }
        return clone.findCenters();
    }
}
