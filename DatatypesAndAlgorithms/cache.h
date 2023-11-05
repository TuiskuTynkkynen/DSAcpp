#pragma once
#include <memory>
#include <string>
#include <unordered_map>

namespace cache
{
	class LRUCache {
	public:
		LRUCache(unsigned int val);
		~LRUCache();
		void Clear();
		void Evict();
		std::string& Find(int index);
		int Find(const std::string& value);
		int Insert(const std::string& value);
		void Print();
	private:
		struct Node;
		std::shared_ptr<Node> head = nullptr;
		std::shared_ptr<Node> tail = nullptr;
		
		std::unordered_map<int, Node> map;

		void SetMostReacent(std::shared_ptr<Node> node);
	};
}

