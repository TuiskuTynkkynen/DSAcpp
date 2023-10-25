#ifndef stack
#define stack

class Stack
{ 
	private:
		struct Node;
		Node* head = nullptr;
	public:
		int length = 0;
		~Stack();
		void Push(int val);
		int Pop();
		int Peek();
};

#endif