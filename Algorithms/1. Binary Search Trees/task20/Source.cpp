#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class BST
{
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node* parent;

		long long height;
		long long max_semipath_length;

		int min_deepest_val;
		int min_2nd_deepest_val;

		Node(int data, Node* parent) : data(data), left(nullptr), right(nullptr), parent(parent),
			height(NULL), max_semipath_length(NULL), min_deepest_val(NULL), min_2nd_deepest_val(NULL) {}
	};

	void insert(Node*& root, int data, Node* parent)
	{
		if (root == nullptr)
			root = new Node(data, parent);

		else if (data < root->data)
			insert(root->left, data, root);
		else if (data > root->data)
			insert(root->right, data, root);
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

	void pre_order(Node* root, vector<long long>& arr)const
	{
		if (root == nullptr)
			return;

		arr.push_back(root->data);
		pre_order(root->left, arr);
		pre_order(root->right, arr);
	}

	void postorder()
	{
		postorder(root);
	}
	void postorder(Node* root)
	{
		if (root == nullptr)
			return;

		postorder(root->left);
		postorder(root->right);

		if (root->left == nullptr && root->right == nullptr)
		{
			root->height = 0;
			root->max_semipath_length = 0;
			root->min_deepest_val = root->data;
		}
		else if (root->left && root->right)
		{
			root->height = max(root->left->height, root->right->height) + 1;
			root->max_semipath_length = root->left->height + root->right->height + 2;
			if (root->left->height == root->right->height)
				root->min_deepest_val = min(root->left->min_deepest_val, root->right->min_deepest_val);
			else if (root->left->height > root->right->height)
				root->min_deepest_val = root->left->min_deepest_val;
			else
				root->min_deepest_val = root->right->min_deepest_val;


			if (root->left->height > root->right->height)
			{
				if (root->left->height == root->right->height + 1)
					root->min_2nd_deepest_val = min(root->left->min_2nd_deepest_val, root->right->min_deepest_val);
				else
					root->min_2nd_deepest_val = root->left->min_2nd_deepest_val;
			}
			else if (root->left->height < root->right->height)
			{
				if (root->left->height + 1 == root->right->height)
					root->min_2nd_deepest_val = min(root->left->min_deepest_val, root->right->min_2nd_deepest_val);
				else
					root->min_2nd_deepest_val = root->right->min_2nd_deepest_val;
			}
			else
			{
				int left_min, right_min;
				if (root->left->left == nullptr && root->left->right == nullptr)
					left_min = root->data;
				else
					left_min = root->left->min_2nd_deepest_val;

				if (root->right->left == nullptr && root->right->right == nullptr)
					right_min = root->data;
				else
					right_min = root->right->min_2nd_deepest_val;
				root->min_2nd_deepest_val = min(left_min, right_min);
			}
		}
		else if (root->left)
		{
			root->height = root->left->height + 1;
			root->max_semipath_length = root->height;
			root->min_deepest_val = root->left->min_deepest_val;

			if (root->left->left == nullptr && root->left->right == nullptr)
				root->min_2nd_deepest_val = root->data;
			else
				root->min_2nd_deepest_val = root->left->min_2nd_deepest_val;
		}
		else if (root->right)
		{
			root->height = root->right->height + 1;
			root->max_semipath_length = root->height;
			root->min_deepest_val = root->right->min_deepest_val;

			if (root->right->left == nullptr && root->right->right == nullptr)
				root->min_2nd_deepest_val = root->data;
			else
				root->min_2nd_deepest_val = root->right->min_2nd_deepest_val;
		}

		if (root->max_semipath_length >= max_semipath_length - 1)
		{
			if (root->max_semipath_length > max_semipath_length)
			{
				roots.clear();
				max_semipath_length = root->max_semipath_length;
			}
			roots.push_back(root);

		}
	}

	vector<Node*> max_path(Node* root)
	{
		vector<Node*> path;

		if (root == nullptr)
			return path;

		while (root->left || root->right)
		{
			path.push_back(root);
			if (root->left && root->right)
				if (root->left->height < root->right->height)
					root = root->right;
				else
					root = root->left;

			else if (root->left)
				root = root->left;
			else if (root->right)
				root = root->right;
		}
		path.push_back(root);

		return path;
	}
	vector<Node*> almost_max_path(Node* root)
	{
		vector<Node*> path;
		if (root == nullptr || root->left == nullptr && root->right == nullptr)
			return path;
		long long n = root->height - 1;
		while (n)
		{
			path.push_back(root);
			n--;

			if (root->left && root->right)
				if (root->left->height < root->right->height && root->left->height != n)
					root = root->right;
				else
					root = root->left;

			else if (root->left)
				root = root->left;
			else if (root->right)
				root = root->right;
		}
		path.push_back(root);

		return path;
	}

	Node* find_best_root()
	{
		Node* best_root = nullptr;
		long long min_sum;

		if (find_if(roots.begin(), roots.end(), [&](Node* root)
		{
			if (root->left && root->right)
				return root->max_semipath_length == max_semipath_length && root->left->height != root->right->height;
			return root->max_semipath_length == max_semipath_length;
		}) != roots.end())
		{
			roots.erase(remove_if(roots.begin(),
				roots.end(), [&](Node* root)
			{
				if (root->left && root->right)
					return root->max_semipath_length != max_semipath_length || root->left->height == root->right->height;
				return root->max_semipath_length != max_semipath_length;
			}), roots.end());

			min_sum = INT64_MAX;
			for (auto i = roots.begin(); i != roots.end(); ++i)
			{
				long long sum;
				if ((*i)->left && (*i)->right)
					sum = (*i)->left->min_deepest_val + (*i)->right->min_deepest_val;
				else if ((*i)->left)
					sum = (*i)->left->min_deepest_val + (*i)->data;
				else if ((*i)->right)
					sum = (*i)->right->min_deepest_val + (*i)->data;

				if (sum < min_sum)
				{
					best_root = *i;
					min_sum = sum;
				}
			}
		}
		else
		{
			min_sum = INT64_MAX;
			for (auto i = roots.begin(); i != roots.end(); ++i)
			{
				long long sum;
				if ((*i)->left && (*i)->right)
				{
					if ((*i)->left->height == (*i)->right->height)
						sum = min((*i)->left->min_deepest_val + (*i)->right->min_2nd_deepest_val, (*i)->left->min_2nd_deepest_val + (*i)->right->min_deepest_val);
					else
						sum = (*i)->left->min_deepest_val + (*i)->right->min_deepest_val;
				}
				else if ((*i)->left)
					sum = (*i)->left->min_deepest_val + (*i)->data;
				else if ((*i)->right)
					sum = (*i)->right->min_deepest_val + (*i)->data;

				if (sum < min_sum)
				{
					best_root = *i;
					min_sum = sum;
				}
			}
		}

		return best_root;
	}

	Node* find_central_node(Node* root) // to refactor
	{
		vector<Node*> left_path;
		vector<Node*> right_path;

		if (root->left && root->right)
		{
			if (root->left->height == root->right->height)
			{
				if (root->left->min_deepest_val + root->right->min_2nd_deepest_val < root->left->min_2nd_deepest_val + root->right->min_deepest_val)
				{
					left_path = max_path(root->left);
					right_path = almost_max_path(root->right);
				}
				else
				{
					left_path = almost_max_path(root->left);
					right_path = max_path(root->right);
				}
			}
			else
			{
				left_path = max_path(root->left);
				right_path = max_path(root->right);
			}
		}
		else if (root->left)
			left_path = max_path(root->left);
		else if (root->right)
			right_path = max_path(root->right);

		vector<Node*> path;
		//vector<Node*> path = std::move(left_path);
		path.insert(path.end(), make_move_iterator(left_path.rbegin()), make_move_iterator(left_path.rend()));
		path.push_back(root);
		//std::move(right_path.begin(), right_path.end(), back_inserter(path));
		path.insert(path.end(), make_move_iterator(right_path.begin()), make_move_iterator(right_path.end()));

		min_sum = path[0]->data + path[path.size() - 1]->data;
		if (path.size() % 2)
			return path[path.size() / 2];
		return nullptr;
	}

	void right_rotation(Node*& node)
	{
		node->parent->left = node->right;
		node->right = node->parent;
		Node* tmp = node->parent->parent;
		if (root == node->parent)
			root = node;
		else if (tmp->right == node->parent)
			tmp->right = node;
		else
			tmp->left = node;
		node->parent->parent = node;
		node->parent = tmp;
	}
	void left_rotation(Node*& node)
	{

		node->parent->right = node->left;
		node->left = node->parent;
		Node* tmp = node->parent->parent;
		if (root == node->parent)
			root = node;
		else if (tmp->right == node->parent)
			tmp->right = node;
		else
			tmp->left = node;
		node->parent->parent = node;
		node->parent = tmp;
	}

public:
	BST() : root(nullptr), max_semipath_length(0) {}

	void insert(int data)
	{
		insert(root, data, nullptr);
	}

	void remove(int data)
	{
		root = remove(root, data);
	}

	vector<long long> pre_order()
	{
		vector<long long> arr;
		pre_order(root, arr);
		return arr;
	}

	vector<long long> task20()
	{
		postorder();
		Node* root = find_best_root();
		Node* central = find_central_node(root);

		if (central)
			while (this->root != central)
			{
				if (central->parent->right == central)
					left_rotation(central);
				else if (central->parent->left == central)
					right_rotation(central);
			}

		vector<long long> ans;
		ans.push_back(min_sum);
		vector<long long> preorder = pre_order();
		ans.insert(ans.begin() + 1, make_move_iterator(preorder.begin()), make_move_iterator(preorder.end()));
		return ans;
	}

	~BST()
	{

	}

private:
	Node* root;

	vector<Node*> roots;
	long long max_semipath_length;
	long long min_sum;
};

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	BST bst;

	int x;
	while (fin >> x)
		bst.insert(x);

	vector<long long> ans = bst.task20();

	for (long long n : ans)
		fout << n << '\n';
	fin.close();
	fout.close();
	return 0;
}