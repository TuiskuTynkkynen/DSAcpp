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
		length = head = tail = 0;
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
		tail = length;

		newArray = new int[capacity]();
		for (int i = 0; i < length; i++) {
			unsigned int oldIndex = (oldHead + i) % oldCapacity;
			newArray[i] = array[oldIndex];
		}
		delete[] array;
		array = newArray;
	}

	int  ArrayBuffer::GetLength() {
		return length;
	}