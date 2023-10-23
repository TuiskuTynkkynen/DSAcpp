#include <iostream>
#include <string> 
#include "linkedlist.h"
#include "binarysearchtree.h"
#include "redblacktree.h"
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
	RBTree.Insert(4);
	RBTree.Insert(6);
	RBTree.Insert(5);
	RBTree.Insert(7);
	RBTree.Insert(2);
	RBTree.Print();
	RBTree.TestRotation(6,1);
	RBTree.Print();
	RBTree.Free();
}

int main()
{
	cout << "Hello World!\n";
	//TestLinkedList();
	//TestBinarySearchTree();
	TestRedBlackTree();
}
