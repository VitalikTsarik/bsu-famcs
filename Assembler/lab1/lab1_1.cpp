#include <iostream>
using namespace std;


void f1(int x) //1. (x 5 + 2 * (x 2 – 4) + x) / x 3
{
	cout << "1) ";
	if (x == 0)
	{
		cout << "Incorrect value\n";
		return;
	}

	int res;
	_asm{
		mov eax, x
		mov ebx, eax // ebx: x
		imul eax
		sub eax, 4
		imul eax, 2 
		add eax, ebx
		mov esi, eax // esi: 2 * (x*x - 4) + x
		mov eax, ebx
		mov ecx, 4
		m1: imul ebx 
			loop m1
			add esi, eax // esi: (x*x*x*x*x + 2 * (x*x - 4) + x) 

			mov eax, ebx
			imul ebx
			imul ebx
			xchg eax, esi
			cdq
			idiv esi

		mov res, eax
	}
	cout << "asm: " << res << '\t';
	cout << "C++: " << (x*x*x*x*x + 2 * (x*x - 4) + x) / (x*x*x) << endl;
}
void f2(int x) //2. (2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x)
{
	cout << "2) ";
	if (x == 0)
	{
		cout << "Incorrect value\n";
		return;
	}

	int res;
	_asm {
		mov eax, x
		mov ebx, eax
		imul eax, 2
		dec eax
		xchg ebx, eax
		imul eax, 2
		inc eax
		imul ebx 
		mov ebx, x
		add ebx, 3
		imul ebx // eax: (2 * x - 1) * (2 * x + 1) * (x + 3)
		mov ebx, x
		imul ebx, 2
		cdq
		idiv ebx
		mov res, eax
	}

	cout << "asm: " << res << '\t';
	cout << "C++: " << (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x) << endl;
}

void f3(int x) //3. (4 * x – 1) * (4 * x + 1) / 4
{
	cout << "3) ";

	int res;
	_asm {
		mov eax, x
		imul eax
		imul eax, 16
		dec eax
		cdq
		mov ebx, 4
		idiv ebx
		mov res, eax
	}

	cout << "asm: " << res << '\t';
	cout << "C++: " << (4 * x - 1) * (4 * x + 1) / 4 << endl;
}

int main()
{
	int x;
	cout << "x = ";
	cin >> x;
	f1(x);
	f2(x);
	f3(x);

	system("pause");
	return 0;
}