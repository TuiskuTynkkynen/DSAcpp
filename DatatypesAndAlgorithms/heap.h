#pragma once
#include <vector>

namespace heap {
	class MinHeap
	{
	public:
		MinHeap(int size);
		~MinHeap();
		MinHeap operator[](int index);
		void Insert(int val);
		int Delete();
		int GetLength();
		void Print();
	private:
		std::vector<int> heap;
		int Parent(int index);
		int LeftChild(int index);
		int RightChild(int index);
		void HeapifyUp();
		void HeapifyDown();
	};
}


