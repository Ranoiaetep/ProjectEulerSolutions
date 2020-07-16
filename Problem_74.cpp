#include <iostream>
#include <cmath>
#include <string>
////#include <algorithm>
#include <vector>

int fact(int n)
{
    int result = 1;
    while(n)
    {
        result *= n;
        n--;
    }
    return result;
}

int digitFactSum(int n)
{
    int result = 0;
    while(n)
    {
        result += fact(n % 10);
        n /= 10;
    }
    //std::cout << result;
    return result;
}

int main() {
    int countTotal = 0;
    for(int i = 10; i < 1000000; i++)
    {
        int count = 0;
        int temp = i;
        std::vector<int> numbers;
        numbers.push_back(temp);
        do
        {
            temp = digitFactSum(temp);
            numbers.push_back(temp);
            count++;
            if(temp == i)
            {
                break;
            }
        }while (temp != 169 && temp != 363601 && temp != 1454 && temp != 871 && temp != 45361 && temp != 872 && temp != 45362 && temp > 2 && temp != 145 && temp != 40585);
        if(count > 56)
        {
            //for(auto i : numbers)
            {
                //std::cout << i << " -> ";
            }
            //std::cout << "\n\n";
            if(count > 56)
                countTotal++;
        }
    }
    std::cout << countTotal;
}