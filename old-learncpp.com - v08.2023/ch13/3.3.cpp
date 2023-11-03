/*
 * Question #3

Now let’s try something a little more complex. Let’s write a class that implements a simple stack from scratch. Review lesson 12.2 -- The stack and the heap if you need a refresher on what a stack is.

The class should be named Stack, and should contain:

    A private array of integers of length 10.
    A private integer to keep track of the size of the stack.
    A public member function named reset() that sets the size to 0.
    A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
    A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
    A public member function named print() that prints all the values in the stack.

Make sure the following program executes correctly:

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}

This should print:

( )
( 5 3 8 )
( 5 3 )
( )

 */

#include<iostream>
#include<array>
#include<cassert>

class Stack     // I would prefer to call this Stack10
{
private:
    std::array<int,10> m_space {};
    std::size_t m_size {};

public:
    void reset(void)
    {
        m_size = {0};
    }

    bool push(const int a)
    {
        if(m_size < 10){
            m_space.at(m_size++) = a;
            return true;
        } else {
            return false;
        }
    }

    int pop(void)
    {
        assert(m_size && "m_size is 0!");
        return m_space.at(--m_size);
    }

    void print(void)
    {
        std::cout << '(';
        for(std::size_t index {}; index<m_size; ++index)
        {
            std::cout << m_space.at(index) << ' ';
        }
        std::cout << ')' << '\n';
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}