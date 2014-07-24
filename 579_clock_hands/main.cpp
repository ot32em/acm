#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    std::string buf;
    while(getline(std::cin, buf))
    {
        if(buf=="0:00")
            break;
        auto pos = buf.find(":");
        int h = std::stoi(buf.substr(0,pos));
        pos++;
        int m = std::stoi(buf.substr(pos, buf.size() - pos));
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
