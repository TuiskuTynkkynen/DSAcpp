#include "hashmap.h"
#include <string>
#include <vector>
#include <iostream>

	hashmap::HashMap::HashMap(unsigned int val){
		map.reserve(val);
		length = 0;
	}

	hashmap::HashMap::~HashMap(){
		map.clear();
	}

	int hashmap::HashMap::Hash(const std::string& val) {
		//Very suboptimal hash function
		int key = 0;
		int length = val.length();
		for (int i = 0; i < length; i++) {
			key += pow(val[i], 3);
		}

		key *= length;

		return key;
	}

	void hashmap::HashMap::Resize(){
		std::vector<std::vector<kvPair>> tempMap = map;
		int newCapacity = 2 * map.capacity();

		map.clear();
		map.reserve(newCapacity);

		for (std::vector<kvPair> bucket : tempMap){
			for (kvPair keyValue : bucket) {
				int key = Hash(keyValue.second);
				map[key % newCapacity].push_back({ key, keyValue.second});
			}
		}

		tempMap.clear();
	}

	void hashmap::HashMap::Clear() {
		map.clear();
	}

	bool hashmap::HashMap::Contains(const std::string& val) {
		int key = Hash(val);
		std::vector<kvPair>& bucket = map[key % map.capacity()];
		
		for (kvPair& keyValue : bucket){
			if (keyValue.first == key) {
				return true;
			}
		}

		return false;
	}

	int hashmap::HashMap::Insert(const std::string& val) {
		int capacity = map.capacity();
		if (length / capacity >= 0.7) {
			Resize();
		}
		
		int key = Hash(val);
		map[key % capacity].push_back({key, val});
		return key;
	}

	void hashmap::HashMap::Delete(const std::string& val) {
		int key = Hash(val);
		std::vector<kvPair>& bucket = map[key % map.capacity()];
		
		int size = bucket.size();
		for (int i = 0; i < size; i++) {
			if (bucket[i].first == key) {
				bucket.erase(bucket.begin() + i);
				length--;
			}
		}
	}

	void hashmap::HashMap::Print(){
		if (length == 0) {
			std::cout << "Hash map is empty\n";
		}
		int size = map.size();
		std::cout << "Hash map:";
		for (int i = 0; i < size; i++) {
			std::vector<kvPair>& bucket = map[i];
			std::cout << "\nBucket " << i << " = ";
			for (kvPair& keyValue : bucket) {
				std::cout << keyValue.second << ", ";
			}
		}
		std::cout << "\n";
	}