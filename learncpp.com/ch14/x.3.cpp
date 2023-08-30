/*
	Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). Users should pass in the size of the array when it is created, and the array should be dynamically allocated. Use assert statements to guard against bad data. Create any constructors or overloaded operators needed to make the following program operate correctly:

#include <iostream>

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}

	This program should print:

5 8 2 3 6
5 8 2 3 6

*/

#include <iostream>

class IntArray
{
public:
	IntArray(int lenght) : m_lenght{lenght}
	{}

	// I assume no dumb users trying to take an index outside of the range of the array
	int& operator[] (int index);

	friend std::ostream& operator<< (std::ostream& out, const IntArray& intarr);

	// the rule of three (regarding memory allocation): copy constructor (it is a constructor, no return type!), copy assignment operator, destructor (again no return type!)
	IntArray(const IntArray& source) : m_lenght{source.m_lenght}
	{
		for(int index{}; index<m_lenght; ++index)
		{
			(this->m_array)[index] = source.m_array[index];
		}
	}
	IntArray& operator= (const IntArray& source);
	~IntArray();

	friend IntArray fillArray(void);

private:
	// I assume no dumb users requiring negative lenght
	int m_lenght{};
	int* m_array{ new int[m_lenght]{} };
};

int& IntArray::operator[] (const int index)
{
	return m_array[index];
}

std::ostream& operator<< (std::ostream& out, const IntArray& intarr)
{
	for(int index{}; index<intarr.m_lenght; ++index)
	{
		out << intarr.m_array[index];
	}
	return out;
}

IntArray& IntArray::operator= (const IntArray& source)
{
	if(this==&source){
		return *this;
	}

	m_lenght=source.m_lenght;
	for(int index{}; index<m_lenght; ++index)
	{
		(this->m_array)[index] = source.m_array[index];
	}

	return *this;
}

IntArray::~IntArray()
	{
		delete m_array;
	}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}