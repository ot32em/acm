#pragma once

#include <algorithm>

namespace geo
{


template <typename PointT>
class AxisX
{
    AxisSel(const PointT&)
    

template<class CoorT>
struct Point
{
    CoorT x;
    CoorT y;
};

template<class CoorT>
struct Line
{
    Point<CoorT> p1;
    Point<CoorT> p2;

    template <typename Comp, typename AxisSel>
    CoorT bound() const{
        return Comp(AxisSel(p).value(), AxisSel(p).value()).value();
    }
};

line.bound<x>.max();

}
