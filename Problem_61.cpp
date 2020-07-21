#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> check(int a, std::vector<int> b)
{
    std::vector<int> numbers;
    for(auto i : b)
    {
        if(i == a)
        {
            int temp = a % 100 * 100 + 10;
            if(temp > 1000)
            {
                for(int c = temp; c < temp + 90; c++)
                {
                    numbers.push_back(c);
                }
            }
        }
    }
    return numbers;
}

bool checkAll(int i, std::array<std::vector<int>, 6> numbers)
{
    std::vector<int> one = check(i, numbers[0]);
    for(auto j : one)
    {
        std::vector<int> two = check(j, numbers[1]);
        for(auto k : two)
        {
            std::vector<int> three = check(k, numbers[2]);
            for(auto l : three)
            {
                std::vector<int> four = check(l, numbers[3]);
                for(auto m : four)
                {
                    std::vector<int> five = check(m, numbers[4]);
                    for(auto n : five)
                    {
                        std::vector<int> six = check(n, numbers[5]);
                        for(auto o : six)
                        {
                            if(o == i)
                            {
                                std::cout << "\n" << i << " : " << j << " : " << k << " : " << l << " : " << m << " : " << n << " : " << o;
								std::cout << "\nSum = " << i + j + k + l + m + n;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}


int main()
{
    std::vector<int> a, b, c, d, e, f;
    int temp = 0;
    int result = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * (temp + 1) / 2;
        a.push_back(result);
    }
    result = 0;
    temp = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * temp;
        b.push_back(result);
    }
    temp = 0;
    result = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * (3 * temp - 1) / 2;
        c.push_back(result);
    }
    temp = 0;
    result = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * (2 * temp - 1);
        d.push_back(result);
    }
    temp = 0;
    result = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * (5 * temp - 3) / 2;
        e.push_back(result);
    }
    temp = 0;
    result = 0;
    while(result < 10000)
    {
        temp++;
        result = temp * (3 * temp - 2);
        f.push_back(result);
    }
	std::array<std::vector<int>, 6> numbers{a, b, c, d, e, f};

	auto compare = [](const std::vector<int>& lhs, const std::vector<int>& rhs)
    { return &lhs[0] < &rhs[0]; };

	std::sort(numbers.begin(), numbers.end(), compare);
	do{
		for(int i = 1010; i < 9999; i++)
		{
			if(checkAll(i, numbers))
			{
				return 0;
			}
		}
	} while(std::next_permutation(numbers.begin(), numbers.end(), compare));
