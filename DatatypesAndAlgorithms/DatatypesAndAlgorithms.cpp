#include <iostream>
#include <string> 
#include "linkedlist.h"
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

int main()
{
	cout << "Hello World!\n";
	//TestLinkedList();
	//TestBinarySearchTree();
	//TestRedBlackTree();
	arrayalgorithms::Array arr(10);
	arr.InitializeRadomValues();
	arr.PrintArray();
}
