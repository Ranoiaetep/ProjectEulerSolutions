#include <iostream>
#include <vector>
#include <chrono>
#include <set>

int testMax = 100000;

void initPrime(std::vector<int> &prime)
{
    const uint64_t max = testMax;
    std::vector<uint64_t> numberMax(max);
    std::fill(numberMax.begin(), numberMax.end(), 1);

    for (uint64_t factor = 2 ; factor < max / 2 ; factor++)
    {
        for (uint64_t mult = 2 ; factor * mult < max ; mult++)
        {
            numberMax[factor * mult] += factor;
        }
    }
    uint64_t count = 0;
    for(size_t i = 2; i < max; i++)
    {
        if(numberMax[i] == 1)
        {
            count++;
            prime.push_back(static_cast<int>(i));
        }
    }
    std::cout << "Total primes: " << count << "\n\n";
}

struct radical
{
    int rad;
    int index;
};

int getRad(std::vector<int> &prime, int number)
{
    int result = 1;
    std::set<int> factors;
    for(int i = 0; number != 1; i++)
    {
        if(number % prime[i] == 0)
        {
            number /= prime[i];
            factors.emplace(prime[i]);
            i--;
        }
    }
    for(auto &i : factors)
    {
        result *= i;
    }
    return result;
}

int main() {
    std::vector<int> prime;
    initPrime(prime);
    std::vector<radical> rads;
    for(int i = 1; i <= testMax; i++)
    {
        rads.push_back({getRad(prime, i), i});
    }
    std::sort(rads.begin(), rads.end(), [](radical a, radical b) {
        bool result;
        (a.rad == b.rad) ? (result = a.index < b.index) : (result =  a.rad < b.rad);
        return result;
    });
    //for(auto &i : rads)
    {
        //std::cout << i.index << " : " << i.rad << "\n";
    }
    std::cout << rads[10000 - 1].index << " : " << rads[10000 - 1].rad << "\n";
}
