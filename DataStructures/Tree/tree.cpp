#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <functional>
#include <queue>
#include "tree.h"

using namespace std;

void Tree::addEdge(int p, int n) {
    if (p >= nodes.size()) {
        nodes.resize(p+1);
    }
    if (n >= nodes.size()) {
        nodes.resize(n+1);
    }
    nodes[p].push_back(n);
    nodes[n].push_back(p);
}

void Tree::traverse() {
    for(int i = 0; i < nodes.size(); i++) {
        cout << i << ":\t";
        for(auto c: nodes[i]) {
            cout << c << "\t";
        }
        cout << endl;
    }
}

void Tree::fill(string filename) {
    nodes = vector<vector<int>>{};
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
    vector<int> distances(nodes.size(), -1);
    queue<int> q;

    int maxDistance = 0;
    q.push(root);
    distances[root] = 0;

    while(!q.empty()) {
        int node = q.front();
        int distance = distances[node];
        q.pop();

        for(int c : nodes[node]) {
            if (distances[c] != -1) continue;
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
