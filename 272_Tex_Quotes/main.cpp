#include <iostream>
#include <string>

int main()
{
    bool close = true;
    std::string buffer;
    while(getline(std::cin, buffer))
    {
        std::string output;
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
    }
    std::cout << std::flush;
   return 0;
}
