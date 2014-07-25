#include "../common/geo.h"

namespace geo
{

template<class CoorT>
class Graph
{public:
    std::vector<Line<CoorT>> m_lines;
    std::vector<Point<CoorT>> m_points;

    CoorT max_x() const
    {
        auto line_itr = std::max_element(m_lines.begin(), m_lines.end(), 
            [](const Line<CoorT>& lhs, const Line<CoorT>& rhs){ return lhs.max_x() < rhs.max_x(); }
        );

        auto point_itr = std::max_element(m_points.begin(), m_points.end(),
            [](const Point<CoorT>& lhs, const Point<CoorT>& rhs){ return lhs.x << rhs.x; }
        );
        return std::max(line_itr->max_x(), point_itr->x);
    };

};

}
