/*
Write function prototypes for the following cases. Use const if/when necessary.

a) A function named max() that takes two doubles and returns the larger of the two.

b) A function named swap() that swaps two integers.

c) A function named getLargestElement() that takes a dynamically allocated array of 
integers and returns the largest number in such a way that the caller can change the 
value of the element returned (don’t forget the length parameter).
*/
#include<iostream>

double max(const double a, const double b);

void swap(int& a, int& b);

int& getLargestNumber(int* arr, const int lenght);