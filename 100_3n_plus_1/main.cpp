#include <iostream>
#include <array>
typedef unsigned long long int_t;
            
int main(int argc, char** argv)
{
    std::array<int_t, 1000000> cache = {}; // all reset to 0
    int_t lhs, rhs;
    while(std::cin >> lhs >> rhs)
    {
        const auto min_n = std::min(lhs, rhs); 
        const auto max_n = std::max(lhs, rhs);
        int_t max_cycles = 1;
        for(auto i = min_n; i <= max_n; i++)
        {
            if(cache[i] == 0)
            {
                int_t cycles = 1;
                for(int_t n = i; n != 1; cycles++)
                    n = n%2?(3*n+1):(n>>1);
                cache[i] = cycles;
            }
            max_cycles = std::max(max_cycles, cache[i]);
        }
        std::cout << lhs << " " << rhs << " " << max_cycles << "\n";
    }
    std::cout << std::flush;
    return 0;
}
