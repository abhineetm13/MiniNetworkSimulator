#include <assert.h>
#include <math.h>
#include <memory>
#include "shapepp.h"
#include "ellipseshape.h"

// default centre is at (0, 0) and default color is green
Shape::Shape() :
    shapeID(-1), cx(0), cy(0), color({0, 255, 0}) {}

// returns the shape ID of the shape
int Shape::getShape() {
    return this->shapeID;
}

// returns true if the shape is of class square, false otherwise
bool Shape::isSquare() {
    return (this->shapeID == 1);
}

// function to set the shape's color by (r, g, b) value
int Shape::setColor(int r, int g, int b) {
    this->color = {r, g, b};
    this->shape_element->setFillColor(sf::Color(r, g, b));
    return 0;
}

// returns the (r, g, b) color of the shape
std::tuple<int, int, int> Shape::getColor() {
    return this->color;
}

// function to display the shape in a sfml window
int Shape::displayShape(sf::RenderWindow &c) {
    c.draw(*this->shape_element);
    return 0;
}

// returns the coordinates of the centre of the shape
std::pair<int, int> Shape::Coordinates() {
    return {this->cx, this->cy};
}

// functions to set the centre coordinates of the shape
// returns the updated coordinated of the shape's centre
std::pair<int, int> Shape::setCentre(int x, int y) {
    this->cx = x;
    this->cy = y;
    this->shape_element->setOrigin({-(float)x, -(float)y});
    return {this->cx, this->cy};
}

// function to translate the shape
// returns the updated coordinated of the shape's centre
std::pair<int, int> Shape::translate(int dx, int dy) {
    this->cx += dx;
    this->cy += dy;
    this->shape_element->move({(float)dx, (float)dy});
    return {this->cx, this->cy};
}

// returns the length of rectangle or square,
// cannot be used for any other shape
int Shape::getLength() {
    assert(this->shapeID == 0 || this->shapeID == 1);
    return 0;
}

// returns the breadth of rectangle or square,
// cannot be used for any other shape
int Shape::getBreadth() {
    assert(this->shapeID == 0 || this->shapeID == 1);
    return 0;
}

// returns the radius of circle,
// cannot be used for any other shape
int Shape::getRadii() {
    assert(this->shapeID == 2);
    return 0;
}

// returns half of the X-axis length of ellipse or circle (radius in this case),
// cannot be used for any other shape
int Shape::getXLength() {
    assert(this->shapeID == 3 || this->shapeID == 2);
    return 0;
}

// returns half of the Y-axis length of ellipse or circle (radius in this case),
// cannot be used for any other shape
int Shape::getYLength() {
    assert(this->shapeID == 3 || this->shapeID == 2);
    return 0;
}

// returns the area of the shape
long double Shape::getArea() {
    return 0;
}

// Constructor, l and b are the length(X-axis) and breadth(Y-axis) respectively
Rectangle::Rectangle (int l, int b) : length(l), breadth(b) {
    this->shapeID = 0;

    // initializing the canvas shape
    this->shape_element = std::make_shared<sf::RectangleShape>(sf::Vector2f((float)l, (float)b));
    this->shape_element->setOrigin({(float)this->cx, (float)this->cy});
    std::tuple<int, int, int> clr = this->color;
    this->shape_element->setFillColor(sf::Color(std::get<0>(clr), std::get<1>(clr), std::get<2>(clr)));
}

// returns the X_dimension of rectangle
int Rectangle::getLength() {
    return this->length;
}

// returns the Y-dimension of the rectangle
int Rectangle::getBreadth() {
    return this->breadth;
}

// returns the area of the rectangle
long double Rectangle::getArea() {
    return (long double)(this->length) * (long double)(this->breadth);
}

// Constructor: l is the side length of the square
Square::Square(int l): Rectangle(l, l) {
    this->shapeID = 1;
}

// Constructor: aa and bb are semi-X-axis length and semi-Y-axis length respectively 
Ellipse::Ellipse(int aa, int bb) : a(aa), b(bb) {
    this->shapeID = 3;

    // initializing the canvas shape
    this->shape_element = std::make_shared<EllipseShape>(sf::Vector2f((float)aa, (float)bb));
    this->shape_element->setOrigin({(float)this->cx, (float)this->cy});
    std::tuple<int, int, int> clr = this->color;
    this->shape_element->setFillColor(sf::Color(std::get<0>(clr), std::get<1>(clr), std::get<2>(clr)));
}

// returns the semi-X-axis length of the ellipse
int Ellipse::getXLength() {
    return this->a;
}

// returns the semi-Y-axis length of the ellipse
int Ellipse::getYLength() {
    return this->b;
}

// returns the area of the ellipse
long double Ellipse::getArea() {
    return M_PI * (long double)(this->a) * (long double)(this->b);
}

// Constructor: r is the radius of the circle
Circle::Circle(int r): Ellipse(r, r) {
    this->shapeID = 2;

    // initializing the canvas shape
    this->shape_element = std::make_shared<sf::CircleShape>((float)r);
    this->shape_element->setOrigin({(float)this->cx, (float)this->cy});
    std::tuple<int, int, int> clr = this->color;
    this->shape_element->setFillColor(sf::Color(std::get<0>(clr), std::get<1>(clr), std::get<2>(clr)));
}

// returns the radius of the circle
int Circle::getRadii() {
    return this->a;
}
