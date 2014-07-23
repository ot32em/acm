#include <iostream>
#include <vector>


int get_number(const std::string& str)
{
    auto point_pos = str.find(".");
    if(point_pos != std::string::npos)
    {
        // left side
        int n = std::stoi(str.substr(0, point_pos));
        int dec_n_pos = point_pos + 1;
        int dec_n = std::stoi(str.substr(dec_n_pos, 1));
        return n*10 + dec_n;
    }
    return std::stoi(str) * 10;
}


struct Point
{
    int x;
    int y;
    Point(const std::string& sx, const std::string& sy)
        :x(get_number(sx)), y(get_number(sy)){}
    bool right_has(const Point& p) const { return p.x >= x; }
    bool left_has(const Point& p) const { return p.x <= x; }
    bool down_has(const Point& p) const { return p.y <= y; }
    bool top_has(const Point& p) const { return p.y >= y; }
};

struct Rect
{
    Point left_top;
    Point right_buttom;
    bool contains(const Point& p) const
    {
        return left_top.right_has(p) && left_top.down_has(p) 
            && right_buttom.left_has(p) && right_buttom.top_has(p);
    }
};

int main(int argc, char** argv)
{
    // read rectangles
    std::vector<Rect> rects;
    char c;
    std::string sx1, sy1, sx2, sy2;
    while(std::cin >> c)
    {
        if(c == '*')
            break;
        std::cin >> sx1 >> sy1 >> sx2 >> sy2;
        Rect rect = {Point(sx1, sy1), Point(sx2, sy2)};
        rects.push_back(rect);
    }

    // read points and test
    std::string sx, sy;
    unsigned int nth_p = 0;
    while(std::cin >> sx >> sy)
    {
        // read point
        if(sx == "9999.9" && sy == "9999.9")
            break;
        Point p(sx, sy);
        nth_p++;

        // test contained in rect one by one
        int nth_r = 0;
        bool in_any = false;
        for(const auto& rect: rects)
        {
            nth_r++;
            if(!rect.contains(p))
                continue;
            in_any = true;
            std::cout << "Point " << nth_p 
                      << " is contained in figure " << nth_r << "\n";
        }
        if(!in_any)
            std::cout << "Point " << nth_p 
                      << " is not contained in any figure\n";
    }
    return 0;
}
