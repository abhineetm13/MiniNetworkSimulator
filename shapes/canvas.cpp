#include "canvas.h"

// Constructor
// xdim and ydim are the dimensions of the canvas
Canvas::Canvas(unsigned int xdim, unsigned int ydim): XM(xdim), YM(ydim) {}

// function to add a shape to the canvas
int Canvas::addShape(Shape* s) {
    this->shapes.push_back(s);
    return 0;
}

// displays all the shapes in the canvas
int Canvas::displayCanvas() {
    sf::RenderWindow window(sf::VideoMode({this->XM, this->YM}), "Canvas");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (size_t i = 0; i < this->shapes.size(); i++) {
            shapes[i]->displayShape(window);
        }

        window.display();
    }
    return 0;
}
