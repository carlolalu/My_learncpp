#include<iostream>

bool is_divisible_3_5(int n)
{
    if ( n%3==0 || n%5==0)
        return true;
    else
        return false;
}

//return the sum of all the numbers divisble by 3 or 5
int bigsum(int m)
{
    int sum = 0;
    for(int i = 0; i<m; i++)
    {
        if(is_divisible_3_5(i)==1)
            {sum = sum +i;}
    }
    
    return sum;
}


int main(void)
{
    /*we wanna be fast: we must exploit two properties;
    
n is multiple of 5 is the last digit is 0 or 5
n is multiple of 3 if the sum of its digits is divisible by 3

Maybe it is not that fast as I think, maybe I have just to use the right operator*/
    std::cout << "Gimme a number : ";
    int n = 0;
    std::cin >> n;

    int sum = bigsum(n);

    std::cout <<"\n" <<  sum << "\n";


    return 0;
}
