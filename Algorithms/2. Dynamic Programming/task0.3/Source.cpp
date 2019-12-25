#include <fstream>
#include <vector>

using namespace std;

vector<int> dims;
vector<vector<long long>> ans;

long long min_num_mult(int n)
{
	for (int k = 0; k < n; ++k)
		for (int i = k; i >= 0; --i)
		{
			if (i == k)
				ans[i][k] = 0;
			else
			{
				ans[i][k] = INT_MAX;
				for (int j = i; j < k; ++j)
				{
					long long tmp = ans[i][j] + ans[j + 1][k] + dims[i] * dims[j + 1] * dims[k + 1];
					if (ans[i][k] > tmp)
						ans[i][k] = tmp;
				}
			}
		}

	return ans[0][n-1];
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, dummy;
	fin >> n;
	dims.resize(n+1);
	for (int i = 0; i < n-1; ++i)
		fin >> dims[i] >> dummy;
	fin >> dims[n - 1] >> dims[n];

	ans.resize(n);
	for (auto& vec : ans)
		vec.resize(n);

	fout << min_num_mult(n);
	return 0;
}