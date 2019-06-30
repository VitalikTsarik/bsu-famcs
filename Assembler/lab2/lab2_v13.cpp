//13. Переставить первую и последнюю цифры натурального числа.
#include <iostream>

using namespace std;
int main()
{
	int x;
	cout << "Enter number: ";
	cin >> x;
	_asm {
		mov eax, x
		cmp x, 0
		je m0
		jg positive1
		neg eax
		positive1 : mov ebx, 10

					xor edx, edx
					div ebx
					mov esi, edx // esi: last digit
					cmp eax, 0
					je m1
					mov ecx, 1

					l1: xor edx, edx
						idiv ebx
						inc ecx
						cmp eax, 0
						jne l1 // ecx: number of digits

						mov eax, x
						cmp eax, 0
						jg positive2
						neg eax
						positive2 : sub eax, esi
									add eax, edx
									xchg eax, esi
									dec ecx
									mov edi, edx
									l2 : mul ebx
										 imul edi, ebx
										 loop l2
										 sub esi, edi
										 add esi, eax

										 cmp x, 0
										 jg positive3
										 neg esi
										 positive3 : mov x, esi
													 m0 :
	m1:
	}
	cout << x << '\n';

	system("pause");
	return 0;
}