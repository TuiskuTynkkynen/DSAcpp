// DatatypesAndAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
				if (next->left != nullptr){
					temp = next;
				}
				next = next->left;
			} else {
				if (next->right != nullptr){
					temp = next;
				}
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
		while (next->left != nullptr) {
			temp = next;
			next = next->left;
		}
		while (next->right != nullptr) {
			temp = next;
			next = next->right;
		}

		std::cout << "freed node with value: " << next->value << "\n";
		if (next->value < temp->value) {
			delete[] temp->left;
			temp->left = nullptr;
			Free();
		} else if (next->value > temp->value) {
			delete[] temp->right;
			temp->right = nullptr;
			Free();
		} else if (tree->left == nullptr && tree->right == nullptr){
			delete[] tree;
			tree = nullptr;
		}
	}

};

int main()
{
	std::cout << "Hello World!\n";
	BinarySearchTree BST{};
	BST.Insert(2);
	BST.Insert(3);
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