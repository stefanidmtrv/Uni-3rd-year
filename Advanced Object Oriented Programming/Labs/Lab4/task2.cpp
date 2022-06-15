#include <iostream>
#include "cat.h"

int main(int argc, char *argv[])
{
  Cat a("Garfield");

  std::cout
      << a.get_name() << " has "
      << a.get_lives() << " lives." << std::endl;

  Cat b("Mog", 10);
  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;

  unsigned int newLives = 42;
  b.set_lives(newLives);

  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;

  std::string newName = "Prince";
  b.set_name(newName);

  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;

  newLives = 8;
  b.set_lives(newLives);

  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;
  
  newLives = 0;
  b.set_lives(newLives);

  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;
  
  b.set_lives(newLives);

  std::cout
      << b.get_name() << " has "
      << b.get_lives() << " lives." << std::endl;

  return 0;
}
