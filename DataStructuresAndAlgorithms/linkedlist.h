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

class DoublyLinkedList {
public:
	~DoublyLinkedList();
	void PrependNode(int val);
	void AppendNode(int val);
	void InsertAt(int index, int val);
	void DeleteAt(int index);
	void DeleteValue(int val);
	void FreeList();
	void PrintList();
	int Count();
	int IndexOf(int val);
	int Get(int index);
private:
	struct Node;
	std::shared_ptr<Node> head = nullptr;
	std::shared_ptr<Node> tail = nullptr;

	std::shared_ptr<Node> GetNode(int index);
};



#endif