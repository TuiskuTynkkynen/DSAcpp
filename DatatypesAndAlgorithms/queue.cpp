#include "queue.h"
#include <iostream>

	 Queue::~Queue() {
		std::cout << "Destructor deleted: ";
		while (head != nullptr) {
			std::cout << head << " = " << head->value << ", ";
			this->Deque();
		}
	}

	void Queue::Enqueue(int val) {
		Node* node = new Node(val);
		if (head == nullptr) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
	}

	int Queue::Deque() {
		if (head == nullptr) {
			return -1;
		}

		Node* node = head;
		Node* next = node->next;
		int value = node->value;

		delete[] head;
		head = next;
		
		if (head == nullptr) {
			tail = nullptr;
		}

		return value;
	}

	int Queue::Peek() {
		if (head == nullptr) {
			return -1;
		}
		return head->value;
	}