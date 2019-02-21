#include <fstream>
#include <vector>

using namespace std;

int n;

vector<int> list_of_arcs_to_canonical(const vector<pair<int, int>>& list_of_arcs)
{
	vector<int> canon(n);

	for (int i = 0; i < n-1; ++i)
		canon[list_of_arcs[i].second - 1] = list_of_arcs[i].first;

	return canon;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> n;
	vector<pair<int, int>> list_of_arcs(n-1);
	for (int i = 0; i < n-1; ++i)
		fin >> list_of_arcs[i].first >> list_of_arcs[i].second;

	vector<int> canon = list_of_arcs_to_canonical(list_of_arcs);

	for (auto el : canon)
		fout << el << ' ';

	return 0;
}