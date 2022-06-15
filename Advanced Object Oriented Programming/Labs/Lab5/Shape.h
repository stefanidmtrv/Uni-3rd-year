#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <iostream>

// Shape

class Shape
{
public:
  Shape();
  virtual ~Shape();

  virtual std::string to_string() const = 0;
  virtual void centre_at(double x, double y) = 0;
};

// Circle

class Circle : public Shape
{
private:
  double x, y, radius;

public:
  Circle(double x, double y, double radius);
  virtual ~Circle();

  virtual std::string to_string() const;
  virtual void centre_at(double x, double y);
};

// Rectangle

class Rectangle : public Shape
{
private:
  double x0, y0, x1, y1;

public:
  Rectangle(double x0, double y0, double x1, double y1);
  virtual ~Rectangle();

  virtual std::string to_string() const;
  virtual void centre_at(double x, double y);
};

// Triangle

class Triangle : public Shape
{
private:
  double x0, y0, x1, y1, x2, y2;

public:
  Triangle(double x0, double y0, double x1, double y1, double x2, double y2);
  virtual ~Triangle();

  virtual std::string to_string() const;
  virtual void centre_at(double x, double y);
};

#endif
