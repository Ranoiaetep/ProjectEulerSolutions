#include <iostream>
#include <cstdlib>
#include <cmath>

bool isIntTri(long long base, long long side)
{
    std::lldiv_t baseQ = std::lldiv(base, 2);
    if(baseQ.rem)
    {
        return false;
    }
    long long heightSq = side * side - baseQ.quot * baseQ.quot;
    long long height = std::round(std::pow(heightSq, 0.5));
    return height * height == heightSq;
}


int main()
{
    long long sum = 0;
    for(long long i = 3; i < 333333334; i++)
    {
        if(isIntTri(i, i+1))
        {
            std::cout << i << ", " << i+1 << "\n";
            sum += i * 3 + 2;
        }
        if(isIntTri(i, i-1))
        {
            std::cout << i << ", " << i-1 << "\n";
            sum += i * 3 - 2;
        }
    }
    std::cout << "\n\n" << sum << "\n";
}
