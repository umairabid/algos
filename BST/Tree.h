class Tree {
	public:
		Node *root;
		Tree();
		void insert(int x);
		void inorder();
		void preorder();
		void inorder();
		void remove(Node *&node);
		Node* search(int x);
		Node* maximum();
		Node* minimum();
		Node* findSuccessor(Node *&node);

	private:
		void inorderTree(Node *&tree);
		void preorderTree(Node *&tree);
		void postorderTree(Node *&tree);
		void insertInTree(Node *&root, int x);
		Node* searchInTree(Node *&root, int x);
		Node* maximumInTree(Node *&root);
		Node* minimumInTree(Node *&root);
		void transplant(Node *&old, Node *&newNode);
};
