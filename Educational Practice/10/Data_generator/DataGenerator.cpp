#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double ASM_Taylor(double x, int k, int &it)
{
	int i;
	const float ten = 10.0;
	double ans;
	_asm {

		fld1
		fld ten
		mov ecx, k
		inc ecx
		_l1 : fdiv st(1), st(0)
			  loop _l1
			  fstp st // st(0) = eps

			  xor esi, esi
			  fldz
			  fld1
			  _l2 : inc esi

					fadd st(1), st
					fld x
					fmulp st(1), st // st(0) = i*x^i, st(1) = sum, st(2) = eps

					mov i, esi
					fild i
					fdiv st(1), st
					fld1
					faddp st(1), st
					fmulp st(1), st // st(0) = (i+1)*x^i 

					fld st
					fabs
					fcomip  st, st(3)

					jnb  _l2
					fstp st
					fstp ans
					fstp st
					fstp st
	}
	it = i;
	return ans;
}

int main()
{
	float x;
	try
	{
		cout << "x = ";
		cin >> x;
		if (x <= -1 || x >= 1)
			throw "Wrong input. Argument x must be in range ]-1, 1[\n";
	}
	catch (const char* e)
	{
		cout << e;
		system("pause");
		return 1;
	}

	int i;
	ofstream fout("Data.txt");
	fout << x << endl;
	for (int j = 2; j < 15; ++j)
	{
		ASM_Taylor(x, j, i);
		fout << i << endl;
	}
	return 0;
}

