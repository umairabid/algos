#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


Node *lca(Node *root, int v1,int v2) {
    vector<int> path1;
    Node* node1 = root;
    map<int, Node*> nodes;
    while(node1) {
    	path1.push_back(node1->data);
	    nodes.insert(pair<int, Node*>(node1->data, node1));
    	if(node1->data == v1) {
    		node1 = NULL;
    	} else {
    		node1 = v1 > node1->data ? node1->right : node1->left;
    	}
        
    }

    vector<int> path2;
    Node* node2 = root;
    while(node2) {
    	path2.push_back(node2->data);
	    nodes.insert(pair<int, Node*>(node2->data, node2));
    	if(node2->data == v2) {
    		node2 = NULL;
    	} else {
    		node2 = v2 > node2->data ? node2->right : node2->left;
    	}
        
    }

    vector<int> intersect;
    set_intersection(path1.begin(),path1.end(),path2.begin(),path2.end(),
                  std::inserter(intersect,intersect.begin()));

    for(auto it = path1.begin() ; it != path1.end(); it++) {
    	cout << *it << "\t";
    }
    cout <<"\n";

    for(auto it = path2.begin() ; it != path2.end(); it++) {
    	cout << *it << "\t";
    }
    cout <<"\n";

    for(auto it = intersect.begin() ; it != intersect.end(); it++) {
    	cout << *it << "\t";
    }
    cout <<"\n";
    
    return nodes.find(*intersect.rbegin())->second;
}

int main() {
	Node *root = new Node(4);
	Node *node2 = new Node(2);
	node2->left = new Node(1);
	node2->right = new Node(3);
	Node *node7 = new Node(7);
	node7->left = new Node(6);
	root->left = node2;
	root->right = node7;
	cout << lca(root, 1, 3)->data << "\n";
	return 0;
}