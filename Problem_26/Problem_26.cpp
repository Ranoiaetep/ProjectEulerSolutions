#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<size_t> length;
    for(int i = 1; i < 10; i++)
    {
        std::vector<std::pair<int, int>> pairs;
        std::cout << "\n" << i << ": ";
        int remainder = 0;
        int temp = 10;
        do
        {
            int quotient = temp / i;
            remainder = temp % i;
            std::pair<int, int> pair = std::make_pair(quotient, remainder);
            if(std::find(pairs.begin(), pairs.end(), pair) == pairs.end())
            {
                std::cout << quotient << ", ";
                pairs.push_back(pair);
            }
            else
            {
                break;
            }
            temp = remainder * 10;
        }
        while(remainder != 0);
        length.push_back(pairs.size());
    }
    std::cout << "\n\n" << std::max_element(length.begin(), length.end()) - length.begin() + 1 << "\n";
}
