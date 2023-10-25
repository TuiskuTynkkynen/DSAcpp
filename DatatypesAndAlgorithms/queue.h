#ifndef queue
#define queue

template<typename T> class Queue
{
	private:
		struct Node {
			T value;
			Node* next;

			Node(T val) {
				value = val;
				next = nullptr;
			}
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		~Queue();
};

#endif