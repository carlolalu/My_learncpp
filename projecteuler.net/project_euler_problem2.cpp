#include<iostream>
#include<cmath>

long long sum_even_fibonacci(long upperbound);

int main(void)
{
    long ubound = 4*1000*1000;
    long long total = sum_even_fibonacci(ubound);
    std::cout << total << std::endl;

    return 0;
}


//brute force system: will likely crash for the lack of memory
long long sum_even_fibonacci(long upperbound)
{
    long tmp;
    long preprevious_member = 0;
    long previous_member = 1;
    long actual_member = 1;
    long long sum = 0;
    while(actual_member <= upperbound)
    {
        if(actual_member%2==0)
            {sum += actual_member;}
        tmp = previous_member;
        actual_member += previous_member;
        previous_member += preprevious_member;
        preprevious_member = tmp;
    }
    return sum;
}


//I would like to write here a more elegant method based on some mathematical observation on the sequence