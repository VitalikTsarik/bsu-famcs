#include <fstream>
#include <vector>

using namespace std;

int n, m;

vector<vector<bool>> list_of_edges_to_adj_matrix(const vector<pair<short, short>>& list_of_edges)
{
	vector<vector<bool>> adj_matrix(n);
	for (auto& vec : adj_matrix)
		vec.resize(n, false);

	for (int i = 0; i < m; ++i)
	{
		adj_matrix[list_of_edges[i].first-1][list_of_edges[i].second-1] = true;
		adj_matrix[list_of_edges[i].second-1][list_of_edges[i].first-1] = true;
	}
	return adj_matrix;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n >> m;
	vector<pair<short, short>> list_of_edges(m);
	for (int i = 0; i < m; ++i)
		fin >> list_of_edges[i].first >> list_of_edges[i].second;

	vector<vector<bool>> adj_matrix = list_of_edges_to_adj_matrix(list_of_edges);

	for (auto line : adj_matrix)
	{
		for (auto el : line)
			fout << el << ' ';
		fout << '\n';
	}

	return 0;
}