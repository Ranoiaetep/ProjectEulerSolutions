#include <iostream>

uint64_t nextChain(uint64_t number)
{
    uint64_t result = 0;
    while(number)
    {
        uint8_t digit = number % 10;
        result += digit * digit;
        number /= 10;
    }
    return result;
}

int main()
{
    uint64_t count = 0;
    for(uint64_t i = 2; i < 10000000; i++)
    {
        uint64_t temp = i;
        while(temp != 1 && temp != 89)
        {
            temp = nextChain(temp);
            if(temp == 89)
            {
                count++;
            }
        }
    }
    std::cout << count + 1 << "\n";
}
