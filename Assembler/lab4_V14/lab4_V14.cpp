//14. В целочисленной прямоугольной матрице определить номер столбца, в котором
//содержится максимальное число нулей.Если таких столбцов несколько, выводить
//последний.

#include <iostream>

using namespace std;

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
			cin >> a[i + n*j ];

	_asm {
		xor edi, edi
		xor edx, edx
		mov ebx, a
		xor esi, esi 
		_next_col:
			mov ecx, n
			xor eax, eax
			_loop : 
				cmp [ebx], 0
				jne m1
				inc eax
				m1: add ebx, 4
			loop _loop
			inc esi
			cmp eax, edx
			jl m2
			mov edi, esi
			mov edx, eax
			m2: 
			cmp esi, m
		jl _next_col
		cmp edx, 0
		je no_zeros
		mov ans, edi			
	}

	cout << ans << endl;
	system("Pause");
	return 0;
no_zeros:
	cout << "The matrix doesn't contain zeros" << endl;
	system("Pause");
	return 0;
}