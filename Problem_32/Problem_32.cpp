#include <iostream>
#include <algorithm>
#include <set>

bool isPandigital(int a, int b)
{
    int product = a * b;
    int count = 0;
    std::set<int> digits;
    while(a)
    {
        count++;
        digits.emplace(a % 10);
        a /= 10;
    }
    while(b)
    {
        count++;
        digits.emplace(b % 10);
        b /= 10;
    }
    while(product)
    {
        count++;
        digits.emplace(product % 10);
        product /= 10;
    }
    if(count == 9 && digits.size() == 9 && *digits.begin() == 1)
    {
        return true;
    }
    return false;
}

int main()
{
    std::set<int> products;
    for(int x = 1; x < 100; x++)
    {
        for(int y = 1; y < 10000; y++)
        {
            if(isPandigital(x, y))
            {
                std::cout << x << " * " << y << " = " << x * y << "\n";
                products.insert(x * y);
            }
        }
    }
    int sum = 0;
    for(auto a : products)
    {
        sum+= a;
    }
    std::cout << "\n" << sum << "\n";
}
