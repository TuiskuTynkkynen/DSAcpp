#pragma once
#include <vector>

namespace graphs {

	class AdjacencyMatrix
	{
	public:
		AdjacencyMatrix();
		~AdjacencyMatrix();
		void BreadthFirstSearch(int val);
	private:
		int* matrix;
		const int size;
		size_t getIndex(int x, int y) const { return x * size + y; }
	};
	
	class AdjacencyList
	{
	public:
		AdjacencyList();
		~AdjacencyList();
		void DepthFirstSearch(int val);
	private:
		struct edge{
			int destination;
			int weigth;
		};
		std::vector<std::vector<edge>> matrix;
		const int size;
		bool DepthFirstSearchRecurse(int current, int val, std::vector<bool> &seen, std::vector<int> &path);
	};

}
