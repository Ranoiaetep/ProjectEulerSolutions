#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>


bool isPandigit(uint64_t number)
{
    std::string result = std::to_string(number);
    std::sort(result.begin(), result.end());
    return result == "123456789";
}

int main()
{
    uint64_t aHead = 0, aTail = 0;
    uint64_t bHead = 1, bTail = 1;
    bool run = true;
    uint64_t count = 0;
    float log = 0;
    uint64_t base = 10;
    while (run) {
        aHead += bHead;
        std::swap(aHead, bHead);
        aTail += bTail;
        std::swap(aTail, bTail);
        if(aHead > 1000000000 * base)
        {
            aHead /= 10;
            bHead /= 10;
        }
        if(aTail > 1000000000)
        {
            aTail %= 1000000000;
            bTail %= 1000000000;
        }
        count++;
        if (count > base/10) {
            log++;
            base *= 10;
        }
        if(isPandigit(aHead/base) && isPandigit(aTail % 1000000000))
        {
            run = false;
        }
    }
    std::cout << count << "\n";
    
    return 0;
}
