#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

inline int toi(char c){ return c - '0'; }

int main(int argc, char** argv)
{
    char buf[10] = {};
    while(std::cin.getline(buf, 10))
    {
        if(strcmp(buf, "0:00") == 0)
            break;
        bool one_digit = buf[1]==':';
        int h = toi(buf[1-one_digit]);
        if(!one_digit)
            h += toi(buf[0]) * 10;
        int m = toi(buf[3-one_digit]) * 10 + toi(buf[4-one_digit]);

//        std::cout << "h: " << h << " m: " << m << std::endl;

        int h_steps = h * 60 + m;
        int m_steps = m * 12;
        double diff_steps = (720 + h_steps - m_steps) % 720;
        diff_steps = std::min(720 - diff_steps, diff_steps);
        double diff_angles = diff_steps / 2;
        diff_angles = std::min(diff_angles, 360 - diff_angles);
        std::cout << std::setprecision(3) << std::fixed << diff_angles << std::endl;
    }
    
    return 0;
}
