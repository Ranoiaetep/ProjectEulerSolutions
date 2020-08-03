#include <iostream>
#include <set>

bool isPalin(long long n, int base)
{
    long long reversed = 0;
    long long temp = n;
    while(temp)
    {
        reversed = reversed * base + temp % base;
        temp /= base;
    }
    return n == reversed;
}


int main() {
    std::set<long long> total;
    long long sum = 0;
    for(int i = 1; i <= 8000; i++)
    {
        sum += i * i;
        for(int j = i + 1; j <= 8000; j++)
        {
            sum += j * j;
            if(isPalin(sum, 10) && sum < 100000000)
            {
                std::cout << i << " : " << j << " = " << sum << "\n";
                total.emplace(sum);
            }
        }
        sum = 0;
    }
    long long result = 0;
    for(auto i : total)
    {
        result += i;
    }
    std::cout << "\n" << result << "\n";
}
