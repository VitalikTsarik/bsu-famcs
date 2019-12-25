#include <fstream>
#include <set>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	set<int> nums;
	int x;

	while (fin >> x)
		nums.insert(x);

	long long sum = 0; 
	for (int a : nums)
		sum += a;

	fout << sum;
	return 0;
}