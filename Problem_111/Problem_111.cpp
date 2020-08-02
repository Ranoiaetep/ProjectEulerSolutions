#include <iostream>
#include <string>
#include <algorithm>

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

long long S(int length, int digit)
{
    long long sum = 0;
    if(digit)
    {
        for(char c = '0'; c <= '9'; c++)
        {
            std::string sNumber(1, c);
            for(int i = 0; i < length - 1; i++)
            {
                sNumber += digit + '0';
            }
            std::sort(sNumber.begin(), sNumber.end());
            do
            {
                if(sNumber[0] != '0')
                {
                    long long temp = std::stoll(sNumber);
                    if (isPrime(temp)) {
                        std::cout << temp << ", ";
                        sum += temp;
                    }
                }
            }while (std::next_permutation(sNumber.begin(), sNumber.end()));
        }
    }
    if(!digit || sum == 0)
    {
        for(char c = '0'; c <= '9'; c++)
        {
            for(char d = c; d <= '9'; d++)
            {
                std::string sNumber(1, c);
                sNumber += d;
                for(int i = 0; i < length - 2; i++)
                {
                    sNumber += digit + '0';
                }
                std::sort(sNumber.begin(), sNumber.end());
                do
                {
                    if(sNumber[0] != '0')
                    {
                        long long temp = std::stoll(sNumber);
                        if (isPrime(temp)) {
                            std::cout << temp << ", ";
                            sum += temp;
                        }
                    }
                }while (std::next_permutation(sNumber.begin(), sNumber.end()));
            }
        }
    }
    return sum;
}


int main()
{
    long long sum = 0;
    for(int i = 0; i <= 9; i++)
    {
        long long temp = S(10, i);
        sum += temp;
        std::cout << ": " << temp << "\n";
    }
    std::cout << "\n\n" << sum << "\n";
}
