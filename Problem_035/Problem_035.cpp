#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>

struct next
{
    int i;
    bool b;
};

next nextRotation(size_t base)
{
    std::string sNumber = std::to_string(base);
    char c = sNumber[0];
    sNumber.erase(0, 1);
    sNumber.push_back(c);
    if(sNumber[0] == '0')
    {
        return {0, false};
    }
    return {std::stoi(sNumber), true};
}


bool testCircle(size_t number, std::vector<uint64_t> & primes)
{
    auto temp = nextRotation(number);
    while(temp.i != number)
    {
        if(!temp.b)
        {
            return false;
        }
        if(primes[temp.i] != 1)
        {
            return false;
        }
        temp = nextRotation(temp.i);
    }
    //std::cout << "\n";
    return true;
}

int testMax = 1000000;

int main() {
    int circleCount = 0;
    auto startTime = std::chrono::steady_clock::now();
    const uint64_t max = testMax;
    std::vector<uint64_t> numberMax(max);
    std::fill(numberMax.begin(), numberMax.end(), 1);
    std::cout << "allocation done";
    auto finishTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration = finishTime - startTime;
    std::cout << ", used: " << duration.count() << "\nTimer starts.\n";
    startTime = std::chrono::steady_clock::now();

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
            if (testCircle(i, numberMax)) {
                circleCount++;
                std::cout << i << "\n";
            }
            //std::cout << count << "\t" << i << "\n";
        }
    }
    std::cout << "\nTotal: " << circleCount << "\n";
    finishTime = std::chrono::steady_clock::now();
    duration = finishTime - startTime;
    std::cout << "\nDuration: " << duration.count() << "\n";
}
