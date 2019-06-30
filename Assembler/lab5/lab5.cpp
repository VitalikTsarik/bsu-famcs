//14. В целочисленной прямоугольной матрице определить номер столбца, в котором
//содержится максимальное число нулей.Если таких столбцов несколько, выводить
//последний.
#include <iostream>
#include <iostream>

using namespace std;

extern "C" int _cdecl foo(int);
extern "C" int _cdecl foo_cdecl(int*, int, int);
extern "C" int _stdcall foo_stdcall(int*, int, int);
extern "C" int _fastcall foo_fastcall(int*, int, int);

int main()
{
	int *a, n, m, ans;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	if (n < 1 || m < 1)
	{
		cout << "Wrong input\n";
		system("Pause");
		return 0;
	}

	a = new int[n*m];

	cout << "Enter matrix:\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i + n * j];


	ans = foo_cdecl(a, n, m);
	cout << "cdecl:    ";
	if (ans == -1)
		cout << "The matrix doesn't contain zeros" << endl;
	else
		cout << ans << endl;

	ans = foo_stdcall(a, n, m);
	cout << "stdcall:  ";
	if (ans == -1)
		cout << "The matrix doesn't contain zeros" << endl;
	else
		cout << ans << endl;

	ans = foo_fastcall(a, n, m);
	cout << "fastcall: ";
	if (ans == -1)
		cout << "The matrix doesn't contain zeros" << endl;
	else
		cout << ans << endl;

	system("Pause");
	return 0;
}