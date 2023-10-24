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

		if (root == nullptr) {
			node->nodeColour = BLACK;
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
		node->nodeColour = RED;

		if (val < parent->value) {
			parent->left = node;
			node->nodeDirection = LEFT;
		}
		else if (val > parent->value) {
			parent->right = node;
			node->nodeDirection = RIGHT;
		}

		FixInsertion(node);
	}
	
	void RedBlackTree::FixInsertion(Node* node) {
		Node* parent = node->parent;
		Node* grandParent;
		Node* uncle;
		direction parentDirection;
		direction reverseDirection;
		while (parent != nullptr && parent->nodeColour == RED) { //Parent is red and not root
			grandParent = parent->parent;
			if (grandParent == nullptr) {
				break;
			}
			parentDirection = parent->nodeDirection;
			reverseDirection = static_cast<direction>(1 - parentDirection);
			uncle = grandParent->child[reverseDirection];

			if (uncle == nullptr || uncle->nodeColour == BLACK) { //uncle is or is considered black
				if (node->nodeDirection == reverseDirection) {
					node = parent;
					Rotate(node, parentDirection);
					parent = grandParent->child[parentDirection];
				}
				Rotate(grandParent, reverseDirection);
				parent->nodeColour = BLACK;
				grandParent->nodeColour = RED;
			}
			else {
				uncle->nodeColour = BLACK;
				parent->nodeColour = BLACK;
				grandParent->nodeColour = RED;
				node = grandParent;
				parent = node->parent;
			}
		}
		root->nodeColour = BLACK;
	}

	void RedBlackTree::Delete(int val) {
		Node* node = root;
		Node* parent = nullptr;

		while (node != nullptr) {
			if (node->value == val) {
				break;
			} else if (val < node->value) {
				parent = node;
				node = node->left;
			} else {
				parent = node;
				node = node->right;
			}
		}

		if (node == nullptr) {
			return;
		}

		colour originalColour = node->nodeColour;
		//if deleted node doesn't have two child nodes 
		if (!(node->left != nullptr && node->right != nullptr)) {
			direction dir = node->nodeDirection;
			Node* temp = nullptr;

			if (node->left != nullptr) { //if deleted node has left child
				temp = node->left;
			} else if (node->right != nullptr) { //if deleted node has right child
				temp = node->right;
			}

			if (parent == nullptr) {  //replace tree
				delete[] root;
				root = temp;
				if (temp != nullptr) {
					temp->parent = nullptr;
				} else {
					return;
				}
			} else {                           //replace right child of parent node or nullptr
				delete[] parent->child[dir];
				parent->child[dir] = temp;
				if (temp != nullptr) {
					temp->parent = parent;
					temp->nodeDirection = dir;
				}
			}

			if (originalColour == BLACK) {
				FixDeletion(temp, parent, dir);
			}
		} else {  //else deleted node has two child nodes 
			Node* temp = Successor(node);
			//originalColour = temp->nodeColour;
			Node* tempRight = temp->right;
			Node* tempParent = temp;

			if (node->right != temp) { //if temp is NOT child of deleted node
				temp->parent->left = tempRight;
				tempParent = temp->parent;
				if (tempRight != nullptr) {
					tempRight->parent = temp->parent;
					tempRight->nodeDirection = LEFT;
				}

				temp->right = node->right;
				node->right->parent = temp;
			}

			temp->left = node->left;
			if (parent == nullptr) {  //replace tree
				root->left->parent = temp;
				root->right->parent = temp;
				delete[] root;
				root = temp;
				if (temp != nullptr) {
					temp->parent = nullptr;
				} else {
					return;
				}
			} else {
				direction dir = node->nodeDirection;
				delete[] parent->child[dir];
				parent->child[dir] = temp;
				if (temp != nullptr) {
					temp->parent = parent;
					temp->nodeDirection = dir;
				}
			}

			if (originalColour == BLACK) {
				FixDeletion(temp, tempParent, RIGHT);
			}
		}
	}

	void RedBlackTree::FixDeletion(Node* node, Node* parent, direction dir) {
		//DOESN'T WORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		direction reverseDir;
		Node* sibling;

		while (node != root && (node == nullptr || node->nodeColour == BLACK)) {
			if (node != nullptr) {
				dir = node->nodeDirection;
			}
			reverseDir = static_cast<direction>(1 - dir);
			
			sibling = parent->child[reverseDir];

			std::cout << node << "/" << parent << "/" << sibling << "\n";
			int nval = (node != nullptr) ? node->value : 0;
			int pval = (parent != nullptr) ? parent->value : 0;
			int sval = (sibling != nullptr) ? sibling->value : 0;
			std::cout << nval << "/" << pval << "/" << sval << "\n";
			if (sibling->nodeColour == RED) {
				sibling->nodeColour = BLACK;
				parent->nodeColour = RED;
				Rotate(parent, dir);
				sibling = parent->child[reverseDir];
			}

			bool isSiblingLeftBlack = (sibling->left == nullptr || sibling->left->nodeColour == BLACK);
			bool isSiblingRightBlack = (sibling->right == nullptr || sibling->right->nodeColour == BLACK);
			if (isSiblingLeftBlack && isSiblingRightBlack) {
				std::cout << "\n";
				sibling->nodeColour = RED;
				node = parent;
				parent = node->parent;
			} else {
				parent = node->parent;
				if (sibling->child[reverseDir]->nodeColour == BLACK) {
					sibling->child[dir]->nodeColour = BLACK;
					sibling->nodeColour = RED;
					Rotate(sibling, reverseDir);
					sibling = parent->child[reverseDir];
				}

				sibling->nodeColour = parent->nodeColour;
				parent->nodeColour = BLACK;
				sibling->child[reverseDir]->nodeColour = BLACK;
				Rotate(parent, dir);
				node = root;
			}

		}
		node->nodeColour = BLACK;
	}

	void RedBlackTree::Free() {
		if (root == nullptr) {
			return;
		}

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
		} else if (node->value < parent->value) {
			std::cout << "freed node with value: " << parent->left->value << "\n";
			delete[] parent->left;
			parent->left = nullptr;
			Free();
		} else if (node->value > parent->value) {
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
		direction reverseDirection = static_cast<direction>(1 - rotationDirection);
		
		Node* temp = node->child[reverseDirection];
		if (temp == nullptr) {
			return;
		}

		node->child[reverseDirection] = temp->child[rotationDirection];
		if (temp->child[rotationDirection] != nullptr) {
			temp->child[rotationDirection]->parent = node;
			temp->child[rotationDirection]->nodeDirection = reverseDirection;
		}

		temp->parent = node->parent;
		if (node->parent == nullptr) {
			root = temp;
		} else {
			node->parent->child[node->nodeDirection] = temp;
			temp->nodeDirection = node->nodeDirection;
		}

		temp->child[rotationDirection] = node;
		node->parent = temp;
		node->nodeDirection = rotationDirection;

		std::cout << "temp = " << temp->value;
		if (temp->parent != nullptr)
		{
			std::cout << " temp parent = " << temp->parent->value;
		}
		std::cout << "\n node = " << node->value;
		if (node->parent != nullptr)
		{
			std::cout << " node parent = " << node->parent->value;
		}
		std::cout << "\n";
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

	RedBlackTree::Node* RedBlackTree::MinChild(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	RedBlackTree::Node* RedBlackTree::MaxChild(Node* node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	RedBlackTree::Node* RedBlackTree::Predecessor(Node* node) {
		if (node->left != nullptr) {
			return MaxChild(node->left);
		}

		Node* parent = node->parent;
		while (parent != nullptr && node->nodeDirection == LEFT) {
			node = parent;
			parent = node->parent;
		}
		return parent;
	}

	RedBlackTree::Node* RedBlackTree::Successor(Node* node) {
		if (node->right != nullptr) {
			return MinChild(node->right);
		}

		Node* parent = node->parent;
		while (parent != nullptr && node->nodeDirection == RIGHT) {
			node = parent;
			parent = node->parent;
		}
		return parent;
	}
