#ifndef linkedlist
#define linkedlist
#include <memory>

class SinglyLinkedList{
public :
	~SinglyLinkedList();
	void PrependNode(int val);
	void AppendNode(int val);
	void InsertAt(int pos, int val);
	void DeleteAt(int pos);
	void PrintList();
	void FreeList();
	int Count();
	int IndexOf(int val);
private:
	struct Node;
	Node* head = nullptr;
};

#endif