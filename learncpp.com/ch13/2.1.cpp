/*
 * a) Create a class called IntPair that holds two integers. This class should have two member variables to hold the integers. You should also create two member functions: one named “set” that will let you assign values to the integers, and one named “print” that will print the values of the variables.

The following main function should execute:

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}

and produce the output:

Pair(1, 1)
Pair(2, 2)
 */
#include<iostream>


class IntPair
{
public:
    int m_first{};
    int m_second{};

    void set(int x, int y)
    {
        m_first = x;
        m_second = y;
    }

    void print(void)
    {
        std::cout << "Pair(" << m_first << "," << m_second <<")\n";
    }
};


int main()
{
    IntPair p1;
    p1.set(1, 1); // set p1 values to (1, 1)

    IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}