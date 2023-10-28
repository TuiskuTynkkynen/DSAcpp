#include <iostream>
#include <string> 
#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include "binarysearchtree.h"
#include "redblacktree.h"
#include "arrayalgorithms.h"
using namespace std;

void TestLinkedList() {
	linkedlist::LinkedList list1;
	list1.PrependNode(2);
	list1.PrintList();
	list1.PrependNode(1);
	list1.PrintList();
	cout << "Count = " << list1.Count() << "\n";
	list1.AppendNode(4);
	cout << "Count = " << list1.Count() << "\n";
	list1.PrintList();
	cout << "Index of 2 = " << list1.IndexOf(2) << "\n";
	cout << "Index of 3 = " << list1.IndexOf(3) << "\n";
	list1.InsertAt(3, 3);
	list1.PrintList();
	list1.Delete(list1.IndexOf(1));
	list1.PrintList();
	list1.FreeList();
}

void TestQueue() {
	queue::Queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(8);
	q.Enqueue(1);
	cout << "Queue length = " << q.length << "\n";
	cout << "Dq = " << q.Deque() << "\n";
	cout << "Dq = " << q.Deque() << "\n";
	cout << "Queue length = " << q.length << "\n";
	cout << "Peek = " << q.Peek() << "\n";
	cout << "Peek = " << q.Peek() << "\n";
}

void TestStack() {
	stack::Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(8);
	s.Push(5);
	cout << "Stack length = " << s.length << "\n";
	cout << "Remove = " << s.Pop() << "\n";
	cout << "Remove = " << s.Pop() << "\n";
	cout << "Stack length = " << s.length << "\n";
	cout << "Peek = " << s.Peek() << "\n";
	cout << "Peek = " << s.Peek() << "\n";
}

void TestBinarySearchTree() {
	binarysearchtree::BinarySearchTree BST{};
	BST.Insert(4);
	BST.Insert(2);
	BST.Insert(1);
	BST.Insert(8);
	BST.Insert(6);
	BST.Insert(12);
	BST.Insert(10);
	BST.Insert(11);
	BST.Insert(14);
	BST.Insert(15);
	cout << "Min = " << BST.Min() << "\n";
	cout << "Max = " << BST.Max() << "\n";
	cout << "Size = " << BST.Size() << "\n";
	BST.Print();
	BST.Delete(8);
	cout << "Size = " << BST.Size() << "\n";
	BST.Print();
	for (int i = 0; i < 4; i++) {
		if (BST.Search(i)) {
			cout << "BST contains value =" << i << "\n";
		}
		else {
			cout << "BST doesn't contain value =" << i << "\n";
		}
	}
	BST.Free();
}

void TestRedBlackTree() {
	redblacktree::RedBlackTree RBTree;
	int num;
	cout << "How many numbers to try? ";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		RBTree.Insert(i);
	}
	RBTree.Print(1);
	RBTree.Print(0);
	for (int i = 1; i <= num; i++) {
		RBTree.Delete(i);
	}
	RBTree.Free();
	return;
	RBTree.Insert(4);
	RBTree.Insert(6);
	RBTree.Insert(5);
	RBTree.Insert(7);
	RBTree.Insert(2);
	RBTree.Insert(8);
	RBTree.Insert(9);
	RBTree.Insert(10);
	/*RBTree.Insert(11);
	RBTree.Insert(12);
	RBTree.Insert(13);
	RBTree.Insert(14);
	RBTree.Insert(15);
	RBTree.Insert(16);*/
	RBTree.Print(1);
	RBTree.Print(0);
	RBTree.Delete(4);
	RBTree.Print(1);
	RBTree.Print(0);
	RBTree.Free();
}

void TestArrayAlgorithms() {
	cout << "\nArray: \n";
	arrayalgorithms::Array arr(10);
	arr.InitializeRadomValues();
	arr.PrintArray();
	arr.BubbleSort();
	arr.PrintArray();
	cout << "Index of 1 = " << arr.LinearSearch(1) << "\n";
	cout << "Index of 6 = " << arr.LinearSearch(6) << "\n";
	cout << "Index of 1 = " << arr.BinarySearch(1) << "\n";
	cout << "Index of 6 = " << arr.BinarySearch(6) << "\n";
	cout << "Value at index 1 = " << arr[1] << "\n";
	arr[1] = 4;
	cout << "Value at index 1 = " << arr[1] << "\n";

	cout << "\nArray list: \n";
	arrayalgorithms::ArrayList arrlist(2);
	arrlist.PrintArrayList();
	arrlist.Push(1);
	arrlist.Push(2);
	arrlist.Push(3);
	arrlist.PrintArrayList();
	arrlist.Pop();
	arrlist.Pop();
	arrlist.Pop();
	arrlist.PrintArrayList();
	arrlist.Enqueue(1);
	arrlist.Enqueue(2);
	arrlist.Enqueue(3);
	arrlist.Enqueue(4);
	arrlist.Enqueue(5);
	arrlist.PrintArrayList();
	arrlist.Deque();
	arrlist.Deque();
	arrlist.Deque();
	arrlist.PrintArrayList();
	arrlist.Insert(1, 7);
	arrlist.Insert(1, 6);
	arrlist.Insert(1, 8);
	arrlist.Insert(5, 11);
	arrlist.PrintArrayList();
	arrlist.Delete(3);
	arrlist.Delete(1);
	arrlist.PrintArrayList();
	cout << "Value at index 1 = " << arrlist[1] << "\n";
	arrlist[1] = 4;
	cout << "Value at index 1 = " << arrlist[1] << "\n";
	cout << "Value at index 10 = " << arrlist[10] << "\n";
}

int main()
{
	//Implement arrayBuffer
	cout << "Hello World!\n";
	//TestLinkedList();
	//TestQueue();
	//TestStack();
	//TestBinarySearchTree();
	//TestRedBlackTree();
	TestArrayAlgorithms();
}
