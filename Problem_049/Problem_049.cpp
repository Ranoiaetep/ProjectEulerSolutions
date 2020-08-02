#include <iostream>
#include <string>
#include <cstdlib>

bool isPrime(long long number)
{
    std::lldiv_t d = {number, 0};
    for(long long i = 2; d.quot > i; i++)
    {
        d = std::lldiv(number, i);
        if(d.rem == 0)
        {
            return false;
        }
    }
    return true;
}

bool isPermutation(int a, int b, int c)
{
    std::string sA = std::to_string(a);
    std::string sB = std::to_string(b);
    std::string sC = std::to_string(c);
    std::sort(sA.begin(), sA.end());
    std::sort(sB.begin(), sB.end());
    std::sort(sC.begin(), sC.end());
    return sA == sB && sA == sC;
}

int main()
{
    for(int i = 1012; i < 9998; i++)
    {
        for (int j = 1; i + j + j < 10000; j++) {
            if(isPermutation(i, i + j, i + j + j))
            {
                if(isPrime(i) && isPrime(i+j) && isPrime(i+j+j))
                {
                    //if(i != 1487 && j != 3330)
                    {
                        std::cout << i << "," << i + j << "," << i + j + j << "\n";
                    }
                }
            }
        }
    }
}
