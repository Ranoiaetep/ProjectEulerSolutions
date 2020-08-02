#include <iostream>
#include <string>
#include <algorithm>

bool isPandigit(std::string sNumber)
{
    std::sort(sNumber.begin(), sNumber.end());
    return sNumber == "0123456789";
}

bool threeDigitDivisble(std::string sNumber, int startIndex, int denom)
{
    std::string temp = sNumber.substr(startIndex, 3);
    return std::stoi(temp) % denom == 0;
}

int main()
{
    int prime[7] = {2,3,5,7,11,13,17};
    std::string s = "1023456789";
    long long sum = 0;
    do
    {
        int passes = 0;
        for(int i = 0; i < 7; i++)
        {
            if(threeDigitDivisble(s, i + 1, prime[i]))
            {
                passes++;
            }
        }
        if(passes == 7)
        {
            std::cout << s << "\n";
            sum += std::stoll(s);
        }
    }while(std::next_permutation(s.begin(), s.end()));
    std::cout << "\n\n" << sum << "\n";
}
