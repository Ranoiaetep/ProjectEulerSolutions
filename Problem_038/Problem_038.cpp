#include <iostream>
#include <string>
#include <algorithm>

struct pan
{
    long long s;
    bool b;
};

pan isPandigit(int number)
{
    std::string result = "";
    for(int i = 1; result.size() < 9; i++)
    {
        result += std::to_string(number * i);
    }
    long long temp = std::stoll(result);
    std::sort(result.begin(), result.end());
    return { temp, result == "123456789"};
}

int main()
{
    long long max = 0;
    for(int i = 9; i < 10000; i++)
    {
        auto p = isPandigit(i);
        if (p.b) {
            if(p.s > max)
            {
                max = p.s;
            }
        }
    }
    std::cout << max << "\n";
}
