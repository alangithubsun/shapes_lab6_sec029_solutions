Here are the three errors. The line numbers are the Line numbers from the ORIGINAL non solutions file.

Error #1 in Shapes.hpp Line 23: 
  Added "public" in front of Shape so now we have "class Circle : public Shape {".
  NOw the inheritance relationship is PUBLIC whereas before it was private. This is
  why main.cpp line 37 was giving an error (Shape* s = new Circle(3);)

Error #2 in Shapes.hpp Line 43:
  The member initializer list in the Rectangle
  default constructor should be length(0), width(0) instead of 
  width(0), length(0) since the private variables of Rectangle are declared 
  with length first. The member initializer list must adhere to the order 
  the private variables are listed in.

Error #3 in Shapes.hpp Line 91:
  The member initializer list in the StupidRectangle function had the wrong 
  order for initialzation. Before, we did "junk(33), Rectangle()", but it
  should be "Rectangle(), junk(33)" since we need to call our base class
  constructor before initializing any of our derived class's members.
  Remember that when a new derived class object is created, the base
  class constructor is ran first, then the derived class constructor.
