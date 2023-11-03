#include "heap.h"
#include <vector>
#include <iostream>

	heap::MinHeap::MinHeap(int size) {
		heap = std::vector<int>(size);
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
		heap.erase(heap.begin());
		HeapifyDown();
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

	void heap::MinHeap::HeapifyDown() {
		int index = heap.size();
		int parentIndex;
		while (index >= 0){
			parentIndex = (index - 1) / 2;

			if (heap[index] > heap[parentIndex]) {
				int temp = heap[index];
				heap[index] = heap[parentIndex];
				heap[parentIndex] = temp;
			} else { break; }

			index = parentIndex;
		}
	}

	void heap::MinHeap::HeapifyUp() {
		int index = 0;
		int leftChildIndex;
		int rightChildIndex;
		while (index >= 0){
			leftChildIndex = 2 * index + 1;
			rightChildIndex = 2 * index + 2;

			if (heap[leftChildIndex] > heap[index]) {
				int temp = heap[leftChildIndex];
				heap[leftChildIndex] = heap[index];
				heap[index] = temp;

				index = leftChildIndex;
			} else if (heap[rightChildIndex] > heap[index]) {
				int temp = heap[rightChildIndex];
				heap[rightChildIndex] = heap[index];
				heap[index] = temp;

				index = rightChildIndex;
			} else { break; }
		}
	}