#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<int> BFS(const vector<vector<bool>>& adj_matrix)
{
	vector<int> ans(n);
	int count = 1;

	queue<int> queue;
	int start = 0;

	while (start != n)
	{
		queue.push(start++);
		while (!queue.empty())
		{
			int tmp = queue.front();
			queue.pop();

			if (ans[tmp] == 0)
			{
				if (tmp == start)
					start++;
				ans[tmp] = count++;

				for (int i = 0; i < n; ++i)
					if (adj_matrix[tmp][i])
						queue.push(i);
			}
		}
	}
	return ans;
}


int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n;
	vector<vector<bool>> adj_matrix(n);
	int x;
	for (auto& vec : adj_matrix)
	{
		vec.resize(n);
		for (int i = 0; i < n; ++i)
		{
			fin >> x;
			vec[i] = x;
		}
	}

	vector<int> ans = BFS(adj_matrix);

	for (int el : ans)
		fout << el << ' ';

	return 0;
}