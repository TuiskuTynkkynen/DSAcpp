#include "stack.h"
#include <iostream>

	struct Stack::Node {
		int value;
		Node* next;

		Node(int val) {
			value = val;
			next = nullptr;
		}
	};

	Stack::~Stack() {
		std::cout << "Destructor removed: ";
		while (head != nullptr) {
			std::cout << this->Pop() << ", ";
		}
	}

	void Stack::Push(int val) {
		Node* node = new Node(val);
		node->next = head;
		head = node;
		length++;
	}

	int Stack::Pop() {
		if (head == nullptr) {
			return -1;
		}

		int value = head->value;
		Node* next = head->next;
		delete[] head;
		head = next;

		length--;
		return value;
	}

	int Stack::Peek() {
		if (head == nullptr) {
			return -1;
		}
		
		return head->value;
	}