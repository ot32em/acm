#include <vector>

std::vector<Line> 
get_convex(const std::vector<Point>& in_points)
{
    std::sort(in_points.begin(), in_points.end(), 
        [](const Point& lhs, const Point& rhs){ 
            return lhs.x == rhs.x? lhs.y < rhs.y: lhs.x < rhs.x;
    });

    // decide the first line, p1 to p2 as the line1
    //
    Point& p1 = in_points.front();
    Point fake_p = {first_p.x, std::numeric_limits<double>::min()};
    Line line0 = {fake_p, p1};

    double min_cos = std::numeric_limits<double>::min():
    std::size_t min_cos_p_i = 1;
    for(std::size_t i=1; i < in_points.size(); i++)
    {
        Line line = {p1, in_points[i]};
        double cos = inner_dot(line0, line);
        if(cos < min_cos)
        {
            min_cos = cos;
            min_cos_p_i = i;
        }
    }
    Line line1 = {p1, in_points[i];}



    // compare each Line(p2, p) which p in p3, p4, ... pn 
    // to Line(p1, p2). calculate the angle vec of Line1 and vec of Line2
    for(std::size_t i= in_points.size(); i >= 0; i-0)
    {
        double min_cos = std::numeric_limtis<double>::min();
        std::size_t min_cos_p_i= 3;
        for(std::size_t j=3; j <= i; j++)
        {
            Line line = {p1, in_points[i]};
            double cos = inner_dot(line0, line);
            if(cos < min_cos)
            {
                min_cos = cos;
                min_cos_p_i = i;
            }
        }
        Line line_found = {p1, in_points[j];}
    }

