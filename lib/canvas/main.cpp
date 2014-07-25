#include "canvas.h"

int main(int argc, char** argv)
{
    geo::Canvas canvas;
    canvas.add_line(0, 20, 33,8);
    canvas.add_line(33, 8, 0,0);
    canvas.add_line(0, 0, 0,20);
    canvas.add_point(10, 10);
    canvas.display();

    return 0;
};
