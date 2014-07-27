#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <list>
#include "../common.h"

std::vector<Line> 
get_convex(const std::vector<Point>& in_points)
{
    if(in_points.size() < 3)
        throw std::invalid_argument("Convex needs at least 3 points.");

    std::vector<Point> sorted_points = in_points;
    std::sort(sorted_points.begin(), sorted_points.end(), 
        [](const Point& lhs, const Point& rhs){ 
            return lhs.x == rhs.x? lhs.y < rhs.y: lhs.x < rhs.x;
    });
    std::list<Point> points(sorted_points.begin(), sorted_points.end());

    Point curr_p = points.front();
    points.pop_front();
    Point prev_p = {curr_p.x, curr_p.y-1};
    
    for(Line ref_l = {prev_p, curr_p}; 
        points.empty(); 
        ref_l = {prev_p, curr_p})
    {
        auto selected_p_iter = points.begin();
        double min_cos = std::numeric_limits<double>::max();
        for(auto p_iter = points.begin(); p_iter != points.end(); p_iter++)
        {
            Line finding_l {curr_p, *p_iter};
            double cos = ref_l.vec().x * finding_l.vec().x + 
                         ref_l.vec().y * finding_l.vec().y;
            if(cos < min_cos)
            {
                min_cos = cos;
                selected_p_iter = p_iter;
            }
        }
        prev_p = curr_p;
        curr_p = *selected_p_iter;
        points.erase(selected_p_iter);
    }


}

    // decide the first line, p1 to p2 as the line1

