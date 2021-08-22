#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-1");
    vector<int> res = tree.findCenters();
    for_each(res.begin(), res.end(), [](int x) { cout << x << " "; });
    return 0;
}