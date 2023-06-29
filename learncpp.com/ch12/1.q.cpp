/*
In this quiz, we’re going to write a version of our basic calculator using function pointers.

1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.

1b) Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return an integer.

1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes two integer parameters and returns an integer. Use std::function, and include the appropriate header.

1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.

1e) Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs and print the result.
 */

#include<iostream>
#include<functional>
#include "1.q.h"

// input structure
int getInteger(void)
{
    std::cout <<"Enter an integer: ";
    int num{};
    std::cin >> num;
    return num;
}

char selectOperation(void)
{
    char operation {};
    do {
        std::cout << "Select an operation between ‘+’, ‘-‘, ‘*’ and ‘/’: ";
        std::cin >> operation;
    } while (operation!='+' && operation!='-' && operation!='*' && operation!='/');

    return operation;
}

// operations
int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a/b;
}

// functional structure

// if we would use the common ptrs
using ArthmFunc = int (*)(int, int);
// with the <functional> header
using ArithmeticFunction = std::function<int(int,int)>;

// I opt for the classical ptrs
ArthmFunc getArithmeticFunction(char op)
{
    switch(op)
    {
        case '+': return &add; break;
        case '-': return &subtract; break;
        case '*': return &multiply; break;
        case '/': return &divide; break;
        default: return &add; break;
    }
}

#ifndef DO_NOT_EXECUTE

int main(void)
{
    int a {};
    int b {};
    a = {getInteger()};
    char op = {selectOperation()};
    b = {getInteger()};

    ArithmeticFunction arithmeticFunction{getArithmeticFunction(op)};

    if(arithmeticFunction)
        std::cout << "the result is: " << arithmeticFunction(a,b) << '\n';

    return 0;
}

#endif