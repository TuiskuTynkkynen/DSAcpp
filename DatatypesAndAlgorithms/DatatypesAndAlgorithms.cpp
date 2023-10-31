#include <iostream>
#include <string> 
#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include "binarysearchtree.h"
#include "redblacktree.h"
#include "arrayalgorithms.h"
#include "pathfinding.h"
using namespace std;

void TestLinkedList() {
	cout << "\nSingly Linked List: \n";
	linkedlist::SinglyLinkedList slist;
	slist.PrependNode(2);
	slist.PrintList();
	slist.PrependNode(1);
	slist.PrintList();
	cout << "Count = " << slist.Count() << "\n";
	slist.AppendNode(4);
	slist.PrintList();
	cout << "Count = " << slist.Count() << "\n";
	cout << "Index of 2 = " << slist.IndexOf(2) << "\n";
	cout << "Index of 3 = " << slist.IndexOf(3) << "\n";
	slist.InsertAt(3, 3);
	slist.PrintList();
	slist.DeleteAt(slist.IndexOf(1));
	slist.PrintList();
	slist.FreeList();

	cout << "\nDoubly Linked List: \n";
	linkedlist::DoublyLinkedList dlist;
	dlist.PrependNode(1);
	dlist.PrependNode(3);
	dlist.PrependNode(4);
	dlist.AppendNode(5);
	dlist.AppendNode(6);
	dlist.PrintList();
	cout << "Count = " << dlist.Count() << "\n";
	cout << "Index of 2 = " << dlist.IndexOf(2) << "\n";
	cout << "Index of 3 = " << dlist.IndexOf(3) << "\n";
	dlist.InsertAt(2, 2);
	dlist.PrintList();
	cout << "Index of 2 = " << dlist.IndexOf(2) << "\n";
	dlist.DeleteValue(5);
	dlist.DeleteAt(4);
	dlist.PrintList();
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
	arrayalgorithms::Array arr(20);
	arr.InitializeRadomValues();
	arr.PrintArray();
	arr.BubbleSort();
	arr.PrintArray();
	arr.InitializeRadomValues();
	arr.PrintArray();
	arr.QuickSort();
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

	cout << "\nArray buffer: \n";
	arrayalgorithms::ArrayBuffer arrbuffer(2);
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Push(1);
	arrbuffer.Push(2);
	arrbuffer.Push(3);
	arrbuffer.Push(4);
	arrbuffer.Push(5);
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Pop();
	arrbuffer.Pop();
	arrbuffer.Pop();
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Pop();
	arrbuffer.Pop();
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Enqueue(1);
	arrbuffer.Enqueue(2);
	arrbuffer.Enqueue(3);
	arrbuffer.Enqueue(4);
	arrbuffer.Enqueue(5);
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Deque();
	arrbuffer.Deque();
	arrbuffer.Deque();
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Insert(1, 7);
	arrbuffer.Insert(1, 6);
	arrbuffer.Insert(1, 8);
	arrbuffer.Insert(5, 11);
	arrbuffer.PrintArrayBuffer();
	arrbuffer.Delete(3);
	arrbuffer.Delete(1);
	arrbuffer.PrintArrayBuffer();
}

void TestPathFinding() {
	pathfinding::SimpleMaze maze0;
	maze0.Solve();
	pathfinding::ComplexMaze maze1;
	maze1.Solve();
	pathfinding::VeryComplexMaze maze2;
	maze2.Solve();
}

int main()
{
	cout << "Hello World!\n";
	TestLinkedList();
	//TestQueue();
	//TestStack();
	//TestBinarySearchTree();
	//TestRedBlackTree();
	//TestArrayAlgorithms();
	//TestPathFinding();
}
