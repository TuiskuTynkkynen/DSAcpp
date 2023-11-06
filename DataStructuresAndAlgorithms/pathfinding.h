#ifndef pathfinding
#define pathfinding
#include <string>
#include <vector>

class Maze
{
	protected:
		struct Coordinate {
			int y;
			int x;
		};
		const Coordinate directions[4] = {
			{0, 1},
			{0, -1},
			{1, 0},
			{-1, 0}
		};

		int length;
		int width;
		Coordinate startPos;
		Coordinate endPos;
		char wallChar;

		std::string* mazeArray;
		bool** seen;
		std::vector<Coordinate> path;

		bool  SolveRecursive(int posX, int posY);
		virtual void foo() = 0;
	public:
		~Maze();
		void Solve();
};

class SimpleMaze : public Maze{
	private:
		void foo(){}
	public:
		SimpleMaze();
};

class ComplexMaze : public Maze{
	private:
		void foo() {}
	public:
		ComplexMaze();
};

class VeryComplexMaze : public Maze{
	private:
		void foo() {}
	public:
		VeryComplexMaze();
};

#endif