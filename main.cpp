//Winter 2024. EECS 280 Lab 6 Section 029. Alan Sun and Shayla Doan.
//In-Class Demonstration of Inheritance and Polymorphism
#include "Shapes.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;


//INSTRUCTIONS: There are three errors in Shapes.hpp that prevent
//              the program from compiling. Find them and fix them.
//              Do not alter any of the private member variables or
//              the order they're declared in (hint hint)


/* -------------------------------------------------------------------------- */
/*                     DO NOT EDIT THE CODE BELOW (please)                    */
/* -------------------------------------------------------------------------- */


//POLYMORPHISM!!!
void print_shape(const string& type, const Shape& s) {
    cout << type << " area is " << s.get_area() << endl;
    cout << type << " perimeter is " << s.get_perimeter() << endl;
    cout << endl;
}


int main() {
    //now cout always prints 2 decimal places
    cout << fixed << setprecision(2);

    //Shape bad_shape; //why is this not compiling??

    Shape* s = new Circle(3);
    cout << "Circle Area: " << s->get_area() << endl;
    cout << "Circle Perimeter: " << s->get_perimeter() << endl;
    cout << endl;
    delete s;

    Rectangle* r = new Square(10);
    cout << "Square Area: " << r->get_area() << endl;
    cout << "Square Perimeter: " << r->get_perimeter() << endl;
    cout << endl;
    delete r;

    //what will print? We never put "virtual" in front of
    //the Rectangle functions, so will this run the Rectangle
    //version or the Random versions?
    r = new StupidRectangle();   //"delete r" deletes the object at r, not the ptr
    cout << "Random Area: " << r->get_area() << endl;
    cout << "Random Perimeter: " << r->get_perimeter() << endl;
    cout << endl;
    delete r;

    s = new NegativeSquare(8);
    print_shape("Negative Square", *s);
    delete s;

    Rectangle rect(2, 3);
    print_shape("Rectangle", rect);


    return 0;
}