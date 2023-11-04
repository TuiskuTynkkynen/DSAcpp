#pragma once

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

	};

}
