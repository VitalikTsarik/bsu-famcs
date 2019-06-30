#include <iostream>
#include <iomanip>

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
	int k;
	double x;
	try
	{
		cout << "x = ";
		cin >> x;
		if (x <= -1 || x >= 1)
			throw "Wrong input. Argument x must be in range ]-1, 1[\n";
		cout << "k = ";
		cin >> k;
		if (k < 1 || k > 15)
			throw "Wrong input. Argument k must be in range [2, 15]\n";
	}
	catch (const char* e)
	{
		cout << e;
		system("pause");
		return 1;
	}

	double ansASM_FPU;
	_asm {
		fld1
		fld x
		fchs
		fld1
		faddp st(1), st(0)
		fld x
		fchs
		fld1
		faddp st(1), st(0)
		fmulp st(1), st(0)
		fdivp st(1), st(0)
		fstp ansASM_FPU
	}
	int i;
	cout << "C++:        " << fixed << setprecision(k) << 1 / ((1 - x)*(1 - x)) << endl;
	cout << "ASM FPU:    " << ansASM_FPU << endl;
	cout << "ASM Taylor: " << ASM_Taylor(x, k, i) << endl;

	system("pause");
	return 0;
}