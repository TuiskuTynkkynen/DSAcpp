// DatatypesAndAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int x = 0;

struct LinkedList
{
	struct Node
	{
		int value;
		Node* next{};
	};


	Node* list;

	void PrependNode(int val) {
		Node* node = new Node;
		Node* temp = list;
		node->next = temp;
		node->value = val;
		list = node;
	}
	
	void AppendNode(int val) {
		Node* node = list;
		while (node->next != nullptr)
		{
			node = node->next;
		}

		Node* newnode = new Node;
		newnode->value = val;
		node->next = newnode;
	}

	void InsertAt(int pos, int val) {
		Node* node = new Node;
		Node* temp = list;
		for (int i = 2; i < pos; i++) {
			if (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}

		node->next = temp->next;
		node->value = val;
		temp->next = node;
	}

	void Delete(int pos) {
		if (pos == 0) { return; }
		Node* node = list;
		if (pos == 1) {
			node = list->next;
			delete[] list;
			list = node;
			return;
		}

		for (int i = 2; i < pos; i++) {
			if (node->next != nullptr)
			{
				node = node->next;
			}
		}
		Node* temp = node->next;
		node->next = temp->next;
		delete[] temp;
	}

	void PrintList() {
		Node* node = list;
		while (node->next != nullptr)
		{
			std::cout << node->value << "/" << node->next;
			std::cout << ", ";
			node = node->next;
		}
		std::cout << node->value << "/" << node->next << "\n";
	}

	void FreeList() {
		Node* node;
		Node* next = list;
		while (next != nullptr)
		{
			node = next;
			std::cout << node->value << "/" << node->next << ": freed node\n";
			next = node->next;
			delete[] node;
		}
		std::cout << "freed list\n";
	}

	int Count() {
		Node* node = list;
		int count = 1;
		while (node->next != nullptr)
		{
			node = node->next;
			count++;
		}
		return count;
	}
	
	int IndexOf(int val) {
		Node* node = list;
		int index = 1;
		while (node != nullptr)
		{
			if (val == node->value) {
				return index;
			}
			node = node->next;
			index++;
		}
		return 0;
	}
};

struct BinarySearchTree
{
	struct Node
	{
		int value;
		Node* left{};
		Node* right{};
	};


	Node* tree;

	void Insert(int val) {
		Node* node = new Node;
		node->value = val;
		if (tree == nullptr) {
			tree = node;
			return;
		}

		Node* next = tree;
		Node* temp = tree;
		while (next != nullptr) {
			if (val < next->value) {
				temp = next;
				next = next->left;
			} else {
				temp = next;
				next = next->right;
			}
		}

		if (val < temp->value) {
			temp->left = node;
		} else if (val > temp->value) {
			temp->right = node;
		}
	}

	void Free() {
		Node* next = tree;
		Node* temp = tree;
		while (next->left != nullptr || next->right != nullptr) {
			temp = next;
			if (next->left != nullptr) {
				next = next->left;
			} else{ 
				next = next->right;
			}
		}

		if (next->value < temp->value) {
			std::cout << "freed node with value: " << temp->left->value << "\n";
			delete[] temp->left;
			temp->left = nullptr;
			Free();
		} else if (next->value > temp->value) {
			std::cout << "freed node with value: " << temp->right->value << "\n";
			delete[] temp->right;
			temp->right = nullptr;
			Free();
		} else if (tree->left == nullptr && tree->right == nullptr){
			std::cout << "freed root node with value: " << tree->value << "\n";
			delete[] tree;
			tree = nullptr;
		}
	}

	int Size() {
		x = 0;
		inOrder(tree);
		return x;
	}

	void inOrder(Node* node) {
		if (node != nullptr) {
			inOrder(node->left);
			x++;
			//std::cout << node->value << "/" << ++x << "\n";
			inOrder(node->right);
		}
	}
};

int main()
{
	//make size, width and length methods to make printing possible
	//(arr of str, str[width], str[how far right] = distance from length 0 * "whitespace" + value)
	//make some sort of print method to make sure elements are inserted in the right order
	std::cout << "Hello World!\n";
	BinarySearchTree BST{};
	BST.Insert(4);
	BST.Insert(1);
	BST.Insert(2);
	BST.Insert(3);
	BST.Insert(5);
	BST.Insert(10);
	BST.Insert(6);
	BST.Insert(7);
	BST.Insert(8);
	BST.Insert(9);
	BST.Insert(11);
	std::cout << "Size = " << BST.Size() << "\n";
	BST.Free();

	/*LinkedList list1{};
	list1.PrependNode(2);
	list1.PrependNode(1);
	list1.PrintList();
	std::cout << "Count = " << list1.Count() << "\n";
	list1.AppendNode(4);
	std::cout << "Count = " << list1.Count() << "\n";
	list1.PrintList();
	std::cout << "Index of 2 = " << list1.IndexOf(2) << "\n";
	std::cout << "Index of 3 = " << list1.IndexOf(3) << "\n";
	list1.InsertAt(3, 3);
	list1.PrintList();
	list1.Delete(list1.IndexOf(1));
	list1.PrintList();
	list1.FreeList();*/
}