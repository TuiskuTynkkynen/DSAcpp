#ifndef queue
#define queue

class Queue
{
	private:
		struct Node;
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		int length = 0; 
		~Queue();
		void Enqueue(int val);
		int Deque();
		int Peek();
};

#endif