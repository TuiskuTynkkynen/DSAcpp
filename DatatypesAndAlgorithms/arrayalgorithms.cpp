#include "arrayalgorithms.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

	
	Array::Array(int size) 
		: length(size)
	{
		array = new int[size]();
	}

	Array::~Array() {
		delete[] array;
	}

	int Array::get(int index) {
		return array[index];
	}
	
	void Array::set(int index, int value) {
		array[index] = value;
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

	Array::ArrayRefrence Array::operator[](int index) {
		return ArrayRefrence{this, index};
	}

	Array::ArrayRefrence& Array::ArrayRefrence::operator=(int val) {
		target_->set(index_, val);
		return *this;
	}
	
	Array::ArrayRefrence::operator int(){
		return target_->get(index_);
	}


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
		
		for (int i = index; i < length; i++) {
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

	ArrayList::ArrayRefrence ArrayList::operator[](int index) {
		return ArrayRefrence{ this, index };
	}

	ArrayList::ArrayRefrence& ArrayList::ArrayRefrence::operator=(int val) {
		target_->set(index_, val);
		return *this;
	}

	ArrayList::ArrayRefrence::operator int() {
		return target_->get(index_);
	}