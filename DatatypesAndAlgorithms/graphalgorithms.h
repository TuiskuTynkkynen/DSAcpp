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
		void DjikstrasShortestPath(int val);
	private:
		struct edge{
			int destination;
			int weigth;
		};
		std::vector<std::vector<edge>> matrix;
		const int size;
		bool DepthFirstSearchRecurse(int current, int val, std::vector<bool> &seen, std::vector<int> &path);
		bool HasUnvisted(const std::vector<bool>& seen);
		int GetLowestUnvisited(const std::vector<bool>& seen, const std::vector<int>& distance);
	};

}
