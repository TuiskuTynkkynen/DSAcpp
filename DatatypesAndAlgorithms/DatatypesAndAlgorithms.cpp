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

	LinkedList(int val) {
		Node* node = new Node;
		node->value = val;
		std::cout << node->value << "/" << node->next << "\n";
		list = node;
	}

	void AddNode(int val) {
		Node* node = list;
		while (node->next != nullptr)
		{
			std::cout << node->next << "\n";
			node = node->next;
		}

		Node* newnode = new Node;
		newnode->value = val;
		node->next = newnode;
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
};

int main()
{
	std::cout << "Hello World!\n";
	LinkedList list1(1);
	//std::cout << list1.list->value << "/" << list1.list->next << "\n";
	list1.PrintList();
	list1.AddNode(2);
	list1.PrintList();
	list1.PrintList();
	list1.FreeList();
}