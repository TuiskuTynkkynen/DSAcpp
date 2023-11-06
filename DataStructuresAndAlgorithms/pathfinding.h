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

			bool operator==(const Coordinate& other) {
				return (y == other.y) && (x == other.x);
			}

			bool operator!=(const Coordinate& other) {
				return !operator==(other);
			}
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

		bool  SolveRecursiveDFS(int posX, int posY);
		size_t getIndex(int y, int x) const { return y * width + x; }
		virtual void foo() = 0;
	public:
		~Maze();
		void SolveDFS();
		void DjikstrasAlgorithm();
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

class ExtremelyComplexMaze : public Maze{
	private:
		void foo() {}
	public:
		ExtremelyComplexMaze();
};

#endif