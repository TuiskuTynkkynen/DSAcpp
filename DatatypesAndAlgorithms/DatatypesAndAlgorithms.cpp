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

		Node* parent = nullptr;
		Node* temp = tree;
		while (temp != nullptr) {
			parent = temp;
			if (val < temp->value) {
				temp = temp->left;
			} else {
				temp = temp->right;
			}
		}

		if (val < parent->value) {
			parent->left = node;
		} else if (val > parent->value) {
			parent->right = node;
		}
	}

	void Delete(int val) {
		//naïve implementation

		Node* node = tree;
		Node* parent = tree;
		while (node != nullptr) {
			if (node->value == val) {
				break;
			} else if (val < node->value) {
				parent = node;
				node = node->left;
			} else {
				parent = node;
				node = node->right;
			}
		}

		if (node == nullptr) {
			return;
		}

		//if deleted node is a leaf node 
		if (node->left == nullptr && node->right == nullptr) {
			if (node->value < parent->value) { //if deleted node is left child
				delete[] parent->left;
				parent->left = nullptr;
			} else {                           //else deleted node is right child
				delete[] parent->right;
				parent->right = nullptr;
			}
			return;
		}

		//if deleted node has only one child node 
		if (node->left == nullptr || node->right == nullptr) {
			Node* temp;
			if (node->left != nullptr) { //if deleted node has left child
				temp = node->left;
			} else {                     //else deleted node has right child
				temp = node->right;
			}
				
			if (node->value < parent->value) { //replace left child of parent node
				delete[] parent->left;
				parent->left = temp;
			} else {                           //replace right child of parent node
				delete[] parent->right;
				parent->right = temp;
			}
			return;
		}

		Node* temp = node->right;

		if (temp->left == nullptr) {
			temp->left = node->left;
			if (node->value < parent->value) {
				delete[] parent->left;
				parent->left = temp;
			} else {
				delete[] parent->right;
				parent->right = temp;
			}
		} else {
			while (temp->left != nullptr) {
				temp = temp->left;
			}

			node->right->left = temp->right;
			temp->right = node->right;
			temp->left = node->left;
			if (node->value < parent->value) {
				delete[] parent->left;
				parent->left = temp;
			} else {
				delete[] parent->right;
				parent->right = temp;
			}
		}
		
	}

	void Free() {
		Node* node = tree;
		Node* parent = tree;
		while (node->left != nullptr || node->right != nullptr) {
			parent = node;
			if (node->left != nullptr) {
				node = node->left;
			} else{ 
				node = node->right;
			}
		}

		if (node->value < parent->value) {
			cout << "freed node with value: " << parent->left->value << "\n";
			delete[] parent->left;
			parent->left = nullptr;
			Free();
		} else if (node->value > parent->value) {
			cout << "freed node with value: " << parent->right->value << "\n";
			delete[] parent->right;
			parent->right = nullptr;
			Free();
		} else if (tree->left == nullptr && tree->right == nullptr){
			cout << "freed root node with value: " << tree->value << "\n";
			delete[] tree;
			tree = nullptr;
		}
	}

	bool Search(int val) {
		Node* node = tree;
		while (node != nullptr) {
			if (node->value == val) {
				return true;
			} else if (node->value > val){
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return false;
	}

	int Min() {
		Node* node = MinChild(tree);
		return node->value;
	}

	int Max() {
		Node* node = MaxChild(tree);
		return node->value;
	}
	
	int Size() {
		x = 0;
		inOrder(tree, 0);
		return x;
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

	private : void inOrder(Node* node, int tempwidth) {
		if (node != nullptr) {
			inOrder(node->left, tempwidth);
			tempwidth++;
			x++;
			inOrder(node->right, tempwidth);
			tempwidth--;
		}

		if (abs(tempwidth) > width) {
			width = abs(tempwidth);
		}
	}

	private: void PrintTraverse(Node* node, int depth) {
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
	
	private: Node* MinChild(Node* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	private: Node* MaxChild(Node* node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	private: Node* Parent(Node* node) {
		Node* parent = nullptr;
		Node* temp = tree;
		while (node->value != temp->value) {
			if (node->value < temp->value) {
				parent = temp;
				temp = temp->left;
			}
			else {
				parent = temp;
				temp = temp->right;
			}
		}
		return parent;
	}

	private : Node* Predecessor(Node* node) {
		if (node->left != nullptr){
			return MaxChild(node->left);
		}

		Node* parent = Parent(node);
		while (parent != nullptr && node == parent->left) {
			node = parent;
			parent = Parent(node);
		}
		return parent;
	}
	
	private : Node* Successor(Node* node) {
		if (node->right != nullptr) {
			return MinChild(node->right);
		}

		Node* parent = Parent(node);
		while (parent != nullptr && node == parent->right) {
			node = parent;
			parent = Parent(node);
		}
		return parent;
	}
};

int main()
{
	cout << "Hello World!\n";
	BinarySearchTree BST{};
	BST.Insert(4);
	BST.Insert(2);
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
		} else {
			cout << "BST doesn't contain value =" << i << "\n";
		}
	}
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