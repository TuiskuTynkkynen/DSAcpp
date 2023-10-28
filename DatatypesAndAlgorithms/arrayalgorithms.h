#ifndef arrayalgorithms
#define arrayalgorithms

class CustomArray {
	protected:
		int* array;
		virtual int get(unsigned int index);
		virtual bool set(unsigned index, int value);
		struct ArrayRefrence {
			CustomArray* target_;
			int index_;

			ArrayRefrence& operator=(int val);
			operator int();
		};
	public:
		CustomArray();
		ArrayRefrence operator[](int index);

};

class Array : public CustomArray
{ 
	private:
		const unsigned int length;
	public:
		Array(int size);
		~Array();
		int GetLength();
		void InitializeRadomValues();
		void PrintArray();
		int LinearSearch(int val);
		int BinarySearch(int val);
		void BubbleSort();
};

class ArrayList : public CustomArray
{
	private:
		unsigned int capacity;
		unsigned int length;
		int get(unsigned int index) override;
		bool set(unsigned int index, int value);
		void Grow();
	public:
		ArrayList(int size);
		~ArrayList();
		int GetLength();
		void PrintArrayList();
		void Push(int val);
		int Pop();
		void Enqueue(int val);
		int Deque();
		bool Insert(unsigned int index, int val);
		bool Delete(unsigned int index);
}; 

class ArrayBuffer : public CustomArray
{
	private:
		unsigned int capacity;
		unsigned int head;
		unsigned int tail;
		unsigned int length;
		int get(unsigned int index) override;
		bool set(unsigned int index, int value);
		void Grow();
	public:
		ArrayBuffer(int size);
		~ArrayBuffer();
		int GetLength();
};

#endif