#include <iostream>
#include <algorithm>
#include <functional>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-2");
    vector<int> heights = tree.getHeights(11);
    vector<int> longestPaths;
    function<void(int, int)> dfsTree = [&](int node, int parent) {

        vector<int> children(tree.nodes[node].size());
        vector<int>::iterator it = remove_copy(
            tree.nodes[node].begin(),
            tree.nodes[node].end(),
            children.begin(),
            parent
        );
        children.erase(it, children.end());

        if(children.size() == 0)
            longestPaths.push_back(0);
        
        if(children.size() == 1)
            longestPaths.push_back(heights[children[0]] + 1);
        
        if(children.size() >= 2) {
            sort(children.begin(), children.end(), [&](int x, int y) { return heights[x] > heights[y]; });
            longestPaths.push_back(
                (heights[children[0]] + 1) +
                (heights[children[1]] + 1)
            );
        }
        
        for(auto c : tree.nodes[node]) {
            if (c == parent) continue;
            dfsTree(c, node);
        }
    };

    dfsTree(11, -1);

    cout << *max_element(longestPaths.begin(), longestPaths.end());

    return 0;
}