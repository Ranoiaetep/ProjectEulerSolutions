#include <iostream>
#include <cstdint>

uint64_t largeMod(uint64_t base, uint64_t exponent, uint64_t mod)
{
    uint64_t temp = 1;
    for(uint64_t i = 1; i <= exponent / 2; i++)
    {
        temp *= base;
        temp %= mod;
    }
    temp = temp * temp % mod;
    if(exponent % 2)
    {
        return base * temp % mod;
    }
    return temp;
}

int main()
{
    uint64_t lastTen = 1;
    //  for (uint64_t i = 1; i <= 7830457; i++) {
    //      lastTen <<= 1;
    //      lastTen %= 10000000000;
    //  }
    lastTen =     largeMod(lastTen, 2, 10000000000);
    lastTen = (lastTen * 28433 + 1) % 10000000000;
    std::cout << lastTen << "\n";
    return 0;
}
