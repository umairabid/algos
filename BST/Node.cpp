#include <iostream>
#include <cstddef>
#include "Node.h"

using namespace std;

Node::Node () {
	left = NULL;
	right = NULL;
	data = 0;
}

Node::Node (int x) {
	left = NULL;
	right = NULL;
	data = x;
}