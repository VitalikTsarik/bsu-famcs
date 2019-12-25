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

	int x;
	while (fin >> x)
		bst.insert(x);

	vector<int> pre_order = bst.pre_order();

	for (int n : pre_order)
		fout << n << endl;

	fin.close();
	fout.close();
	return 0;
}