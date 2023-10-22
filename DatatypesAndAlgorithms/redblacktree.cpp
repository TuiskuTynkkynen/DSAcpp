#include "redblacktree.h"

	enum RedBlackTree::direction{
		left = 0,
		right = 1
	};
	
	struct RedBlackTree::Node
	{
		int value;
		direction nodeDirection;
		Node* parent = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	void RedBlackTree::Insert(int val) {
		Node* node = new Node;
		node->value = val;
		
		if (root == nullptr) {
			root = node;
			return;
		}
	}

	void RedBlackTree::Rotate(Node* node, direction rotationDirection) {
		if (rotationDirection == left) {

		}
	}