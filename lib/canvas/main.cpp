#include "canvas.h"

int main(int argc, char** argv)
{
    geo::Canvas canvas;
    canvas.add_line(0, 20, 63,8);
    canvas.add_line(63, 8, 0,0);
    canvas.add_line(0, 0, 0,20);
    canvas.display();

    return 0;
};
