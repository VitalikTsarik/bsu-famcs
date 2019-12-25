#include <fstream>
#include <vector>

using namespace std;

class BST
{
	struct Node
	{
		int data;
		Node* left;
		Node* right;

		Node(int data): data(data), left(nullptr), right(nullptr) {}
	};

	void insert(Node*& root, int data)
	{
		if (root == nullptr)
			root = new Node(data);

		else if (data < root->data)
			insert(root->left, data);
		else if (data > root->data)
			insert(root->right, data);
	}

	Node* remove(Node* root, int data)
	{
		if (root == nullptr)
			return nullptr;

		if (data < root->data)
			root->left = remove(root->left, data);
		else if (data > root->data)
			root->right = remove(root->right, data);
		else
		{
			Node* tmp;

			if (root->right == nullptr)
			{
				tmp = root->left;
				delete root;
				return tmp;
			}
			if (root->left == nullptr)
			{
				tmp = root->right;
				delete root;
				return tmp;
			}

			Node* min_node = root->right;
			while (min_node->left)
				min_node = min_node->left;

			root->data = min_node->data;
			root->right = remove(root->right, min_node->data);
		}
		return root;
	}

	void pre_order(Node*& root, vector<int>& arr)const
	{
		if (root == nullptr)
			return;

		arr.push_back(root->data);
		pre_order(root->left, arr);
		pre_order(root->right, arr);
	}

public:
	BST(): root(nullptr) {}

	void insert(int data)
	{
		insert(root, data);
	}

	void remove(int data)
	{
		root = remove(root, data);
	}

	vector<int> pre_order()
	{
		vector<int> arr;
		pre_order(root, arr);
		return arr;
	}

	~BST()
	{
		
	}

private:
	Node* root;
};


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	BST bst;

	int to_remove;
	int x;

	fin >> to_remove;
	while (fin >> x)
		bst.insert(x);

	bst.remove(to_remove);

	vector<int> pre_order = bst.pre_order();

	for (int n : pre_order)
		fout << n << endl;

	fin.close();
	fout.close();
	return 0;
}