class Tree {
	public:
		Node *root;
		Tree();
		void insert(int x);
		void inorder();
		Node* search(int x);
		Node* maximum();
		Node* minimum();
		Node* findSuccessor(Node *&node);

	private:
		// recursive
		void inorderTree(Node *&tree);
		void insertInTree(Node *&root, int x);
		Node* searchInTree(Node *&root, int x);
		Node* maximumInTree(Node *&root);
		Node* minimumInTree(Node *&root);

		//iterative
		void inorderTreeIterative(Node *&root);
		void insertInTreeIterative(Node *&root, int x);
		Node* searchInTreeIterative(Node *&root, int x);
};
