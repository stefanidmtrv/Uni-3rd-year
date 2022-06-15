#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "Shape.h"

// Shape

Shape::Shape()
{
  std::cout << "Default constructor called..." << std::endl;
}

Shape::~Shape()
{
  std::cout << "Default deconstructor" << std::endl;
}

// Circle

Circle::Circle(double x, double y, double radius) : x(x), y(y), radius(radius)
{
  std::cout << "Circle constructor called..." << std::endl;
}

Circle::~Circle()
{
  std::cout << "Circle deconstructor" << std::endl;
}

std::string Circle::to_string() const
{
  std::stringstream string_stream;
  string_stream << "Circle centred at (" << x << ", " << y << ") with radius " << radius;

  return string_stream.str();
}

void Circle::centre_at(double x, double y)
{
  this->x = x;
  this->y = y;
}

// Rectangle

Rectangle::Rectangle(double x0, double y0, double x1, double y1) : x0(x0), y0(y0), x1(x1), y1(y1)
{
  std::cout << "Rectangle constructor called..." << std::endl;
}

Rectangle::~Rectangle()
{
  std::cout << "Deconstructing rectangle." << std::endl;
}

std::string Rectangle::to_string() const
{
  std::stringstream string_stream;

  string_stream
      << "Rectangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << ")]"
      << " with width " << abs(x1 - x0) << " and height " << abs(y1 - y0) << ".";

  return string_stream.str();
}

void Rectangle::centre_at(double x, double y)
{
  const double width = x1 - x0;
  const double height = y1 - y0;

  this->x0 = x - width / 2;
  this->y0 = y - height / 2;

  this->x1 = x + width / 2;
  this->y1 = y + height / 2;
}

// Triangle

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2) : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2)
{
  std::cout << "Triangle constructor called..." << std::endl;
}

Triangle::~Triangle()
{
  std::cout << "Deconstructing triangle." << std::endl;
}

std::string Triangle::to_string() const
{
  std::stringstream string_stream;

  const double side_one_length = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
  const double side_two_length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  const double side_three_length = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2));

  string_stream
      << "Triangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")]"
      << " with sides of length " << side_one_length << ", " << side_two_length << " and " << side_three_length << ".";

  return string_stream.str();
}

void Triangle::centre_at(double x, double y)
{
  const double x_centre = (x0 + x1 + x2) / 3;
  const double y_centre = (y0 + y1 + y2) / 3;
  
  const double x_diff = y_centre - y;
  const double y_diff = y_centre - y;

  x0 += x_diff;
  x1 += x_diff;
  x2 += x_diff;
  
  y0 += y_diff;
  y1 += y_diff;
  y2 += y_diff;
}
