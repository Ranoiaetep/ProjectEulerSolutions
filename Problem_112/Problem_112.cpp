#include <iostream>
#include <string>

bool isIncreasing(std::string sNumber)
{
    for(auto it = sNumber.begin(); it != sNumber.end()-1; it++)
    {
        if (*it > *(it+1)) {
            return false;
        }
    }
    return true;
}

bool isDecreasing(std::string sNumber)
{
    for(auto it = sNumber.begin(); it != sNumber.end()-1; it++)
    {
        if (*it < *(it+1)) {
            return false;
        }
    }
    return true;
}


bool isBouncy(long long number)
{
    std::string sNumber = std::to_string(number);
    return !isIncreasing(sNumber) && !isDecreasing(sNumber);
}


int main()
{
    long long notBouncy = 0;
    long long Bouncy = 0;
    long long number = 1;
    while(notBouncy * 99 >= Bouncy)
    {
        bool temp = isBouncy(number);
        temp ? Bouncy++ : notBouncy++;
        number++;
    }
    std::cout << number-2 << "\n";
}
