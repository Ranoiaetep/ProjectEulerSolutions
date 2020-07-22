#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>


bool isPrime(uint64_t number)
{
    if(!(number % 2))
        return false;
    if(number % 2)
    {
        for(int i = 3; number / i > i; i+=2)
        {
            if(!(number % i))
                return false;
        }
    }
    return true;
}


int main()
{
    std::vector<std::tuple<int, int, int>> length;
    for(int a = -999; a < 1000; a++)
    {
        for(int b = -999; b < 1000; b++)
        {
            int count = 0;
            for(int n = 0; ; n++)
            {
                int temp = n * n + a * n + b;
                if(temp > 0)
                {
                    if(isPrime(temp))
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            length.push_back({count, a, b});
        }
    }
    auto compare = [](const std::tuple<int, int, int>& lhs, const std::tuple<int, int, int>& rhs)
    { return std::get<0>(lhs) < std::get<0>(rhs); };
    auto max = *std::max_element(length.begin(), length.end(), compare);
    std::cout << std::get<1>(max) * std::get<2>(max);
}
