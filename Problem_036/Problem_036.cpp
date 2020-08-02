#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

std::string getBinary(int number)
{
    std::string sNumber = std::bitset<20>(number).to_string();
    if(sNumber.find('1') == 0)
    {
        return sNumber;
    }
    return sNumber.substr(sNumber.find('1'));
}

bool isPalin(int n, int base)
{
    int reversed = 0;
    int temp = n;
    while(temp)
    {
        reversed = reversed * base + temp % base;
        temp /= base;
    }
    return n == reversed;
}

int main()
{
    long long sum = 0;
    for(int i = 1; i < 1000000; i += 2)
    {
        if (isPalin(i, 10) && isPalin(i, 2))
        {
            sum += i;
            std::cout << i << " : " << getBinary(i) << "\n";
        }
    }
    std::cout << "\n\n" << sum << "\n";
}
