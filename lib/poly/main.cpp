#include <iostream>
#include <vector>
#include "../common/geo.h"

#include "view_graph.h"


int main(int argc, char** argv)
{
    std::vector<Line> lines = {
        {{0,0}, {0,5}},
        {{0,5}, {5,5}},
        {{5,5}, {3,8}},
        {{3,8}, {5,0}},
        {{5,0}, {0,0}},
    };

    Graph g;
    for(const auto& line: lines)
        g.add(line);
    g.show();

    return 0;
}
