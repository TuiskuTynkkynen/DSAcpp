#ifndef redblacktree
#define redblacktree

struct RedBlackTree{
	private:
		enum direction;
		struct Node;
		Node* root = nullptr;

	public: 
		void Insert(int val);
		void Rotate(Node* node, direction rotationDirection);
};

#endif