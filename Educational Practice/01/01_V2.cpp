//2. Разработать шаблон функции, позволяющей найти в одномерном
//массиве максимальную монотонную подпоследовательность из подряд
//идущих элементов.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

enum Compare
{
	LESS = -1,
	EQUAL,
	GREATER
};

template <class Type>
Compare Сomparison(Type a, Type b)
{
	if (a < b)
		return LESS;
	if (a == b)
		return EQUAL;
	return GREATER;
}
template<>
Compare Сomparison<char*>(char* a, char* b)
{
	return (Compare)strcmp(a, b);;
}


void getRandom(int &x)
{
	x = rand() % 10; // range: 0-9
}

void getRandom(double &x)
{
	x = -10 + 20 * (double)rand() / RAND_MAX; // range from -10 to 10
}

void getRandom(char* &x)
{
	const char Symbols[] = "ABCD";
	int size = 3;

	char *temp = new char[size + 1];
	x = temp;
	while (size)
	{
		size--;
		*temp = Symbols[rand() % 4];
		temp++;
	}
	*temp = '\0';
}


template <class Type>
void MaxMonotonicSubsequence(Type Sq[], int Size)
{

	cout << "Maximum monotone subsequence of consecutive elements:\n";

	if (Size == 1)
	{
		cout << Sq[0];
		return;
	}

	int iMaxBeg = 0, lengthMax = 0, length = 1;
	Compare previous, current;

	int i = 0;
	do
	{
		previous = Сomparison(Sq[i], Sq[i + 1]);
		length++;
		i++;
	} while (previous == EQUAL);

	while (i < Size)
	{
		if (i != Size - 1)
			current = Сomparison(Sq[i], Sq[i + 1]);
		if ((current == previous || current == EQUAL) && i != Size - 1)
		{
			length++;
		}
		else
		{
			if (length > lengthMax)
			{
				lengthMax = length;
				iMaxBeg = i + 1 - length;
			}
			length = 2;
			previous = current;
		}
		i++;
	}

	for (int i = iMaxBeg; i < iMaxBeg + lengthMax; ++i)
		cout << Sq[i] << ' ';
}

template<class Type>
void doTheThing(Type* &arr, int Size)
{
	cout << "\nGenerated array:\n";
	for (int i = 0; i < Size; ++i)
	{
		getRandom(arr[i]);
		cout << arr[i] << ' ';
	}
	cout << endl;
	MaxMonotonicSubsequence(arr, Size);
	cout << endl;
}

void main()
{
	srand(time(NULL));
	int Size;
	do
	{
		cout << "Enter the size of arrays: ";
		cin >> Size;
		if (Size < 1)
			cout << "The size can't be less than one. Try again\n";
	} while (Size < 1);

	int *intArr = new int[Size];
	doTheThing(intArr, Size);
	delete[] intArr;

	cout << setprecision(3);
	double *dblArr = new double[Size];
	doTheThing(dblArr, Size);
	delete[] dblArr;

	char **chArr = new char*[Size];
	doTheThing(chArr, Size);
	for (int i = 0; i < Size; ++i)
		delete[]chArr[i];
	delete[] chArr;

	system("pause");
}