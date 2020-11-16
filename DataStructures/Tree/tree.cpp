#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <functional>
#include <unordered_map>
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

void Tree::traverse(int root) {
    unordered_map<int, bool> visited;
    function<void(int)> traverseNode = [&](int node) {
        cout << node << " :\t";
        visited[node] = true;
        for(auto c : nodes[node]) {
            cout << c << "\t";
        }
        for(auto c : nodes[node]) {
            if(visited.find(c) == visited.end()) {
                cout << "\n";
                traverseNode(c);
            }
        }
    };
    traverseNode(root);
    
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
    unordered_map<int, bool> visited;
    function<int(int)> getNodeHeight = [&](int node){
        visited[node] = true;
        vector<int> childrenHeights;
        for(int c : nodes[node]) {
            if (visited.find(c) == visited.end())
                childrenHeights.push_back(getNodeHeight(c));
        }
        int height = 1;
        if (childrenHeights.size() > 0) {
            height = *max_element(childrenHeights.begin(), childrenHeights.end()) + 1;
        } 
        heights[node] = height;
        return height;
    };
    getNodeHeight(root);
    return heights;
}
