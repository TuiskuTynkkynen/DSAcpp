#ifndef binarysearchtree
#define binarysearchtree
#include <string>

class BinarySearchTree {
	public :
		void Insert(int val);
		void Delete(int val);
		void Free();
		bool Search(int val);
		int Min();
		int Max();
		int Size();
		void Print();

	private :
		struct Node;
		Node* tree = nullptr;
		int size = 0;
		std::string* strs;
		int width;

		void inOrder(Node* node, int tempwidth);
		void PrintTraverse(Node* node, int depth);
		Node* MinChild(Node* node);
		Node* MaxChild(Node* node);
		Node* Parent(Node* node);
		Node* Predecessor(Node* node);
		Node* Successor(Node* node);


};
#endif