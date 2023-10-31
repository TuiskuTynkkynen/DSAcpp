#include <iostream>
#include "linkedlist.h"
#include <memory>

	//SINGLY LINKED LIST

	struct SinglyLinkedList::Node
	{
		int value{};
		Node* next{};
	};

	SinglyLinkedList::~SinglyLinkedList() {
		if (head != nullptr) {
			FreeList();
		}
	}

	void SinglyLinkedList::PrependNode(int val) {
		Node* node = new Node;
		node->next = head;
		node->value = val;
		head = node;
	}

	void SinglyLinkedList::AppendNode(int val) {
		Node* node = head;
		Node* newnode = new Node;
		newnode->value = val;
		
		if (head == nullptr) {
			head = newnode;
			return;
		}

		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = newnode;
	}

	void SinglyLinkedList::InsertAt(int pos, int val) {
		if (head == nullptr || pos < 0) {
			return;
		}
		
		Node* node = new Node;
		Node* temp = head;
		for (int i = 1; i < pos; i++) {
			if (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}

		node->next = temp->next;
		node->value = val;
		temp->next = node;
	}

	void SinglyLinkedList::DeleteAt(int pos) {
		if (head == nullptr || pos < 0) {
			return;
		}

		Node* node = head;
		if (pos == 0) {
			node = head->next;
			delete[] head;
			head = node;
			return;
		}

		for (int i = 1; i < pos; i++) {
			if (node->next != nullptr)
			{
				node = node->next;
			}
		}

		Node* temp = node->next;
		
		if (temp != nullptr) {
			node->next = temp->next;
			delete[] temp;
		}
	}

	void SinglyLinkedList::PrintList() {
		if (head == nullptr) {
			std::cout << "List is empty";
			return;
		}

		Node* node = head;
		std::cout << "List = ";
		while (node->next != nullptr)
		{
			std::cout << node->value << ", ";
			node = node->next;
		}
		std::cout << node->value << "\n";
	}

	void SinglyLinkedList::FreeList() {
		Node* node;
		Node* next = head;

		std::cout << "Freed nodes with values: ";
		while (next != nullptr)
		{
			node = next;
			std::cout << node->value << ", ";
			next = node->next;
			delete[] node;
		}
		head = nullptr;
		std::cout << "\nList has been freed\n";
	}

	int SinglyLinkedList::Count() {
		if (head == nullptr) {
			return 0;
		}

		Node* node = head;

		int count = 1;
		while (node->next != nullptr)
		{
			node = node->next;
			count++;
		}
		return count;
	}

	int SinglyLinkedList::IndexOf(int val) {
		Node* node = head;
		int index = 0;
		while (node != nullptr)
		{
			if (val == node->value) {
				return index;
			}
			node = node->next;
			index++;
		}
		return -1;
	}