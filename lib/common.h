struct Point
{
    double x;
    double y;

    bool operator<(const Point& lhs) const { 
        return x==lhs.x? y < lhs.y; x < lhs.x;
    }
};

struct Line
{
    Point src;
    Point dst;
};
