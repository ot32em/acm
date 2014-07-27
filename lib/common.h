struct Point
{
    double x;
    double y;

    bool operator<(const Point& lhs) const { 
        return (x == lhs.x)? (y < lhs.y): (x < lhs.x);
    }
};

typedef Point Vector;

struct Line
{
    Point src;
    Point dst;
    Vector vec() const { return {dst.x - src.x, dst.y - src.y};}
};
