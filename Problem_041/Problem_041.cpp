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

int main() {
    for(char a = /*'9'*/ '7'; a > '0'; a--)
    {
        std::string number = "";
        for (char b = a; b > '0'; b--) {
            number += b;
        }
        do
        {
            if(isPrime(std::stoll(number)))
            {
                std::cout << number << "\n";
                return 0;
            }
        }
        while (std::next_permutation(number.begin(), number.end(), std::greater<char>()));
    }
}
