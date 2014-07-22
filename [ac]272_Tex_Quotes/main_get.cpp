#include <iostream>

int main(int argc, char** argv)
{
    bool closed = true;
    char buffer;
    std::cin.tie(nullptr);
    while(std::cin.get(buffer))
    {
        if(buffer != '"')
        {
            std::cout.put(buffer);
        }
        else if(closed)
        {
            std::cout.put('`');
            std::cout.put('`');
            closed = false;
        }
        else
        {
            std::cout.put('\'');
            std::cout.put('\'');
            closed = true;
        }
    }
    std::cout << std::flush;
    return 0;

}
