#include <iostream>
#include <numeric>

bool isCurious(int a, int b)
{
    if(a % 10 == 0 || a == b)
    {
        return false;
    }
    if(a * (b / 10) == b * (a / 10)  && b % 10 == a % 10 ||
            a * (b / 10) == b * (a % 10) && b % 10 == a / 10 ||
            a * (b % 10) == b * (a % 10) && b / 10 == a / 10 ||
            a * (b % 10) == b * (a / 10) && b / 10 == a % 10 )
    {
        return true;
    }
    return false;
}

int main()
{
    int a = 1, b = 1;
    for(int i = 10; i < 100; i++)
    {
        for(int j = 10; j < i; j++)
        {
            if(isCurious(i,j))
            {
                a *= j;
                b *= i;
                std::cout << j << " / " << i << "\n";
            }
        }
    }
    std::cout << "\n" << b / std::gcd(a,b) << "\n";
}
