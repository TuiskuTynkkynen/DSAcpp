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
		list = node;
	}

	void AddNode(int val) {
		Node* node = list;
		while (node->next != nullptr)
		{
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

int main()
{
	std::cout << "Hello World!\n";
	LinkedList list1(1);
	std::cout << "Count = " << list1.Count() << "\n";
	list1.PrintList();
	list1.AddNode(2);
	std::cout << "Count = " << list1.Count() << "\n";
	list1.PrintList();
	std::cout << "Index of 2 = " << list1.IndexOf(2) << "\n";
	std::cout << "Index of 3 = " << list1.IndexOf(3) << "\n";
	list1.FreeList();
}