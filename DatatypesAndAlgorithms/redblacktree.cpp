#include "redblacktree.h"
#include <iostream>
#include <string>

	enum RedBlackTree::direction{
		LEFT = 0,
		RIGHT = 1
	};

	enum RedBlackTree::colour{
		BLACK = 0,
		RED = 1
	};
	
	struct RedBlackTree::Node
	{
		int value;
		colour nodeColour;
		direction nodeDirection;
		Node* parent = nullptr;
		Node* child[2] = {nullptr, nullptr};
		#define left child[LEFT]
		#define right child[RIGHT]
	};

	void RedBlackTree::Insert(int val) {
		Node* node = new Node;
		node->value = val;
		node->parent = nullptr;
		node->nodeColour = BLACK;

		if (root == nullptr) {
			root = node;
			return;
		}

		Node* parent = nullptr;
		Node* temp = root;
		while (temp != nullptr) {
			parent = temp;
			if (val < temp->value) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}

		node->parent = parent;
		if (parent->nodeColour == BLACK) {
			node->nodeColour = RED;
		}

		if (val < parent->value) {
			parent->left = node;
			node->nodeDirection = LEFT;
		}
		else if (val > parent->value) {
			parent->right = node;
			node->nodeDirection = RIGHT;
		}

	}

	void RedBlackTree::Free() {
		Node* node = root;
		Node* parent = nullptr;
		while (node->left != nullptr || node->right != nullptr) {
			parent = node;
			if (node->left != nullptr) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}

		if (parent == nullptr) {
			std::cout << "freed root node with value: " << root->value << "\n";
			delete[] root;
			root = nullptr;
		}
		else if (node->value < parent->value) {
			std::cout << "freed node with value: " << parent->left->value << "\n";
			delete[] parent->left;
			parent->left = nullptr;
			Free();
		}
		else if (node->value > parent->value) {
			std::cout << "freed node with value: " << parent->right->value << "\n";
			delete[] parent->right;
			parent->right = nullptr;
			Free();
		}
	}

	void RedBlackTree::TestRotation(int val, int dir) {
		Node* node = root;
		Node* next = root;
		while (val != node->value) {
			node = next;
			if (val < node->value) {
				next = node->left;
			} else {
				next = node->right;
			}

			if (next == nullptr) {
				return;
			}
		}
		if (dir == 0) {
			Rotate(node, LEFT);
		} else {
			Rotate(node, RIGHT);
		}
	}

	void RedBlackTree::Rotate(Node* node, direction rotationDirection) {
		direction nodeDirection = node->nodeDirection;

		Node* temp = node->child[1-rotationDirection];
		if (temp == nullptr) {
			return;
		}

		if (node->parent == nullptr) {
			root = temp;
		} else {
			node->parent->child[nodeDirection] = temp;
		}

		node->child[1 - rotationDirection] = temp->child[rotationDirection];
		temp->child[rotationDirection] = node; 
	}

	void RedBlackTree::Print(int mode) {
		size = 0;
		width = 0;
		TraverseInOrder(root, 0);
		strs = new std::string[width * 2];
		std::cout << "Red-black tree: \n";
		PrintTraverse(root, 0, mode);
		for (int i = 0; i < width * 2; i++) {
			if (!strs[i].empty()) {
				std::cout << strs[i] << "\n";
			}
		}
		delete[] strs;
	}
	
	void RedBlackTree::TraverseInOrder(Node* node, int tempwidth) {
		if (node != nullptr) {
			TraverseInOrder(node->left, tempwidth);
			tempwidth++;
			size++;
			TraverseInOrder(node->right, tempwidth);
			tempwidth--;
		}

		if (abs(tempwidth) > width) {
			width = abs(tempwidth);
		}
	}

	void RedBlackTree::PrintTraverse(Node* node, int depth, int mode) {
		if (node != nullptr) {
			depth++;
			PrintTraverse(node->left, depth, mode);
			PrintTraverse(node->right, depth, mode);
			depth--;

			int distance = 0;
			Node* temp = root;
			while (node->value != temp->value) {
				if (node->value < temp->value) {
					temp = temp->left;
					distance++;
				}
				else {
					temp = temp->right;
					distance--;
				}
			}
			
			while (strs[width - distance].length() < 3 * depth + 1) {
				strs[width - distance] += " ";
			}
			
			std::string val;
			if (mode == 0) {
				val = std::to_string(node->value);
			} else {
				val = (node->nodeColour == BLACK)? "B" : "R";
			}
			
			for (int i = 0; i < val.length(); i++) {
				strs[width - distance][depth * 2 + i] = (strs[width - distance][depth * 2 + i] == ' ') ? val[i] : '?';
			}
			if (node->left != nullptr && node->right != nullptr) {
				strs[width - distance][depth * 2 + val.length()] = '<';
			}
			else if (node->left != nullptr) {
				strs[width - distance][depth * 2 + val.length()] = 217;
			}
			else if (node->right != nullptr) {
				strs[width - distance][depth * 2 + val.length()] = 191;
			}
		}
	}
