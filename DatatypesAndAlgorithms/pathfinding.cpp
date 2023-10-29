#include "pathfinding.h"
#include <string>
#include <vector>
#include <iostream>

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
		if (SolveRecursive(startPos.y, startPos.x) == false) {
			std::cout << "Maze could't be solved;";
		} else {
			for (int i = 0; i < path.size(); i++) {
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
		}
		path.clear();

		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				seen[i][j] = false;
			}
		}
	}

	SimpleMaze::SimpleMaze() {
		length = 7;
		width = 5;
		startPos = {6, 1};
		endPos = {0, 3};
		wallChar = '#';
		
		mazeArray = new std::string[length];

		mazeArray[0] = "###E#";
		mazeArray[1] = "#   #";
		mazeArray[2] = "# ###";
		mazeArray[3] = "#   #";
		mazeArray[4] = "### #";
		mazeArray[5] = "#   #";
		mazeArray[6] = "#S###";


		seen = new bool* [length]();

		for (int i = 0; i < length; i++) {
			seen[i] = new bool[width];
		}
	}

	ComplexMaze::ComplexMaze() {
		length = 10;
		width = 12;
		startPos = { 9,11 };
		endPos = { 0,1 };
		wallChar = '#';

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

		seen = new bool* [length]();

		for (int i = 0; i < length; i++) {
			seen[i] = new bool[width];
		}
	}

	VeryComplexMaze::VeryComplexMaze() {
		length = 21;
		width = 22;
		startPos = {19,21};
		endPos = { 0,1 };
		wallChar = '#';

		mazeArray = new std::string[length];

		mazeArray[0] = "#E###################";
		mazeArray[1] = "# #         # # #   #";
		mazeArray[2] = "# # ####### # # # ###";
		mazeArray[3] = "#       # # #   #   #";
		mazeArray[4] = "# ##### # # # # ### #";
		mazeArray[5] = "# #   #   # # # # # #";
		mazeArray[6] = "# # ####### # ### # #";
		mazeArray[7] = "# #   #     # #   # #";
		mazeArray[8] = "### ##### ### # ### #";
		mazeArray[9] = "#   # #   # # # # # #";
		mazeArray[10] = "### # # ### # # # # #";
		mazeArray[11] = "#       # # #   #   #";
		mazeArray[12] = "### ##### # # # # # #";
		mazeArray[13] = "#             #   # #";
		mazeArray[14] = "############# ### ###";
		mazeArray[15] = "#         #   # #   #";
		mazeArray[16] = "# ####### # ### ### #";
		mazeArray[17] = "#       #       #   #";
		mazeArray[18] = "### ####### # ### ###";
		mazeArray[19] = "#     #     #   #   S";
		mazeArray[20] = "##################### ";

		seen = new bool* [length]();

		for (int i = 0; i < length; i++) {
			seen[i] = new bool[width];
		}
	}