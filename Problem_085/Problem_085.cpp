#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

uint64_t countSquares(int i, int j)
{
	uint64_t sum = 0;
	for(int a = 1; a <= i; a++)
	{
		for(int b = 1; b <= j; b++)
		{
			sum += (a * b);
		}
	}
	return sum;
}

int main() {
	std::vector<std::tuple<uint64_t, int, int>> max;
	for(int i = 1; i < 1415; i++)
	{
		for(int j = 1; j < 1415; j++)
		{
			uint64_t number = countSquares(i, j);
			if(number > 2000000)
			{
				uint64_t temp = countSquares(i, j-1);
				max.push_back({temp, i, j-1});
				break;
			}
		}
	}
	auto compare = [](const std::tuple<uint64_t, int, int>& lhs, const std::tuple<uint64_t, int, int>& rhs)
    { return std::get<0>(lhs) < std::get<0>(rhs); };
	auto it = std::max_element(max.begin(),max.end(),compare);
	std::cout << std::get<1>(*it) * std::get<2>(*it);
}
