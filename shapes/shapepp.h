#ifndef SHAPEPP_H
#define SHAPEPP_H

#include <utility>
#include <memory>
#include <SFML/Graphics.hpp>

class Shape {
protected:
    int shapeID;
    int cx, cy;
    std::tuple<int, int, int> color;  // (r, g, b)
    std::shared_ptr<sf::Shape> shape_element;

public:
    Shape();
    int getShape();
    bool isSquare();

    int setColor(int r, int g, int b);
    std::tuple<int, int, int> getColor();

    int displayShape(sf::RenderWindow & c);

    std::pair<int, int> Coordinates();
    std::pair<int, int> setCentre(int x, int y);
    std::pair<int, int> translate(int dx, int dy);

    virtual int getLength();
    virtual int getBreadth();
    virtual int getRadii();
    virtual int getXLength();
    virtual int getYLength();
    virtual long double getArea();

};

class Rectangle : public Shape {
private:
    int length, breadth;

public:
    Rectangle(int l, int b);
    int getLength() override;
    int getBreadth() override;
    long double getArea() override;
};

class Square: public Rectangle {
public:
    Square(int l);
};

class Ellipse : public Shape {
protected:
    int a, b;
public:
    Ellipse(int aa, int bb);
    int getXLength() override;
    int getYLength() override;
    long double getArea() override;
};

class Circle : public Ellipse {
public:
    Circle(int r);
    int getRadii() override;
};

#endif