#include <iostream>
#include <cmath>
#include "cat.h"

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "No arguments were provided." << std::endl;
    return 1;
  }

  const unsigned int noCats = round((argc - 1) / 2.0);
  Cat *cats = new Cat[noCats];

  for (unsigned int i = 0; i < noCats; i++)
  {
    std::string name = argv[2 * i + 1];

    if ((2 * i + 2) < argc)
    {
      unsigned int lives = std::stoi(argv[2 * i + 2]);
      cats[i] = Cat(name, lives);
    }
    else
    {
      cats[i] = Cat(name);
    }
  }

  for (unsigned int i = 0; i < noCats; i++)
  {
    std::cout
        << "Cat " << i << ": "
        << cats[i].to_string()
        << std::endl;
  }

  delete[] cats;

  return 0;
}