#include <fstream>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> list_of_edges_to_adj_list(const vector<pair<int, int>>& list_of_edges)
{
	vector<vector<int>>  adj_list(n);

	for (int i = 0; i < m; ++i)
	{
		adj_list[list_of_edges[i].first - 1].push_back(list_of_edges[i].second);
		adj_list[list_of_edges[i].second - 1].push_back(list_of_edges[i].first);
	}
	return adj_list;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n >> m;
	vector<pair<int, int>> list_of_edges(m);
	for (int i = 0; i < m; ++i)
		fin >> list_of_edges[i].first >> list_of_edges[i].second;

	vector<vector<int>> adj_list = list_of_edges_to_adj_list(list_of_edges);

	for (auto line : adj_list)
	{
		fout << line.size() << ' ';
		for (auto el : line)
			fout << el << ' ';
		fout << '\n';
	}

	return 0;
}