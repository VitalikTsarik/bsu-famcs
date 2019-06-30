#pragma once
#include <exception>
#include <iostream>
#include "Iterator.h"
using namespace std;

template<typename Type>
class Stack
{
public:

	typedef Iterator<Type> iterator;
	iterator begin() { return iterator(&arr[0]); }
	iterator end() { return iterator(&arr[size]); }

	Stack();
	explicit Stack(const Stack<Type>&);
	Stack(Type*, int);
	void operator= (const Stack<Type>&);
	void push(const Type&);
	void pop();
	Type top()const;
	bool empty()const { return size == 0; }
	~Stack();
	void print();

private:

	Type* arr;
	int size;
	int max_size;
	static const int standart_max_size = 10;
	static const int growth_rate = 2;
	void increase_max_size();

};

template<typename Type>
Stack<Type>::Stack() : size(0), max_size(standart_max_size)
{
	arr = new Type[max_size];
}
template<>
Stack<char*>::Stack() : size(0), max_size(standart_max_size)
{
	arr = new char*[max_size];
	for (int i = 0; i < max_size; ++i)
		arr[i] = new char[80];
}

template<typename Type>
Stack<Type>::Stack(const Stack<Type>& S) : size(0), max_size(standart_max_size)
{
	if (this != &S)
	{
		arr = new Type[max_size];
		for (int i = 0; i < S.size; ++i)
			push(S.arr[i]);
	}
}
template<>
Stack<char*>::Stack(const Stack<char*>& S) : size(0), max_size(standart_max_size)
{
	if (this != &S)
	{
		arr = new char*[max_size];
		for (int i = 0; i < max_size; ++i)
			arr[i] = new char[80];
		for (int i = 0; i < S.size; ++i)
			push(S.arr[i]);
	}
}

template<typename Type>
Stack<Type>::Stack(Type* arr, int size) : size(0), max_size(standart_max_size)
{
	this->arr = new Type[max_size];
	for (int i = 0; i < size; ++i)
		push(arr[i]);
}
template<>
Stack<char*>::Stack(char** arr, int size) : size(0), max_size(standart_max_size)
{
	this->arr = new char*[max_size];
	for (int i = 0; i < max_size; ++i)
		this->arr[i] = new char[80];
	for (int i = 0; i < size; ++i)
		push(arr[i]);
}


template<typename Type>
void Stack<Type>::increase_max_size()
{
	max_size *= growth_rate;
	Type* tmp = new Type[max_size];
	for (int i = 0; i < size; ++i)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}
template<>
void Stack<char*>::increase_max_size()
{
	char** tmp = new char*[max_size*growth_rate];
	for (int i = 0; i < max_size*growth_rate; ++i)
		tmp[i] = new char[80];

	for (int i = 0; i < size; ++i)
		strcpy_s(tmp[i], 80, arr[i]);

	for (int i = 0; i < max_size; ++i)
		delete[] arr[i];
	delete[] arr;

	max_size *= growth_rate;
	arr = tmp;
}


template<typename Type>
void Stack<Type>::operator= (const Stack<Type>& S)
{
	if (this != &S)
	{
		while (max_size < S.size)
			increase_max_size();
		size = S.size;
		for (int i = 0; i < S.size; ++i)
			arr[i] = S.arr[i];
	}
}
template<>
void Stack<char*>::operator= (const Stack<char*>& S)
{
	if (this != &S)
	{
		while (max_size < S.size)
			increase_max_size();
		size = S.size;
		for (int i = 0; i < S.size; ++i)
			strcpy_s(arr[i], 80, S.arr[i]);
	}
}


template<typename Type>
void Stack<Type>::push(const Type& el)
{
	if (size == max_size)
		increase_max_size();

	arr[size] = el;
	++size;
}


template<typename Type>
void Stack<Type>::pop()
{
	if (size == 0)
		throw underflow_error("empty before pop");
	--size;
}

template<typename Type>
Type Stack<Type>::top()const
{
	if (size == 0)
		throw range_error("Stack is empty. Can't get top element");
	return arr[size - 1];
}

template<typename Type>
Stack<Type>::~Stack()
{
	delete[] arr;
}

template<typename Type>
void Stack<Type>::print()
{
	for (Stack<Type>::iterator it = begin(); it != end(); ++it)
		cout << *it << ' ';
}
