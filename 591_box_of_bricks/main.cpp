#include <iostream>
#include <array>
#include <numeric>

int main(int argc, char** argv)
{
    int n;
    int n_th = 1;
    while(std::cin >> n)
    {
        if(!n)
            break;
        std::array<int, 50> b = {};
        if(n_th !=1)
            std::cout << std::endl;
        for(int i=0;i<n;i++)
            std::cin >> b[i];
        const auto avg = std::accumulate(b.begin(), b.begin() + n, 0) / n;
        const auto mov = std::accumulate(b.begin(), b.begin() + n, 0,
            [avg](int init, int n){
                return init + abs(n-avg);

            }
        );
        std::cout << "Set #" << n_th++ << std::endl;
        std::cout << "The minimum number of moves is " << mov/2 << "." <<std::endl;
        
    }
    
    return 0;
}
