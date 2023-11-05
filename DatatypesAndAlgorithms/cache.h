#pragma once
#include <memory>
#include <string>
#include <unordered_map>

namespace cache
{
	class LRUCache {
	public:
		LRUCache(unsigned int size);
		~LRUCache();
		void Clear();
		int GetKey(const std::string& value);
		const std::string& GetValue(int key);
		int Update(int key, const std::string& value);
		void Print();
	private:
		const int size;
		int length;

		struct Node;
		std::shared_ptr<Node> head = nullptr;
		std::shared_ptr<Node> tail = nullptr;
		
		std::unordered_map<int, std::shared_ptr<Node>> lookup;
		std::unordered_map<std::shared_ptr<Node>, int> reverseLookup;

		void Evict();
		std::shared_ptr<Node> Get(int key);
		void SetMostReacent(std::shared_ptr<Node> node);
	};
}

