#include <iostream>
#include <algorithm>
#include <functional>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-2");

    pair<int, int> r = tree.findFarthest(11);
    pair<int, int> s = tree.findFarthest(r.first);
    cout << s.second;
    
    return 0;
}