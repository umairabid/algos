#include <iostream>
#include <vector>
#include <fstream>
#include <sstream> 
#include "tree.h"

using namespace std;

void Tree::addEdge(int p, int n) {
    if (p >= tree.size()) {
        tree.resize(p+1);
    }
    tree[p].push_back(n);
}

void Tree::traverse(int root) {
    cout << root << " :\t";
    for(auto c : tree[root]) {
        cout << c << "\t";
    }
    for(auto c : tree[root]) {
        if(c < tree.size() && tree[c].size() > 0) {
            cout << "\n";
            traverse(c);
        }
    }
}

void Tree::fill(string filename) {
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
