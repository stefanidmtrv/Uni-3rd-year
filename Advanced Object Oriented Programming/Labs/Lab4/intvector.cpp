#include <iostream>
#include "intvector.h"

// Constructors.

IntVector::IntVector() : length(4), data(new int[4]), pos(0)
{
  std::cout << "Default constructor called..." << std::endl;
}

IntVector::IntVector(unsigned int length) : length(length), data(new int[length]), pos(0)
{
  std::cout << "IntVector constructor called with length: " << length << std::endl;
}

// Move constructor.
IntVector::IntVector(IntVector &&other) noexcept : length(other.length), data(other.data), pos(other.pos)
{
  std::cout << "Move constructor called..." << std::endl;

  // Reset values of other.
  other.length = 0;
  other.data = nullptr;
  other.pos = 0;
}

// Move assignment operator.
IntVector &IntVector::operator=(IntVector &&a) noexcept
{
  std::cout << "Move assignment operator called..." << std::endl;

  // Check if we are assigning to ourselves.
  if (&a == this)
    return *this;

  // Copy the values from the other object.
  length = a.length;
  data = a.data;
  pos = a.pos;

  // Reset the values in the other object.
  a.length = 0;
  a.data = nullptr;
  a.pos = 0;

  // Return a reference to ourselves.
  return *this;
}

// Destructor.

IntVector::~IntVector()
{
  std::cout << "Destructing... " << std::endl;

  delete[] data;
}

// Methods

void IntVector::push(const int value)
{
  // Check if we need to resize.
  if (pos >= length)
  {
    // Resize.
    resize(length * 2);
  }

  // Add the value.
  data[pos++] = value;
}

int IntVector::pop()
{
  // Check if we have any values.
  if (pos == 0)
    throw std::runtime_error("No values to pop.");

  // Return the value, then decrement the position.
  return data[--pos];
}

void IntVector::resize(const unsigned int new_length)
{
  if (new_length > 0)
  {
    // Create a new array.
    int *new_data = new int[new_length];

    // Copy the old data to the new array.
    for (unsigned int i = 0; i < pos; i++)
    {
      new_data[i] = data[i];
    }

    // Delete the old array.
    delete[] data;

    // Set the new data.
    data = new_data;
    length = new_length;

    std::cout << "Resized to: " << length << std::endl;
  }
  else
  {
    // Log invalid size, deleting the array.
    std::cout << "Invalid size: " << new_length << ". Deleting IntVector." << std::endl;
    delete this;
  }
}

// Overload >> operator.
std::ostream &operator<<(std::ostream &os, const IntVector &iv)
{
  os << "\nIntVector - Pos: " << iv.pos << ", Length: " << iv.length << "\n\t";
  for (unsigned int i = 0; i < iv.pos; i++)
  {
    os << iv.data[i] << " ";
  }
  os << std::endl;

  return os;
}

// Print using the overloaded >> operator.
void IntVector::print()
{
  std::cout << *this << std::endl;
}
