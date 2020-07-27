#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


int nextChain(int number)
{
    int sum = 1;
    int factor = 2;
    std::div_t div = {number,0};
    for (; div.quot >= factor; ++factor)
    {
        div = std::div(number, factor);
        if (!div.rem)
        {
            //std::cout << factor << "," << div.quot << ",";
            sum += factor + div.quot;
        }
    }
    return sum;
}


int main()
{
    int maxStep = 0;
    int maxValue = 0;
    for(int i = 1; i < 1000000; i++)
    {
        int step = 0;
        int root = i;
        std::vector<int> chain;
        chain.emplace_back(root);
        do
        {
            root = nextChain(root);
            if (root > 1000000)
            {
                goto next;
            }
            chain.emplace_back(root);
            step++;
        }while(std::find(chain.begin(), chain.end(), root) == (chain.end()-1));
        if(*chain.begin() == *(chain.end()-1))
        {
            if (step > maxStep)
            {
                maxStep = step;
                maxValue = root;
                std::cout << maxValue << " : " << maxStep << "\n";
            }
        }
        next:
        ;
    }
}
