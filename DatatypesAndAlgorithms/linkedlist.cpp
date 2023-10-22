#include <iostream>
#include "linkedlist.h"
	

	struct LinkedList::Node
	{
		int value;
		Node* next{};
	};

	void LinkedList::PrependNode(int val) {
		Node* node = new Node;
		Node* temp = list;
		node->next = temp;
		node->value = val;
		list = node;
	}

	void LinkedList::AppendNode(int val) {
		Node* node = list;
		while (node->next != nullptr)
		{
			node = node->next;
		}

		Node* newnode = new Node;
		newnode->value = val;
		node->next = newnode;
	}

	void LinkedList::InsertAt(int pos, int val) {
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

	void LinkedList::Delete(int pos) {
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
		if (temp != nullptr) {
			node->next = temp->next;
		}
		delete[] temp;
	}

	void LinkedList::PrintList() {
		Node* node = list;
		while (node->next != nullptr)
		{
			std::cout << node->value << "/" << node->next;
			std::cout << ", ";
			node = node->next;
		}
		std::cout << node->value << "/" << node->next << "\n";
	}

	void LinkedList::FreeList() {
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

	int LinkedList::Count() {
		Node* node = list;
		int count = 1;
		while (node->next != nullptr)
		{
			node = node->next;
			count++;
		}
		return count;
	}

	int LinkedList::IndexOf(int val) {
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