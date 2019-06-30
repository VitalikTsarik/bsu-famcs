#pragma once
#include "Stack.h"
#include "Iterator.h"
#include <algorithm>
#include <iostream>

using namespace std;

template<typename Type> class Stack;
template<typename Type> class Iterator;

template <typename Type>
class Visitor
{
public:


	virtual void visit(Stack<Type>*) = 0;

};

template <class Type>
class min_Visitor : public Visitor<Type>
{
private:

	Type Min;

public:

	void visit(Stack<Type>* stack)
	{
		Type min = stack->top();
		for_each(stack->begin(), stack->end(), [&min](Type tmp) { if (tmp < min) min = tmp; });
		Min = min;
	}
	Type getMin() { return Min; }


};

template <class Type>
class max_Visitor : public Visitor<Type>
{
private:

	Type Max;

public:

	void visit(Stack<Type>* stack)
	{
		Type max = stack->top();
		for_each(stack->begin(), stack->end(), [&max](Type tmp) { if (tmp > max) max = tmp; });
		Max = max;
	}
	Type getMax() { return Max; }
};

template <class Type>
class imin_Visitor : public Visitor<Type>
{
private:

	Iterator<Type> imin;

public:

	imin_Visitor() : imin(nullptr) {}
	void visit(Stack<Type>* stack)
	{
		imin = stack->begin();
		for (Iterator<Type> it = stack->begin(); it != stack->end(); ++it)
			if (*imin > *it)
				imin = it;
	}
	Iterator<Type> get_imin() { return imin; }
};

template <class Type>
class imax_Visitor : public Visitor<Type>
{
private:

	Iterator<Type> imax;

public:

	imax_Visitor() : imax(nullptr) {}
	void visit(Stack<Type>* stack)
	{
		imax = stack->begin();
		for (Iterator<Type> it = stack->begin(); it != stack->end(); ++it)
			if (*imax < *it)
				imax = it;
	}
	Iterator<Type> get_imax() { return imax; }
};