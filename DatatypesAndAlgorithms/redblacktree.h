#ifndef redblacktree
#define redblacktree
#include <string>

struct RedBlackTree{
	private:
		enum direction;
		enum colour;
		struct Node;
		Node* root = nullptr;
		int size = 0;
		int width = 0;
		std::string* strs;

		void FixInsertion(Node* node);
		void FixDeletion(Node* node, Node* parent, direction dir);
		void Rotate(Node* node, direction rotationDirection);
		void TraverseInOrder(Node* node, int tempwidth);
		void PrintTraverse(Node* node, int depth, int mode);
		RedBlackTree::Node* MinChild(Node* node);
		RedBlackTree::Node* MaxChild(Node* node);
		RedBlackTree::Node* Predecessor(Node* node);
		RedBlackTree::Node* Successor(Node* node);

	public: 
		void Insert(int val);
		void Delete(int val);
		void Free();
		void TestRotation(int val, int dir);
		void Print(int mode);
};

#endif