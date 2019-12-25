#include <fstream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
int cnt = 1;

void DFS(const vector<vector<bool>>& adj_matrix, int cur)
{
	if (ans[cur])
		return;

	ans[cur] = cnt++;
	for (int i = 0; i < n; ++i)
		if (adj_matrix[cur][i])
			DFS(adj_matrix, i);
}

vector<int> DFS(const vector<vector<bool>>& adj_matrix)
{
	ans.resize(n);
	for (int i = 0; i < n; ++i)
	{
		if (ans[i])
			continue;

		ans[i] = cnt++;
		for (int j = 0; j < n; ++j)
			if (adj_matrix[i][j])
				DFS(adj_matrix, j);
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

	vector<int> ans = DFS(adj_matrix);

	for (int el : ans)
		fout << el << ' ';

	return 0;
}