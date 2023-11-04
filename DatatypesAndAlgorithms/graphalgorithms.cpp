#include "graphalgorithms.h"
#include <queue>
#include <vector>
#include <iostream>

	graphs::AdjacencyMatrix::AdjacencyMatrix()
		: size(5)
	{
		matrix = new int[size*size]();

		int tempMatrix[][5] = {
			{0,1,4,5,0},
			{1,0,0,0,0},
			{0,0,0,2,0},
			{0,0,0,0,5},
			{0,0,0,0,0}
		};

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i * size + j] = tempMatrix[i][j];
			}
		}

	}

	graphs::AdjacencyMatrix::~AdjacencyMatrix() {
		delete[] matrix;
	}

	void graphs::AdjacencyMatrix::BreadthFirstSearch(int val) {
		const int source = 0;

		std::vector<bool> seen;
		seen.assign(size, false);
		seen[source] = true;

		std::vector<int> previous;
		previous.assign(size, -1);

		std::queue<int> q;
		q.push(source);
		
		while (!q.empty()) {
			int current = q.front();

			if (current == val) {
				break;
			}

			for (int i = 0; i < size; i++) {
				if (matrix[getIndex(current, i)] != 0 && seen[i] == false) {
					seen[i] = true;
					previous[i] = current;
					q.push(i);
				}
			}

			q.pop();
		}

		if (seen[val] == false) {
			std::cout << "Did not find value = " << val << "\n";
			return;
		}

		std::vector<int> out;
		int current = val;
			
		while (previous[current] != -1) {
			out.push_back(current);
			current = previous[current];
		}

		out.push_back(source);

		std::cout << "Path";
		for (int i = out.size() - 1; i >= 0; i--) {
			std::cout << " -> " << out[i];
		}
		std::cout << "\n";
		
	}