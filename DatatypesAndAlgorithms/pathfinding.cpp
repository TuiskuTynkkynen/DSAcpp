#include "pathfinding.h"
#include <string>
#include <vector>
#include <iostream>

	Maze::Maze() 
		:length(10), width(12), startPos{0,1}, endPos{9,11}, wallChar('#')
	{
		mazeArray = new std::string[length];
		
		mazeArray[0] = "#E#########";
		mazeArray[1] = "# #   #   #";
		mazeArray[2] = "# # # # ###";
		mazeArray[3] = "# # #     #";
		mazeArray[4] = "#   ##### #";
		mazeArray[5] = "# ###     #";
		mazeArray[6] = "# #     # #";
		mazeArray[7] = "### #######";
		mazeArray[8] = "#         S";
		mazeArray[9] = "###########";

		seen = new bool*[length]();
		
		for (int i = 0; i < length; i++) {
			seen[i] = new bool[width];
		}
	}

	Maze::~Maze() {
		delete[] mazeArray;
		
		for (int i = 0; i < length; i++) {
			delete[] seen[i];
		}

		delete[] seen;
	}

	bool Maze::SolveRecursive(int posY, int posX) {
		if (posY < 0 || posY > length - 1 || posX < 0 || posX > width - 1) { //if out of bounds
			return false;
		}  else if (posY == endPos.y && posX == endPos.x) { //if end
			path.push_back({ posY, posX });
			return true;
		} else if (mazeArray[posY][posX] == wallChar) { //if wall
			return false;
		} else if(seen[posY][posX] == true) { //if seen
			return false;
		}

		seen[posY][posX] = true;
		path.push_back({posY, posX});

		int dirCount = sizeof(directions) / sizeof(directions[0]);
		for (int i = 0; i < dirCount; i++) {
			int y = directions[i].y;
			int x = directions[i].x;
			if (SolveRecursive(posY + y, posX + x) == true) {
				return true;
			}
		}

		path.pop_back();
	}

	void Maze::Solve() {
		SolveRecursive(startPos.y, startPos.x);

		std::cout << "Path:\n";


		for (int i = 0; i < path.size(); i++) {
			std::cout << "[" << path[i].x << "," << path[i].y << "], ";
			mazeArray[path[i].y][path[i].x] = 177;
		}

		std::cout << "\nSolved maze:\n";

		for (int i = 0; i < length; i++) {
			std::cout << " " << mazeArray[i] << "\n";
		}

		for (int i = 0; i < path.size(); i++) {
			mazeArray[path[i].y][path[i].x] = ' ';
		}
		mazeArray[startPos.y][startPos.x] = 'S';
		mazeArray[endPos.y][endPos.x] = 'E';

		path.clear();

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				seen[i][j] = false;
			}
		}
	}