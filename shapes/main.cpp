#include <iostream>
#include "shapepp.h"
#include "canvas.h"

int main () {

    Canvas c = Canvas(800, 600);

    std::cout << "-----------Testing Rectangle-------" << std::endl;
    Shape* A = new Rectangle(100, 150);
    A->setCentre(10, 150);
    std::cout << "Shape ID: " << A->getShape() << ", Is square: " << A->isSquare() << std::endl;
    std::cout << "Length: " << A->getLength() << ", Breadth: " << A->getBreadth() << std::endl;
    std::cout << "Area: " << A->getArea() << std::endl;
    c.addShape(A);

    std::cout << "-------------Testing Square---------" << std::endl;
    Shape* B = new Square(100);
    B->translate(200, 150);
    B->setColor(0, 0, 255);
    std::cout << "Shape ID: " << B->getShape() << ", Is square: " << B->isSquare() << std::endl;
    std::cout << "Length: " << B->getLength() << ", Breadth: " << B->getBreadth() << std::endl;
    std::cout << "Area: " << B->getArea() << std::endl;
    c.addShape(B);

    std::cout << "-------------Testing Circle---------" << std::endl;
    Shape* C = new Circle(100);
    C->setColor(255, 0, 0);
    C->setCentre(400, 150);
    std::cout << "Shape ID: " << C->getShape() << ", Is square: " << C->isSquare() << std::endl;
    std::cout << "Radius: " << C->getRadii() << std::endl;
    std::cout << "Area: " << C->getArea() << std::endl;
    c.addShape(C);

    std::cout << "-------------Testing Ellipse---------" << std::endl;
    Shape* D = new Ellipse(100, 50);
    D->translate(300, 400);
    std::cout << "Shape ID: " << D->getShape() << ", Is square: " << D->isSquare() << std::endl;
    std::cout << "Semi-X-axis: " << D->getXLength() << ", Semi-Y-axis: " << D->getYLength() << std::endl;
    std::cout << "Area: " << D->getArea() << std::endl;
    c.addShape(D);

    // testing SFML
    std::cout << "--------display----------" << std::endl;
    c.displayCanvas();


}