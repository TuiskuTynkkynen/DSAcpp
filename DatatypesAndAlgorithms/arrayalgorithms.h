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
	public:
		const int length;
		Array(int size);
		~Array();
		void InitializeRadomValues();
		void PrintArray();
		int LinearSearch(int val);
		int BinarySearch(int val);
		void BubbleSort();
};

class ArrayList : public CustomArray
{
	private:
		int capacity;
		int get(unsigned int index) override;
		bool set(unsigned int index, int value);
		void Grow();
	public:
		int length;
		ArrayList(int size);
		~ArrayList();
		void PrintArrayList();
		void Push(int val);
		int Pop();
		void Enqueue(int val);
		int Deque();
		bool Insert(unsigned int index, int val);
		bool Delete(unsigned int index);
}; 

#endif