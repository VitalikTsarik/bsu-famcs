#pragma once

template<typename Type>
class Iterator : public std::iterator<std::input_iterator_tag, Type>
{
public:

	Iterator(Type* ptr = nullptr) : ptr(ptr) {}

	Iterator<Type>& operator=(Iterator<Type>& It)
	{
		ptr = It.ptr;
		return (*this);
	}

	bool  operator==(const Iterator<Type>& It)const { return (ptr == It.ptr); }
	bool  operator!=(const Iterator<Type>& It)const { return (ptr != It.ptr); }

	Iterator<Type>& operator++()
	{
		++ptr;
		return (*this);
	}
	Iterator<Type>& operator++(int)
	{
		Iterator<Type> temp = *this;
		++ptr;
		return (temp);
	}

	Type& operator*()const { return *ptr; }
	Type* getPtr() { return ptr; }

private:

	Type* ptr;
};