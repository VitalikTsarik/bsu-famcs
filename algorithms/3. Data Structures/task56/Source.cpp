#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	vector<bool> bits;
	long long n;
	fin >> n;

	while (n)
	{
		bits.push_back(n%2);
		n /= 2;
	}

	int i = 0;
	for (auto it = bits.begin(); it != bits.end(); ++it, ++i)
		if ((*it) || (*it) == 1 && i == 0)
			fout << (*it)*i << ' ';

	return 0;
}
