#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	vector<long long> arr(n);
	for (auto& el : arr)
		fin >> el;

	vector<long long> lengths(n, 0);
	vector<long long> last_el_edx;
	last_el_edx.push_back(0);
	lengths[0] = 1;
	long long max_length = 1;
	for (long long i = 1; i < n; ++i)
	{
		if (arr[i] > arr[last_el_edx[last_el_edx.size() - 1]])
		{
			last_el_edx.push_back(i);
			lengths[i] = ++max_length;
		}
		else
		{
			auto it = upper_bound(last_el_edx.rbegin(), last_el_edx.rend(), i, [&](long long a, long long b)
			{
				return arr[a] > arr[b];
			});
			*(it - 1) = i;
			lengths[i] = last_el_edx.size() - (it - last_el_edx.rbegin() - 1);
		}
	}

	reverse(arr.begin(), arr.end());
	vector<long long> reverse_lengths(n, 0);
	last_el_edx.clear();
	last_el_edx.push_back(0);
	reverse_lengths[0] = 1;
	max_length = 1;

	for (long long i = 1; i < n; ++i)
	{
		if (arr[i] < arr[last_el_edx[last_el_edx.size() - 1]])
		{
			last_el_edx.push_back(i);
			reverse_lengths[i] = ++max_length;
		}
		else
		{
			auto it = upper_bound(last_el_edx.rbegin(), last_el_edx.rend(), i, [&](long long a, long long b)
			{
				return arr[a] < arr[b];
			});

			*(it - 1) = i;
			reverse_lengths[i] = last_el_edx.size() - (it - last_el_edx.rbegin() - 1);
		}
	}

	reverse(reverse_lengths.begin(), reverse_lengths.end());

	vector<long long> maxs(n);
	maxs[n - 1] = reverse_lengths[n - 1];
	for (long long i = n - 2; i >= 1; --i)
		maxs[i] = max(reverse_lengths[i], maxs[i + 1]);

	max_length = 1;
	for (long long i = 0; i < n - 1; ++i)
		max_length = max(max_length, lengths[i] + maxs[i + 1]);

	fout << max_length;

	return 0;
}