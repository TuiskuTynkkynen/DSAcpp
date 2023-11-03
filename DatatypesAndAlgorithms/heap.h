#pragma once
#include <vector>

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
	void HeapifyUp();
	void HeapifyDown();
};

