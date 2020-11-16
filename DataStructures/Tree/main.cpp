#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    Tree tree;
    tree.fill("edges-1");
    // tree.traverse(1);
    tree.getHeights(1);
    return 0;
}