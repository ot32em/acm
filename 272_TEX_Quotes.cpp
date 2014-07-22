#include <iostream>
#include <array>
#include <sstream>

const unsigned int BUFFER_SIZE = 4096;

int main()
{
    std::string input_str = 
"\"To be or not to be,\" quoth the Bard, \"that is the question\".\n"
"The programming contestant replied: \"I must disagree."
"To `C' or not to `C', that is The Question!\"";
    std::istringstream input(input_str);
    
    std::istream& in = input;
    
    std::array<char, BUFFER_SIZE> buffer = {};
    std::array<char, BUFFER_SIZE> output = {};
    while(in.getline(buffer.data(), BUFFER_SIZE))
    {
        bool close = true;
        const char* src_ptr = buffer.data();
        char* dst_ptr = output.data();
        while(*src_ptr != '\0')
        {
            if(*src_ptr != '\"') // content char
            {
                *dst_ptr++ = *src_ptr;
            }
            else if(close) // ``
            {
                *dst_ptr++ = '`';
                *dst_ptr++ = '`';
                close = false;
            }
            else // ''
            {
                *dst_ptr++ = '\'';
                *dst_ptr++ = '\'';
                close = true;
            }
            src_ptr++;
        }
        std::cout << output.data() << "\n";
    }
    std::cout << std::flush;
   
   return 0;
}
