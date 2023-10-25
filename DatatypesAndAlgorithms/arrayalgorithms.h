#ifndef arrayalgorithms
#define arrayalgorithms

class Array
{ 
	protected:
		int* array;
		int get(int index);
		void set(int index, int value);
		struct ArrayRefrence {
			Array* target_;
			int index_;

			ArrayRefrence& operator=(int val);
			operator int();
		};
	public:
		const int length;
		Array(int size);
		~Array();
		ArrayRefrence operator[](int index);
		void InitializeRadomValues();
		void PrintArray();
		int LinearSearch(int val);
		int BinarySearch(int val);
		void BubbleSort();
};

class ArrayList
{
	private:
		int* array;
		int capacity;
		int get(unsigned int index);
		bool set(unsigned int index, int value);
		struct ArrayRefrence {
			ArrayList* target_;
			int index_;

			ArrayRefrence& operator=(int val);
			operator int();
		};
		void Grow();
	public:
		int length;
		ArrayList(int size);
		~ArrayList();
		ArrayRefrence operator[](int index);
		void PrintArrayList();
		void Push(int val);
		int Pop();
		void Enqueue(int val);
		int Deque();
		bool Insert(unsigned int index, int val);
		bool Delete(unsigned int index);
}; 

#endif