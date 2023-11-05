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
		std::string Get(int index);
		int Get(const std::string& value);
		int Update(const std::string& value);
		void Print();
	private:
		const int size;

		struct Node;
		std::shared_ptr<Node> head = nullptr;
		std::shared_ptr<Node> tail = nullptr;
		
		std::unordered_map<int, Node> map;

		void SetMostReacent(std::shared_ptr<Node> node);
		void Evict();
	};
}

