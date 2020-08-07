#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <iterator>
#include <algorithm>

uint64_t testMax = 1000000;

void initPrime(std::vector<uint64_t> &prime)
{
    auto startTime = std::chrono::steady_clock::now();
    std::cout << "allocation done";
    auto finishTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration = finishTime - startTime;
    std::cout << ", used: " << duration.count() << "\nTimer starts.\n";
    startTime = std::chrono::steady_clock::now();

    for (uint64_t factor = 2 ; factor * 2 < prime.size() ; factor++)
    {
        for (uint64_t mult = factor ; factor * mult < prime.size() ; mult++)
        {
            prime[factor * mult]++;
        }
    }
    uint64_t count = 0;
    for(size_t i = 2; i < prime.size(); i++)
    {
        if(prime[i] == 1)
        {
            count++;
            //std::cout << count << "\t" << i << "\n";
        }
    }
    std::cout << "\nTotal: " << count << "\n";
    finishTime = std::chrono::steady_clock::now();
    duration = finishTime - startTime;
    std::cout << "\nDuration: " << duration.count() << "\n";
}

int main()
{
    const uint64_t max = testMax;
    std::vector<uint64_t> numberMax(max);
    std::fill(numberMax.begin(), numberMax.end(), 1);
    initPrime(numberMax);
    std::vector<int> prime;
    for(int i = 0; i < max; i++)
    {
        if(numberMax[i] == 1 && i >= 2)
        {
            prime.push_back(i);
        }
    }
    int maxLength = 0;
    for(auto it = prime.begin(); it != prime.end() - 1; it++)
    {
        for (auto it2 = it + 1; it2 != prime.end(); it2++) {
            int sum = std::accumulate(it, it2, 0);
            if(sum > max)
            {
                break;
            }
            if(sum < max && numberMax[sum] == 1)
            {
                maxLength = std::max(maxLength, static_cast<int>(std::distance(it, it2)));
                if(maxLength == static_cast<int>(std::distance(it, it2)))
                std::cout << maxLength << " : " << sum << " : " << *it << "~" << *it2 <<"\n";
            }
        }
    }
    std::cout << "\n\n" << maxLength << "\n";
}
