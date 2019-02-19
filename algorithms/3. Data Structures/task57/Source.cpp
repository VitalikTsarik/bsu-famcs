#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int m, c, n;
	fin >> m >> c >> n;

	vector<int> ht(m, -1);
	int x;
	while (fin >> x)
	{
		int h;
		int i = 0;
		do
		{
			h = (x%m + c * i) % m;
			++i;
		} while (ht[h] != -1 && ht[h] != x);
		ht[h] = x;
	}

	for (int x : ht)
		fout << x << ' ';

	return 0;
}
