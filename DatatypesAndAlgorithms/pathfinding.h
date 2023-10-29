#ifndef pathfinding
#define pathfinding
#include <string>
#include <vector>

class Maze
{
	private:
		struct Coordinate {
			int y;
			int x;
		};

		const int length;
		const int width;
		const Coordinate startPos;
		const Coordinate endPos;
		const char wallChar;
		const Coordinate directions[4] = {
			{1, 0},
			{-1, 0},
			{0, 1},
			{0, -1}
		};

		std::string* mazeArray;
		bool** seen;
		std::vector<Coordinate> path;

		bool  SolveRecursive(int posX, int posY);
	public:
		Maze();
		~Maze();
		void Solve();
};

#endif