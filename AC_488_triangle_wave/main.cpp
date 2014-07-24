#include <iostream>

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    while(n--)
    {
        int a, f;
        std::cin >> a >> f;
        while(f--)
        {
            bool back = false;
            for(int c=1; c!=0; back?c--:c++)
            {
                for(int i=0;i<c;i++) 
                    std::cout << c;
                std::cout << "\n";
                back = (c == a) ? true: back;
            }
            if(!(n==0 && f==0))
                std::cout << "\n";
        }
    }
    std::cout << std::flush;
    return 0;
}
