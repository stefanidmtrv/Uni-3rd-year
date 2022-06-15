#ifndef INTVECTOR_H
#define INTVECTOR_H
#pragma once

#include <iostream>

class IntVector
{
private:
  int *data;
  unsigned int pos;
  unsigned int length;

public:
  // Constructors.
  IntVector();
  IntVector(unsigned int length);
  IntVector(IntVector &&other) noexcept; // move constructor.

  IntVector &operator=(IntVector &&a) noexcept; // move assignment operator.

  // Destructor.
  ~IntVector();

  // Methods.
  void push(const int value);
  int pop();
  void resize(unsigned int new_length);

  // overload >> operator in class scope.
  friend std::ostream &operator<<(std::ostream &os, const IntVector &iv);
  void print();
};

#endif