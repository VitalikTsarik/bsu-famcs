#include <fstream>
#include <vector>

using namespace std;

int n;

vector<int> list_of_arcs_to_canonical(const vector<vector<bool>>& adj_matrix)
{
	vector<int> canon(n);

	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)
			if (adj_matrix[i][j])
			{
				canon[j] = i + 1;
				break;
			}

	return canon;
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
	vector<int> canon = list_of_arcs_to_canonical(adj_matrix);

	for (auto el : canon)
		fout << el << ' ';

	return 0;
}