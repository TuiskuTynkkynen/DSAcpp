#ifndef arrayalgorithms
#define arrayalgorithms

class Array
{
	
	private:
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
};

#endif