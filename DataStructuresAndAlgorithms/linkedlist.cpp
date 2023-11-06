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

	//DOUBLY LINKED LIST

	struct DoublyLinkedList::Node
	{
		int value{};
		std::shared_ptr<Node> next{};
		std::shared_ptr<Node> previous{};
	};

	DoublyLinkedList::~DoublyLinkedList() {
		if (head != nullptr) {
			FreeList();
		}
	}

	void DoublyLinkedList::FreeList() {
		{
			std::shared_ptr<Node> node;
			std::shared_ptr<Node> next = head;

			std::cout << "Freed nodes with values: ";
			while (next != nullptr)
			{
				node = next;
				std::cout << node->value << ", ";
				next = node->next;
				node->next = nullptr;
				node->previous = nullptr;
			}
			head = nullptr;
			tail = nullptr;
		}

		std::cout << "\nList has been freed\n";
	}

	void DoublyLinkedList::PrependNode(int val) {
		auto node = std::make_shared<Node>();
		node->value = val;
		node->next = head;
		
		if (head == nullptr) {
			head = tail = node;
			return;
		}

		head->previous = node;
		head = node;
	}

	void DoublyLinkedList::AppendNode(int val) {
		auto node = std::make_shared<Node>();
		node->value = val;
		node->next = nullptr;
		node->previous = tail;

		if (head == nullptr) {
			head = tail = node;
			return;
		}

		tail->next = node;
		tail = node;
	}

	void DoublyLinkedList::InsertAt(int index, int val) {
		if (index == 0) {
			PrependNode(val);
			return;
		}

		std::shared_ptr<Node> prev = GetNode(index - 1);
		
		if (prev == nullptr) {
			return;
		}

		auto node = std::make_shared<Node>();
		node->value = val;
		node->next = prev->next;
		
		if (prev->next != nullptr) {
			node->next->previous = node;
		}

		node->previous = prev;
		prev->next = node;
	}

	void DoublyLinkedList::DeleteAt(int index) {
		if (index == 0) {
			std::shared_ptr<Node> node = head;
			node = head->next;
			node->previous = nullptr;
			head = nullptr;
			head = node;
			return;
		}

		std::shared_ptr<Node> prev = GetNode(index - 1);
		
		if (prev == nullptr) {
			return;
		}

		std::shared_ptr<Node> deletedNode = prev->next;

		if (deletedNode != nullptr) {
			if (deletedNode->next != nullptr){
				deletedNode->next->previous = prev;
			}

			prev->next = deletedNode->next;

			if (deletedNode == tail) {
				if (tail->previous != nullptr) {
					tail->previous->next = nullptr;
				}
				tail = tail->previous;
			}
		} 
	}

	void DoublyLinkedList::DeleteValue(int val) {
		DeleteAt(this->IndexOf(val));
	}

	void DoublyLinkedList::PrintList() {
		if (head == nullptr) {
			std::cout << "List is empty";
			return;
		}

		std::shared_ptr<Node> node = head;
		std::cout << "List = ";
		while (node->next != nullptr)
		{
			std::cout << node->value << ", ";
			node = node->next;
		}
		std::cout << node->value << "\n";
	}

	int DoublyLinkedList::Count() {
		if (head == nullptr) {
			return 0;
		}

		std::shared_ptr<Node> node = head;

		int count = 1;
		while (node->next != nullptr)
		{
			node = node->next;
			count++;
		}
		return count;
	}

	int DoublyLinkedList::IndexOf(int val) {
		std::shared_ptr<Node> node = head;
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

	int DoublyLinkedList::Get(int index) {
		std::shared_ptr<Node> node = GetNode(index);
		
		if (node == nullptr) {
			return -1;
		}

		return node->value;
	}

	std::shared_ptr<DoublyLinkedList::Node> DoublyLinkedList::GetNode(int index) {
		if (head == nullptr || index < 0) {
			return nullptr;
		}
		
		std::shared_ptr<Node> node = head;
		for (int i = 0; i < index; i++) {
			if (node->next != nullptr) {
				node = node->next;
			} else {
				return nullptr;
			}
		}

		return node;
	}