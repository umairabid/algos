#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-1");

    unordered_map<int, int> maxTrees = tree.getMaxTrees(12);

    cout << min_element(maxTrees.begin(), maxTrees.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    })->first << endl;
    
    return 0;
}