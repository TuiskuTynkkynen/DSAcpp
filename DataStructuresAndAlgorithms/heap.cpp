#include "heap.h"
#include <vector>
#include <iostream>

	heap::MinHeap::MinHeap(int size) {
		heap = std::vector<int>();
		heap.reserve(size);
		std::cout << heap.size() << "/" << heap.capacity() << "\n";
	}

	heap::MinHeap::~MinHeap() {
	}

	heap::MinHeap heap::MinHeap::operator[](int index){
		return heap[index];
	}

	void heap::MinHeap::Insert(int val) {
		heap.push_back(val);
		HeapifyUp();
	}
	
	int heap::MinHeap::Delete() {
		if (heap.size() == 0)
			return -1;

		int value = heap[0];

		heap[0] = heap.back();
		heap.pop_back();
		HeapifyDown();

		return value;
	}

	int heap::MinHeap::GetLength() {
		return heap.size();
	}

	void heap::MinHeap::Print() {
		int length = heap.size();
		std::cout << "Heap = ";
		for (int i = 0; i < length; i++) {
			std::cout << heap[i] << ", ";
		}
		std::cout << "\n";
	}

	void heap::MinHeap::HeapifyUp() {
		int index = heap.size() - 1;
		int parentIndex;

		while (index > 0){
			parentIndex = Parent(index);

			if (heap[index] < heap[parentIndex]) {
				int temp = heap[index];
				heap[index] = heap[parentIndex];
				heap[parentIndex] = temp;
			} else { break; }

			index = parentIndex;
		}
	}

	void heap::MinHeap::HeapifyDown() {
		int index = 0;
		int length = heap.size();
		int leftChildIndex;
		int rightChildIndex;
		int smallestIndex;

		while (index < length) {
			leftChildIndex = LeftChild(index);
			rightChildIndex = RightChild(index);
			smallestIndex = index;
			
			if (leftChildIndex < length && heap[leftChildIndex] < heap[smallestIndex]) {
				smallestIndex = leftChildIndex;
			}
			
			if (rightChildIndex < length && heap[rightChildIndex] < heap[smallestIndex]) {
				smallestIndex = rightChildIndex;
			}

			if (smallestIndex != index) {
				int temp = heap[smallestIndex];
				heap[smallestIndex] = heap[index];
				heap[index] = temp;

				index = smallestIndex;
			} else { break; }
		}
	}

	int heap::MinHeap::Parent(int index) {
		return (index - 1) / 2;
	}
	
	int heap::MinHeap::LeftChild(int index) {
		return index * 2 + 1;
	}
	
	int heap::MinHeap::RightChild(int index) {
		return index * 2 + 2;
	}
