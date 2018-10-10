class Tree {
	public:
		Node *root;
		Tree();
		void insert(int x);
		void inorder();

	private:
		// recursive
		void inorderTree(Node *&tree);
		void insertInTree(Node *&root, int x);

		//iterative
		void inorderTreeIterative(Node *&root);
		void insertInTreeIterative(Node *&root, int x);
		
};
