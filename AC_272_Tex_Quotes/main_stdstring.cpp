#include <iostream>
#include <string>

int main()
{
    bool close = true;
    std::string buffer;
    std::string output;
    while(getline(std::cin, buffer))
    {
        for(const auto src_char: buffer)
        {
            if(src_char != '\"')
            {
                output += src_char;
            }
            else if(close) // ``, left "
            {
                output += "``";
                close = false;
            }
            else // '', right "
            {
                output += "''";
                close = true;
            }
        }
        std::cout << output << "\n";
        output.clear();
    }
    std::cout << std::flush;
    return 0;
}
