#include <iostream>
#include <cstddef>
#include "Node.h"

using namespace std;

Node::Node () {
	left = NULL;
	right = NULL;
	data = 0;
	predecessor = NULL;
}

Node::Node (int x) {
	left = NULL;
	right = NULL;
	predecessor = NULL;
	data = x;
}
