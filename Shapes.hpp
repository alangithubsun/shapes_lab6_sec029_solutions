#ifndef _SHAPES_HPP
#define _SHAPES_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

static const double pi = 3.1415926535;

class Shape {
public:
    //returns area of shape
    virtual double get_area() const = 0;

    //return perimeter of shape
    virtual double get_perimeter() const = 0;

    virtual ~Shape() {} //needed to delete shape objects through pointers
};


class Circle : public Shape { //ERROR #1: Used to be "Shape" instead of "public Shape"
public:
    Circle() : radius(0) {}
    Circle(double radius_) : radius(radius_) {}

    virtual double get_area() const override { return pi * radius * radius; }
    virtual double get_perimeter() const override {return 2 * pi * radius; }

private:
    double radius;
};


class Rectangle : public Shape {
public:
    Rectangle() : length(0), width(0) {} //ERROR #2: Used to be width(0), length(0)
    Rectangle(double length_, double width_) : length(length_), width(width_) {}

    double get_area() const { return length * width; }
    double get_perimeter() const { return 2 * (length + width); }

private:
    double length;
    double width;
};


class Square : public Rectangle {
public:
    Square() : Rectangle() {}
    Square(double side) : Rectangle(side, side) {}

    double get_area() const { return Rectangle::get_area(); }
    double get_perimeter() const { return Rectangle::get_perimeter(); }
};


class NegativeSquare : public Square {
public:
    NegativeSquare() : Square(), scalar(-1) {}
    NegativeSquare(double side_length) : Square(side_length), scalar(-1) {} 

    virtual double get_area() const override { return Square::get_area() * scalar; }
    virtual double get_perimeter() const override {return Square::get_perimeter() * scalar; }
private:
    double scalar;
};


class StupidRectangle : public Rectangle {
public:
    StupidRectangle() : Rectangle(), junk(33) {} //ERROR #3: Used to be junk(33), Rectangle()

    double get_area() const {
        std::cout << "RANDOM AREA ";
        return 123.45;
    }

    double get_perimeter() const {
        std::cout << "RANDOM PERIMETER ";
        return 543.21;
    }

private:
    int junk;
};


#endif