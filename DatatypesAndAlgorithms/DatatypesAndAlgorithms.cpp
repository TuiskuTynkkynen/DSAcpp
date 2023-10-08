#include <iostream>
#include <string> 
using namespace std;

int x = 0;
string* strs;
int width;

struct LinkedList
{
	struct Node
	{
		int value;
		Node* next{};
	};


	Node* list;

	void PrependNode(int val) {
		Node* node = new Node;
		Node* temp = list;
		node->next = temp;
		node->value = val;
		list = node;
	}
	
	void AppendNode(int val) {
		Node* node = list;
		while (node->next != nullptr)
		{
			node = node->next;
		}

		Node* newnode = new Node;
		newnode->value = val;
		node->next = newnode;
	}

	void InsertAt(int pos, int val) {
		Node* node = new Node;
		Node* temp = list;
		for (int i = 2; i < pos; i++) {
			if (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}

		node->next = temp->next;
		node->value = val;
		temp->next = node;
	}

	void Delete(int pos) {
		if (pos == 0) { return; }
		Node* node = list;
		if (pos == 1) {
			node = list->next;
			delete[] list;
			list = node;
			return;
		}

		for (int i = 2; i < pos; i++) {
			if (node->next != nullptr)
			{
				node = node->next;
			}
		}
		Node* temp = node->next;
		node->next = temp->next;
		delete[] temp;
	}

	void PrintList() {
		Node* node = list;
		while (node->next != nullptr)
		{
			cout << node->value << "/" << node->next;
			cout << ", ";
			node = node->next;
		}
		cout << node->value << "/" << node->next << "\n";
	}

	void FreeList() {
		Node* node;
		Node* next = list;
		while (next != nullptr)
		{
			node = next;
			cout << node->value << "/" << node->next << ": freed node\n";
			next = node->next;
			delete[] node;
		}
		cout << "freed list\n";
	}

	int Count() {
		Node* node = list;
		int count = 1;
		while (node->next != nullptr)
		{
			node = node->next;
			count++;
		}
		return count;
	}
	
	int IndexOf(int val) {
		Node* node = list;
		int index = 1;
		while (node != nullptr)
		{
			if (val == node->value) {
				return index;
			}
			node = node->next;
			index++;
		}
		return 0;
	}
};

struct BinarySearchTree
{
	struct Node
	{
		int value;
		Node* left{};
		Node* right{};
	};


	Node* tree;

	void Insert(int val) {
		Node* node = new Node;
		node->value = val;
		if (tree == nullptr) {
			tree = node;
			return;
		}

		Node* next = tree;
		Node* temp = tree;
		while (next != nullptr) {
			if (val < next->value) {
				temp = next;
				next = next->left;
			} else {
				temp = next;
				next = next->right;
			}
		}

		if (val < temp->value) {
			temp->left = node;
		} else if (val > temp->value) {
			temp->right = node;
		}
	}

	void Free() {
		Node* next = tree;
		Node* temp = tree;
		while (next->left != nullptr || next->right != nullptr) {
			temp = next;
			if (next->left != nullptr) {
				next = next->left;
			} else{ 
				next = next->right;
			}
		}

		if (next->value < temp->value) {
			cout << "freed node with value: " << temp->left->value << "\n";
			delete[] temp->left;
			temp->left = nullptr;
			Free();
		} else if (next->value > temp->value) {
			cout << "freed node with value: " << temp->right->value << "\n";
			delete[] temp->right;
			temp->right = nullptr;
			Free();
		} else if (tree->left == nullptr && tree->right == nullptr){
			cout << "freed root node with value: " << tree->value << "\n";
			delete[] tree;
			tree = nullptr;
		}
	}

	int Size() {
		x = 0;
		inOrder(tree, 0);
		return x;
	}

	void inOrder(Node* node, int width1) {
		if (node != nullptr) {
			inOrder(node->left, width1);
			width1++;
			x++;
			inOrder(node->right, width1);
			width1--;
		}

		if (abs(width1) > width) {
			width = abs(width1);
		}
	}

	void Print() {
		x = 0;
		width = 0;
		inOrder(tree, 0);
		strs = new string[width*2];
		cout << "Binary tree: \n";
		PrintTraverse(tree, 0);
		for (int i = 0; i < width*2; i++) {
			if (!strs[i].empty()) {
				cout << strs[i] << "\n";
			}
		}
		delete[] strs;
	}

	void PrintTraverse(Node* node, int depth) {
		if (node != nullptr) {
			depth++;
			PrintTraverse(node->left, depth);
			PrintTraverse(node->right, depth);
			depth--;

			int distance = 0;
			Node* temp = tree;
			while (node->value != temp->value) {
				if (node->value < temp->value) {
					temp = temp->left;
					distance++;
				} else {
					temp = temp->right;
					distance--;
				}
			}
			while (strs[width - distance].length() < 3 * depth + 1) {
				strs[width - distance] += " ";
			}
			string val = to_string(node->value);
			for (int i = 0; i < val.length(); i++) {
				strs[width - distance][depth*2 + i] = (strs[width - distance][depth * 2 + i] == ' ') ? val[i] : '?';
			}
			strs[width - distance][depth * 2 +  val.length()] = '<';
		}
	}
};

int main()
{
	//make size, width and length methods to make printing possible
	//(arr of str, str[width], str[how far right] = distance from length 0 * "whitespace" + value)
	//make some sort of print method to make sure elements are inserted in the right order
	cout << "Hello World!\n";
	BinarySearchTree BST{};
	BST.Insert(4);
	BST.Insert(2);
	BST.Insert(1);
	BST.Insert(3);
	BST.Insert(6);
	BST.Insert(5);
	BST.Insert(7);
	BST.Insert(111);
	cout << "Size = " << BST.Size() << "\n";
	BST.Print();
	BST.Free();

	/*LinkedList list1{};
	list1.PrependNode(2);
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
	list1.FreeList();*/
}