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