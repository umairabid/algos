#include <vector>

#ifndef TREE_H
#define TREE_H

struct Tree {
    std::vector<std::vector<int>> tree;
    void addEdge(int, int);
    void traverse(int);
    void fill(std::string);
};

#endif
