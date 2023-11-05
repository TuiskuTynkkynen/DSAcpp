#pragma once
#include <string>
#include <vector>

namespace hashmap {
	class HashMap
	{
	public:
		HashMap(unsigned int size);
		~HashMap();
		void Clear();
		bool Contains(const std::string& value);
		int Insert(const std::string& value);
		void Delete(const std::string& value);
		void Print();
	private:
		int length;
		typedef std::pair<int, std::string> kvPair;
		std::vector<std::vector<kvPair>> map;
		int Hash(const std::string& value);
	};
}