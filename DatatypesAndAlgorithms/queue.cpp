#include "queue.h"
#include <iostream>

	struct Queue::Node {
		int value;
		Node* next;

		Node(int val) {
			value = val;
			next = nullptr;
		}
	};

	Queue::~Queue() {
		std::cout << "Destructor deleted: ";
		while (head != nullptr) {
			std::cout << head << " = " << head->value << ", ";
			this->Deque();
		}
		length = 0;
	}

	void Queue::Enqueue(int val) {
		Node* node = new Node(val);
		if (tail == nullptr) {
			tail = head = node;
		} else {
			tail->next = node;
			tail = node;
		}

		length++;
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

		length--;
		
		return value;
	}

	int Queue::Peek() {
		if (head == nullptr) {
			return -1;
		}
		return head->value;
	}