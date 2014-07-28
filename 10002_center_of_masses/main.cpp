#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    int n;
    while(std::cin >> n)
    {
        if(n < 3)
            break;
        int x_sum = 0, y_sum = 0;
        int x, y;
        for(int i=0;i<n;i++)
        {
            std::cin >> x >> y;
            x_sum += x;
            y_sum += y;
        }
        double mp_x = double(x_sum) / n;
        double mp_y = double(y_sum) / n;
        std::cout << std::setprecision(3) << std::fixed 
                  << mp_x << " "
                  << mp_y << std::endl;
    }
    
    return 0;
}
