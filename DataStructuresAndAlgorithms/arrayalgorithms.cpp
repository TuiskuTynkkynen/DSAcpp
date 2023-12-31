#include "arrayalgorithms.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

	//BASE ARRAY	
	
	CustomArray::CustomArray()
	{
		array = nullptr;
	}
	
	int CustomArray::get(unsigned int index) {
		return array[index];
	}
	
	bool CustomArray::set(unsigned index, int value) {
	 	array[index] = value;
		return true;
	}

	CustomArray::ArrayRefrence CustomArray::operator[](int index) {
		return ArrayRefrence{ this, index };
	}

	CustomArray::ArrayRefrence& CustomArray::ArrayRefrence::operator=(int val) {
		target_->set(index_, val);
		return *this;
	}

	CustomArray::ArrayRefrence::operator int() {
		return target_->get(index_);
	}

	//ARRAY

	Array::Array(int size)
		: length(size)
	{
		array = new int[size]();
	}

	Array::~Array() {
		delete[] array;
	}

	int  Array::GetLength() {
		return length;
	}

	void Array::InitializeRadomValues() {
		std::vector<int> tempvec;

		for (int i = 0; i < length; i++) {
			tempvec.push_back(i);
		}

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(tempvec.begin(), tempvec.end(), std::default_random_engine(seed));

		for (int i = 0; i < length; i++) {
			array[i] = tempvec[i];
		}
	}

	void Array::PrintArray() {
		std::cout << "Array = ";
		for (int i = 0; i < length; i++) {
			std::cout << array[i] << ", ";
		}
		std::cout << "\n";
	}

	int Array::LinearSearch(int val) {
		for (int i = 0; i < length; i++) {
			if (array[i] == val) {
				return i;
			}
		}
		return -1;
	}

	int Array::BinarySearch(int val) {
		int lowerBound = 0;
		int upperBound = length;
		int middle;

		while (lowerBound < upperBound)
		{
			middle = lowerBound + (upperBound - lowerBound) / 2;
			if (array[middle] < val) {
				lowerBound = middle + 1;
			}
			else if (array[middle] > val) {
				upperBound = middle;
			}
			else {
				return middle;
			}
		}
		return -1;
	}

	void Array::BubbleSort() {
		int upperBound = length - 1;
		while (upperBound > 0) {
			for (int i = 0; i < upperBound; i++) {
				if (array[i] > array[i + 1]) {
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
			upperBound--;
		}
	}

	void Array::QuickSort() {
		int start = 0;
		int half = length / 2;
		int end = length - 1;
		DoQuickSort(start, end);
	}
	
	void Array::DoQuickSort(int lowerBound, int upperBound) {
		if (lowerBound >= upperBound){
			return;
		}

		int pivotIndex = QuickSortPartition(lowerBound, upperBound);
		DoQuickSort(lowerBound, pivotIndex - 1);
		DoQuickSort(pivotIndex + 1, upperBound);
	}
	
	int Array::QuickSortPartition(int lowerBound, int upperBound) {
		int pivotValue = array[upperBound];
		int index = lowerBound - 1;

		for (int i = lowerBound; i < upperBound; i++) {
			if (array[i] <= pivotValue) {
				index++;
				int temp = array[i];
				array[i] = array[index];
				array[index] = temp;
			} 
		}

		index++;
		array[upperBound] = array[index];
		array[index] = pivotValue;

		return index;
	}

	//ARRAYLIST

	ArrayList::ArrayList(int size)
	{
		length = 0;
		capacity = size;
		array = new int[size]();
	}

	ArrayList::~ArrayList() {
		delete[] array;
	}
	
	int ArrayList::get(unsigned int index) {
		if (index >= length) {
			return -1;
		}
		return array[index];
	}

	bool ArrayList::set(unsigned int index, int value) {
		if (index >= length) {
			return false;
		}
		array[index] = value;
		return true;
	}

	void ArrayList::Grow() {
		int* newArray;
		capacity *= 2;
		newArray = new int[capacity]();
		for (int i = 0; i < length; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}

	int  ArrayList::GetLength() {
		return length;
	}

	void ArrayList::PrintArrayList() {
		if (length == 0) {
			std::cout << "Arraylist is empty\n";
			return;
		}
		
		std::cout << "Arraylist = ";
		for (int i = 0; i < length; i++) {
			std::cout << array[i] << ", ";
		}
		std::cout << "\n";
	}

	void ArrayList::Push(int val) {
		if (length == capacity) {
			this->Grow();
		} 
		array[length] = val;
		length++;
	}
	
	int ArrayList::Pop() {
		if (length == 0) {
			return -1;
		}
		return array[length--];
	}

	void ArrayList::Enqueue(int val) {
		if (length == capacity) {
			this->Grow();
		}

		for(int i = 0; i < length; i++) {
			array[length - i] = array[length - i - 1];
		}

		array[0] = val;
		length++;
	}

	int ArrayList::Deque() {
		if (length == 0) {
			return -1;
		}
		
		for (int i = 0; i < length; i++) {
			array[i] = array[i + 1];
		}

		return array[length--];
	}

	bool ArrayList::Insert(unsigned int index, int val) {
		if (index > length) {
			return false;
		}
		
		if (length == capacity) {
			this->Grow();
		}

		length++;

		for (int i = index; i < length - 1; i++) {
			array[length - i] = array[length - i - 1];
		}

		array[index] = val;
		return true;
	}

	bool ArrayList::Delete(unsigned int index) {
		if (index >= length) {
			return false;
		}

		for (int i = index; i < length; i++) {
			array[i] = array[i + 1];
		}

		length--;
		return true;
	}

	//ARRAY BUFFER

	ArrayBuffer::ArrayBuffer(int size)
	{
		length = head = 0;
		tail = -1;
		capacity = size;
		array = new int[size]();
	}

	ArrayBuffer::~ArrayBuffer() {
		delete[] array;
	}

	int ArrayBuffer::get(unsigned int index) {
		if (index >= length) {
			return -1;
		}

		//get index relative to first element of array
		index = (head + index) % capacity;
		
		return array[index];
	}

	bool ArrayBuffer::set(unsigned int index, int value) {
		if (index >= length) {
			return false;
		}

		//get index relative to first element of array
		index = (head + index) % capacity;
		
		array[index] = value;
		return true;
	}

	void ArrayBuffer::Grow() {
		int* newArray;
		unsigned int oldHead = head;
		unsigned int oldCapacity = capacity;

		capacity *= 2;
		head = 0;
		tail = length - 1;

		newArray = new int[capacity]();
		for (int i = 0; i < length; i++) {
			unsigned int oldIndex = (oldHead + i) % oldCapacity;
			newArray[i] = array[oldIndex];
		}
		delete[] array;
		array = newArray;
	}

	void ArrayBuffer::PrintArrayBuffer() {
		if (length == 0) {
			std::cout << "Array buffer is empty\n";
			return;
		}

		std::cout << "Array buffer = ";
		for (int i = 0; i < length; i++) {
			unsigned int index = (head + i) % capacity;
			std::cout << array[index] << ", ";
		}
		std::cout << "\n";
	}

	int  ArrayBuffer::GetLength() {
		return length;
	}

	void ArrayBuffer::Push(int val) {
		if (length == capacity) {
			this->Grow();
		}

		tail = (++tail) % capacity;
		array[tail] = val;
		length++;
	}

	int ArrayBuffer::Pop() {
		if (length == 0) {
			return -1;
		}

		int value = array[tail];
		length--;
		
		if (tail == 0) {
			tail = capacity;
		} else {
			tail--;
		}

		return value;
	}

	void ArrayBuffer::Enqueue(int val) {
		if (length == capacity) {
			this->Grow();
		}

		if (head == 0) {
			head = capacity - 1;
		} else {
			head--;
		}
		
		array[head] = val;
		length++;
	}

	int ArrayBuffer::Deque() {
		if (length == 0) {
			return -1;
		}

		int value = array[head];

		head = (++head) % capacity;
		length--;

		return value;
	}

	bool ArrayBuffer::Insert(unsigned int index, int val) {
		if (index > length) {
			return false;
		}

		if (length == capacity) {
			this->Grow();
		}

		tail = (++tail) % capacity;
		length++;

		for (int i = index; i < length - 1; i++) {
			int newIndex = tail - i;
			if (newIndex < 0) { newIndex = capacity + newIndex; }

			int oldIndex = tail - i - 1;
			if (oldIndex < 0) { oldIndex = capacity + oldIndex; }
			
			array[newIndex] = array[oldIndex];
		}

		//get index relative to first element of array
		index = (head + index) % capacity;

		array[index] = val;
		return true;
	}

	bool ArrayBuffer::Delete(unsigned int index) {
		if (index >= length) {
			return false;
		}

		for (int i = index; i < length; i++) {
			unsigned int newIndex = (head + i) % capacity;
			unsigned int oldIndex = (head + i + 1) % capacity;

			array[newIndex] = array[oldIndex];
		}

		if (tail == 0) {
			tail = capacity;
		} else {
			tail--;
		}
		length--;
		return true;
	}
