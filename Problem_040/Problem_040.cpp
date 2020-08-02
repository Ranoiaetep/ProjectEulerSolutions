#include <iostream>
#include <string>

int main()
{
    std::string result = "";
    for(int i = 0; i <= 1000000; i++)
    {
        result += std::to_string(i);
    }
    int product = 1;
    for(int i = 1; i <= 1000000; i *= 10)
    {
        product *= result[i] - '0';
    }
    std::cout << product << "\n";
}
