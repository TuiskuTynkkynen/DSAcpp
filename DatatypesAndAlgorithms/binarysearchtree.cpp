#include "binarysearchtree.h"
#include <iostream>
#include <string>

	struct BinarySearchTree::Node
	{
		int value;
		Node* left{};
		Node* right{};
	};

	void BinarySearchTree::Insert(int val) {
		Node* node = new Node;
		node->value = val;

		if (tree == nullptr) {
			tree = node;
			return;
		}

		Node* parent = nullptr;
		Node* temp = tree;
		while (temp != nullptr) {
			parent = temp;
			if (val < temp->value) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}

		if (val < parent->value) {
			parent->left = node;
		}
		else if (val > parent->value) {
			parent->right = node;
		}
	}

	void BinarySearchTree::Delete(int val) {
		Node* node = tree;
		Node* parent = nullptr;

		while (node != nullptr) {
			if (node->value == val) {
				break;
			}
			else if (val < node->value) {
				parent = node;
				node = node->left;
			}
			else {
				parent = node;
				node = node->right;
			}
		}

		if (node == nullptr) {
			return;
		}

		//if deleted node doesn't have two child nodes 
		if (!(node->left != nullptr && node->right != nullptr)) {
			Node* temp = nullptr;

			if (node->left != nullptr) { //if deleted node has left child
				temp = node->left;
			}
			else if (node->right != nullptr) { //if deleted node has right child
				temp = node->right;
			}

			if (parent == nullptr) {  //replace tree
				delete[] tree;
				tree = temp;
			}
			else if (node->value < parent->value) { //replace left child of parent node or nullptr
				delete[] parent->left;
				parent->left = temp;
			}
			else {                           //replace right child of parent node or nullptr
				delete[] parent->right;
				parent->right = temp;
			}
		}
		else {  //else deleted node has two child nodes 
			Node* temp = Successor(node);

			if (node->right != temp) { //if temp is NOT child of deleted node
				Parent(temp)->left = temp->right;
				temp->right = node->right;
			}

			temp->left = node->left;
			if (parent == nullptr) {  //replace tree
				delete[] tree;
				tree = temp;
			}
			else if (node->value < parent->value) {
				delete[] parent->left;
				parent->left = temp;
			}
			else {
				delete[] parent->right;
				parent->right = temp;
			}
		}
	}

	void BinarySearchTree::Free() {
		Node* node = tree;
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
			std::cout << "freed root node with value: " << tree->value << "\n";
			delete[] tree;
			tree = nullptr;
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

	bool BinarySearchTree::Search(int val) {
		Node* node = tree;
		while (node != nullptr) {
			if (node->value == val) {
				return true;
			}
			else if (node->value > val) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return false;
	}

	int BinarySearchTree::Min() {
		Node* node = MinChild(tree);
		return node->value;
	}

	int BinarySearchTree::Max() {
		Node* node = MaxChild(tree);
		return node->value;
	}

	int BinarySearchTree::Size() {
		size = 0;
		inOrder(tree, 0);
		return size;
	}

	void BinarySearchTree::Print() {
		size = 0;
		width = 0;
		inOrder(tree, 0);
		strs = new std::string[width * 2];
		std::cout << "Binary tree: \n";
		PrintTraverse(tree, 0);
		for (int i = 0; i < width * 2; i++) {
			if (!strs[i].empty()) {
				std::cout << strs[i] << "\n";
			}
		}
		delete[] strs;
	}

	void BinarySearchTree::inOrder(Node* node, int tempwidth) {
		if (node != nullptr) {
			inOrder(node->left, tempwidth);
			tempwidth++;
			size++;
			inOrder(node->right, tempwidth);
			tempwidth--;
		}

		if (abs(tempwidth) > width) {
			width = abs(tempwidth);
		}
	}

	void BinarySearchTree::PrintTraverse(Node* node, int depth) {
		if (node != nullptr) {
			depth++;
			PrintTraverse(node->left, depth);
			PrintTraverse(node->right, depth);
			depth--;

			int distance = 0;
			Node* temp = tree;
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
			std::string val = std::to_string(node->value);
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

	BinarySearchTree::Node* BinarySearchTree::MinChild(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	BinarySearchTree::Node* BinarySearchTree::MaxChild(Node* node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	BinarySearchTree::Node* BinarySearchTree::Parent(Node* node) {
		Node* parent = nullptr;
		Node* temp = tree;
		while (node->value != temp->value) {
			if (node->value < temp->value) {
				parent = temp;
				temp = temp->left;
			}
			else {
				parent = temp;
				temp = temp->right;
			}
		}
		return parent;
	}

	BinarySearchTree::Node* BinarySearchTree::Predecessor(Node* node) {
		if (node->left != nullptr) {
			return MaxChild(node->left);
		}

		Node* parent = Parent(node);
		while (parent != nullptr && node == parent->left) {
			node = parent;
			parent = Parent(node);
		}
		return parent;
	}

	BinarySearchTree::Node* BinarySearchTree::Successor(Node* node) {
		if (node->right != nullptr) {
			return MinChild(node->right);
		}

		Node* parent = Parent(node);
		while (parent != nullptr && node == parent->right) {
			node = parent;
			parent = Parent(node);
		}
		return parent;
	}