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
				matrix[i * j] = tempMatrix[i][j];
			}
		}

	}

	graphs::AdjacencyMatrix::~AdjacencyMatrix() {
		delete[] matrix;
	}

	int graphs::AdjacencyMatrix::BreadthFirstSearch(int val) {
		std::vector<bool> seen;
		seen.assign(size, false);
		seen[0] = true;

		std::vector<int> previous;
		previous.assign(size, -1);

		std::queue<int> q;
		q.push(0);
		
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

		if (previous[val] == -1) {
			std::cout << "Did not find value = " << val << "\n";
		}	else {
			std::cout << "Path = ";
			for (int i : previous) {
				std::cout << i << "->";
			}
			std::cout << "\n";
		}
	}