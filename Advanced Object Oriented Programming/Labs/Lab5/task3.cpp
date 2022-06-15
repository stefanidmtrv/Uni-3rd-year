#include <iostream>
#include "Shape.h"

int main(int argc, char *argv[])
{
  // Creating an array of different shapes.
  Shape **shapes = new Shape*[10];
  shapes[0] = new Circle(0, 0, 1);
  shapes[1] = new Rectangle(0, 0, 1, 1);
  shapes[2] = new Triangle(0, 0, 1, 1, 1, 1);
  shapes[3] = new Circle(0, 1, 1);
  shapes[4] = new Rectangle(0, 5, 1, 1);
  shapes[5] = new Triangle(0, 5, 1, 3, 1, 2);
  shapes[6] = new Circle(5, 0, 1);
  shapes[7] = new Rectangle(15, 0, 2, 1);
  shapes[8] = new Triangle(3, 7, 1, 10, 1, 12);
  shapes[9] = new Circle(17, 3, 15);

  std::cout << "\nOriginal Shapes...\n" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << shapes[i]->to_string() << std::endl;
  }

  std::cout << "\nRecentring circles..." << std::endl;

  for (int i = 0; i < 10; i++) {
    shapes[i]->centre_at(13, 4);
  }

  std::cout << "Shapes should now be centred around (13, 4)\n" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << shapes[i]->to_string() << std::endl;
  }

  // Clean up
  for (int i = 0; i < 10; i++) {
    delete shapes[i];
  }

  delete[] shapes;
}
