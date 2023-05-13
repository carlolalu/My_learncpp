#include<iostream>
#include<cmath>

int parts(int n)
{
    if(n==1)
    {return 1;}

    int max = n;

    for(int i=1; i <= n/2; i++)
    {
        int candidate = parts(n-i)*parts(i);
        if(candidate < max)
            {continue;}

        max = {candidate};
    }
    return max;
}


int main(void)
{
    std::cout << "\nEnter a positive number: ";
    int x{0};
    std::cin >> x;
    std::cout << "\nthe result is: " << parts(x);
    
    return 0;
}