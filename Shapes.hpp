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


class Circle : public Shape {
public:
    //default constructor, sets radius to 0
    Circle() : radius(0) {}

    //non-default constructor, what should go in the ??
    Circle(double radius_) : radius(radius_) {}

    //what does override do?
    //does virtual matter here?
    virtual double get_area() const override { return pi * radius * radius; }
    virtual double get_perimeter() const override {return 2 * pi * radius; }

private:
    double radius;
};


class Rectangle : public Shape {
public:
    Rectangle() : length(0), width(0) {}

    Rectangle(double length_, double width_) : length(length_), width(width_) {}

    //there's no virtual or override. Does this cause problems?
    double get_area() const { return length * width; }
    double get_perimeter() const { return 2 * (length + width); }

private:
    double length;
    double width;
};


class Square : public Rectangle {
public:
    //default constructor that calls default constructor
    //to initialize rectangle's member varaibles
    Square() : Rectangle() {}

    //makes rectangle's length and width equal to side
    Square(double side) : Rectangle(side, side) {}

    //now we can juse call the functions from the
    //Rectangle class to reduce code duplication
    double get_area() const { return Rectangle::get_area(); }
    double get_perimeter() const { return Rectangle::get_perimeter(); }

    //note that square does NOT have any private member 
    //variables itself. Do we need any for square?
};


//everything in NeagtiveSquare is correct
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
    StupidRectangle() : Rectangle(), junk(33) {}

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