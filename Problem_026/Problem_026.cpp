#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::pair<size_t, int>> length;
    for(int i = 1; i < 5000; i++)
    {
        std::vector<std::pair<int, int>> pairs;
        //std::cout << "\n" << i << ": ";
        std::div_t qr = {0, 0};
        int temp = 10;
        do
        {
            qr = std::div(temp, i);
            std::pair<int, int> pair = std::make_pair(qr.quot, qr.rem);
            if(std::find(pairs.begin(), pairs.end(), pair) == pairs.end())
            {
                //std::cout << quotient << ", ";
                pairs.push_back(pair);
            }
            else
            {
                break;
            }
            temp = qr.rem * 10;
        }
        while(qr.rem != 0);
        length.emplace_back(std::pair<size_t, int>(pairs.size(),i));
        if(i % 1000 == 0) std::cout << i << "\n";
    }
    auto it = std::max_element(length.begin(), length.end());
    std::cout << "\n\n" << it-> first + 1 << " : " << it -> second - 1 << "\n";
}
