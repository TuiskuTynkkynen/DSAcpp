#ifndef queue
#define queue

class Queue
{
	private:
		struct Node {
			int value;
			Node* next;

			Node(int val) {
				value = val;
				next = nullptr;
			}
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		~Queue();
		void Enqueue(int val);
		int Dequeue();
};

#endif