#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    int w=0;
    bool s=true;
    char c;
    while(std::cin.get(c))
    {
        if(std::isalpha(c))
        {
            if(s)
            {
                w++;
            }
            s=false;
        }
        else
        {
            if(c=='\n')
            {
                std::cout << w << "\n";
                w=0;
            }
            s=true;
        }
    }
    
    return 0;
}
