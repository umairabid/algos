class Tree {
	public:
		Node* root;
		Tree();
		void insert(int x);
		void inorder();
	
	private:
		void inorderTraversal(Node* tree);
		void insertInTree(Node* root, int x);
};