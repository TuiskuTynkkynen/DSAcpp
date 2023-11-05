#include "cache.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>
	
	struct cache::LRUCache::Node
	{
		std::string value{};
		std::shared_ptr<Node> next{};
		std::shared_ptr<Node> previous{};
	};
	
	cache::LRUCache::LRUCache(unsigned int size)
		: size(size)
	{
		lookup.reserve(size);
		reverseLookup.reserve(size);
		head = tail = nullptr;
		length = 0;
	}

	cache::LRUCache::~LRUCache() {
		while (head != nullptr) {
			Evict();
		}
	}

	void cache::LRUCache::SetMostReacent(std::shared_ptr<cache::LRUCache::Node> node) {
		if (head == nullptr || node == head) {
			return;
		} else {
			node->previous->next = node->next;
		}
		
		if (node == tail) {
			tail = node->previous;
		} else {
			node->next->previous = node->previous;
		}

		node->next = head;
		head->previous = node;
		head = node;

		node->previous = nullptr;
	}
	
	void cache::LRUCache::Evict(){
		int key = reverseLookup[tail];
		lookup.erase(key);
		reverseLookup.erase(tail);
		if (head != tail) {
			std::shared_ptr<Node> node = tail;
			tail = tail->previous;
			node->previous->next = nullptr;
			node->next = node->previous = nullptr;
		} else {
			tail->next = tail->previous = nullptr;
			head = tail = nullptr;
		}
		length--;
	}

	std::shared_ptr<cache::LRUCache::Node> cache::LRUCache::Get(int key) {
		std::_List_iterator iter = lookup.find(key);
		
		if (iter == lookup.end()) {
			return nullptr;
		}

		SetMostReacent(iter->second);
		return iter->second;
	}

	void cache::LRUCache::Clear() {
		while (head != nullptr) {
			Evict();
		}
		lookup.clear();
		reverseLookup.clear();
		length = 0;
	}

	int cache::LRUCache::GetKey(const std::string& val) {
		std::hash<std::string> hasher;
		return hasher(val);
	}
	
	const std::string& cache::LRUCache::GetValue(int key) {
		std::shared_ptr<Node> node = Get(key);
		if (node != nullptr) {
			return node->value;
		}
		return "";
	}

	int cache::LRUCache::Update(int key, const std::string& val) {
		std::shared_ptr<Node> node = Get(key);
		std::hash<std::string> hasher;
		int newKey = hasher(val);

		if (node != nullptr) {
			node->value = val;
			lookup.erase(key);
			reverseLookup.erase(node);
		} else {
			if (++length > size) {
				Evict();
			}

			node = std::make_shared<Node>();
			node->value = val;
			node->next = head;
			node->previous = nullptr;

			if (head == nullptr) {
				head = tail = node;
			}
			else {
				head->previous = node;
				head = node;
			}
		}
		
		lookup.emplace(newKey, node);
		reverseLookup.emplace(node, newKey);
		return newKey;
	}
	
	void cache::LRUCache::Print() {
		std::shared_ptr<Node> node = head;
		std::cout << "LRU = ";
		while (node->next != nullptr) {
			std::cout << node->value << " <-> ";
			node = node->next;
		}
		std::cout << node->value << "\n";
	}