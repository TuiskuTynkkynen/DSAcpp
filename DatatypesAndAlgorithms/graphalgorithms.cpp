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

	graphs::AdjacencyList::AdjacencyList()
		:size(8)
	{
		std::vector<edge> tempVector;

		//Graph[0]
		tempVector.push_back({1,1}); //Edge[0]
		tempVector.push_back({2,4}); //Edge[1]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[1]
		tempVector.push_back({2,7}); //Edge[0]
		tempVector.push_back({3,3}); //Edge[1]
		tempVector.push_back({5,1}); //Edge[1]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[2]
		tempVector.push_back({4,1}); //Edge[0]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[3]
		tempVector.push_back({1,1}); //Edge[0]
		tempVector.push_back({2,2}); //Edge[1]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[4]
		graph.push_back(tempVector);

		//Graph[5]
		tempVector.push_back({6,1}); //Edge[0]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[6]
		tempVector.push_back({4,1}); //Edge[0]
		graph.push_back(tempVector);
		tempVector.clear();

		//Graph[7]
		graph.push_back(tempVector);
	}

	graphs::AdjacencyList::~AdjacencyList(){
		graph.clear();
	}

	void graphs::AdjacencyList::DepthFirstSearch(int val) {
		int source = 0;

		std::vector<bool> seen;
		seen.assign(size, false);

		std::vector<int> path;

		if (!DepthFirstSearchRecurse(source, val, seen, path)) {
			std::cout << "Did not find value = " << val << "\n";
			return;
		}

		std::cout << "Path";
		for (int i = 0; i < path.size(); i++) {
			std::cout << " -> " << path[i];
		}
		std::cout << "\n";
	}

	bool graphs::AdjacencyList::DepthFirstSearchRecurse(int current, int val, std::vector<bool> &seen, std::vector<int>& path) {
		if (seen[current]) {
			return false;
		}

		path.push_back(current);
		seen[current] = true;

		if (current == val) {
			return true;
		}

		int edgeCount = graph[current].size();
		for (int i = 0; i < edgeCount; i++) {
			edge edge = graph[current][i];
			if (DepthFirstSearchRecurse(edge.destination, val, seen, path) == true) {
				return true;
			}
		}

		path.pop_back();
		return false;
	}

	void graphs::AdjacencyList::DjikstrasShortestPath(int val) {
		const int source = 0;

		std::vector<int> previous;
		previous.assign(size, -1);
		
		std::vector<int> distance;
		distance.assign(size, INT32_MAX);
		distance[source] = 0;

		typedef std::pair<int, int> intPair;
		std::priority_queue<intPair, std::vector<intPair>, std::greater<intPair>> q;

		q.emplace(0, source);

		while (!q.empty()) {
			int current = q.top().second;
			q.pop();

			int edgeCount = graph[current].size();
			for (int i = 0; i < edgeCount; i++) {
				edge edge = graph[current][i];

				int tempDistance = distance[current] + edge.weigth;
				if (tempDistance < distance[edge.destination]) {
					distance[edge.destination] = tempDistance;
					q.emplace(tempDistance, edge.destination);
					previous[edge.destination] = current;
				}
			}
		}

		if (val >= size) {
			std::cout << "Node = " << val << " does note exist\n";
			return;
		} else if (previous[val] == -1) {
			std::cout << "Could not reach node = " << val << "\n";
			return;
		}

		std::vector<int> out;
		int current = val;

		while (previous[current] != -1) {
			out.push_back(current);
			current = previous[current];
		}

		out.push_back(source);

		std::cout << "Shortest path";
		for (int i = out.size() - 1; i >= 0; i--) {
			std::cout << " -> " << out[i];
		}
		std::cout << "\nDistnance = " << distance[val] << "\n";
	}