#pragma once

#include <algorithm>

namespace geo
{


template<class CoorT>
struct Point
{
    enum AXIS{X, Y};
    CoorT x;
    CoorT y;
};

template<class CoorT>
struct Line
{
    Point<CoorT> p1;
    Point<CoorT> p2;
};

}
