#include <iostream>

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    char buffer;
    while(std::cin.get(buffer))
        std::cout.put(buffer=='\n'?buffer:buffer-7);
    return 0;
}
