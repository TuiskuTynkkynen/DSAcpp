#ifndef linkedlist
#define linkedlist

class LinkedList
{
	public :
		struct Node;
		
		void PrependNode(int val);

		void AppendNode(int val);

		void InsertAt(int pos, int val);

		void Delete(int pos);

		void PrintList();

		void FreeList();

		int Count();

		int IndexOf(int val);

	private:
		Node* list = nullptr;

};

#endif