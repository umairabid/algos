#include <map>
using namespace std;
class Tree {
	public:
		Node *root;
		Tree();
		void insert(int x);
		void inorder();
		void preorder();
		void postorder();
		void levelorder();
		void remove(Node *&node);
		void getNodesDistance();
		Node* search(int x);
		Node* maximum();
		Node* minimum();
		Node* findSuccessor(Node *&node);
		int getLength();

	private:
		int length;
		void inorderTree(Node *&tree);
		void preorderTree(Node *&tree);
		void postorderTree(Node *&tree);
		void levelorderTree(Node *&tree);
		void insertInTree(Node *&root, int x);
		Node* searchInTree(Node *&root, int x);
		Node* maximumInTree(Node *&root);
		Node* minimumInTree(Node *&root);
		void transplant(Node *&old, Node *&newNode);
		void getNodesDistanceInTree(Node *&node, int distance, int level, map<int, pair<int, int> > &distances);
};
