#include <fstream>
#include <vector>

using namespace std;

bool isHeap(const vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n/2; ++i)
		if (arr[i] > arr[2 * i] || arr[i] > arr[2 * i + 1])
			return false;

	if (n % 2 && arr[n / 2] > arr[n-1])
		return false;
	return true;
}

int main()
{
	ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n;
	fin >> n;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; ++i)
		fin >> arr[i];

	if (isHeap(arr))
		fout << "Yes";
	else
		fout << "No";
	return 0;
}
