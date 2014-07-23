#include <iostream>
#include <cassert>
#include <vector>
#include <limits>
#include <cmath>


bool close(double lhs, double rhs)
{
    return std::fabs(lhs - rhs) < std::numeric_limits<double>::epsilon();
}

class Rect
{public:
    Rect(double x1, double y1, double x2, double y2, unsigned int nth)
        :m_x1(x1),  m_y1(y1),  m_x2(x2),  m_y2(y2),  m_nth(nth)
        {}
    double nth() const {return m_nth;}
    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;
    unsigned int m_nth;
    bool contains(double x, double y) const
    {
        return x >= m_x1 && y <= m_y1 &&
               x <= m_x2 && y >= m_y2;
    }
};

int main(int argc, char** argv)
{
    std::vector<Rect> rects;
    char c;
    double x1, y1, x2, y2;
    int nth_r = 1;
    while(std::cin >> c)
    {
        if(c == '*')
            break;
        std::cin >> x1 >> y1 >> x2 >> y2;
        rects.push_back(Rect(x1, y1, x2, y2, nth_r++));
    }

    double x, y;
    unsigned int nth_p = 0;
    while(std::cin >> x >> y)
    {
        if(close(x, 9999.9) && close(y, 9999.9))
            break;
        nth_p++;
        bool in_any = false;
        for(const auto& rect: rects)
        {
            if(!rect.contains(x, y))
                continue;
            in_any = true;
            std::cout << "Point " << nth_p 
                      << " is contained in figure " << rect.nth() << "\n";
        }
        if(!in_any)
            std::cout << "Point " << nth_p << " is not contained in any figure\n";
    }
    return 0;
}
