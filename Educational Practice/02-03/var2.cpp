//2. Разработать шаблон класса для работы со стеком, 
//реалтзованным в динамическом массиве

#include <iostream>
#include <ctime>
#include "Stack.h"
#include <algorithm>

using namespace std;

enum Color
{
	Red,
	Green,
	Blue
};


class Railway_carriage
{
public:

	Railway_carriage() {}
	Railway_carriage(Color color, int type = 1, int weight = 20, int dimensions = 4) : color(color), type(type), weight(weight), dimensions(dimensions) {}
	Color getColor() { return color; }

private:

	int type;
	Color color;
	int weight;
	int dimensions;

};


int main()
{
	int intArr[]{ 1,2,3,4,5,6,7,8,9,10,11,12 };
	Stack<int> S1, S2(intArr, 12), S3(S2);

	S1 = S2;
	S1.pop();
	S3.push(13);

	cout << "int:\n"
		<< "\n1st: ";
	S1.print();
	cout << "\n2nd: ";
	S2.print();
	cout << "\n3rd: ";
	S3.print();

	char* charArr[]{ "ab","bc","cd" };
	Stack<char*> S4, S5(charArr, 3), S6(S5);

	S4 = S5;
	S4.pop();
	S6.push("de");

	cout << "\n\nchar*:\n"
		<< "\n4th: ";
	S4.print();
	cout << "\n5th: ";
	S5.print();
	cout << "\n6th: ";
	S6.print();

	srand(time(NULL));

	const int size = 50;
	Railway_carriage *initial = new Railway_carriage[size];

	for (int i = 0; i < size; ++i)
		initial[i] = Railway_carriage(Color(rand() % 2));

	Stack<Railway_carriage> Station;

	for (int i = 0; i < size; ++i)
		Station.push(initial[i]);

	Railway_carriage *first = new Railway_carriage[size], *second = new Railway_carriage[size];
	int count1 = 0, count2 = 0;

	for (int i = 0; i < size; ++i)
	{
		if (Station.top().getColor() == Red)
			first[count1++] = Station.top();
		else
			second[count2++] = Station.top();
		Station.pop();
	}

	cout << "\n\nCarriages:\n"
		<< "Number of red railway carriages: " << count1 << endl
		<< "Number of green railway carriages: " << count2 << endl;


	Stack<int>::iterator it = S1.begin();

	system("pause");
	return 0;
}
