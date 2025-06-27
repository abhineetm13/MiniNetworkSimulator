#ifndef CANVAS_H
#define CANVAS_H

#include "shapepp.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Canvas {
    std::vector<Shape*> shapes;
    unsigned int XM, YM;

public:
    Canvas(unsigned int xdim, unsigned int ydim);
    int addShape(Shape* s);
    int displayCanvas();
};

#endif