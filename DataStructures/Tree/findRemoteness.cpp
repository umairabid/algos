#include <iostream>
#include <algorithm>
#include <functional>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-1");
    vector<int> nodes = tree.dfs(1);
    vector<int> remoteness(nodes.size()); 

    for(int n : nodes) {
        remoteness[n] = tree.findFarthest(n).second;
    }

    for(int i = 1; i <= remoteness.size(); i++) {
        cout << i << " : " << remoteness[i] << endl;
    }

    return 0;
}