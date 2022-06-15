#include <iostream>
#include "intvector.h"

int main(void)
{
  std::cout << "Press p to pop, q to quit or a number to push." << std::endl;

  IntVector iv = IntVector();
  while (true)
  {
    std::string value;
    std::cout << "Enter a value: ";
    std::cin >> value;

    if (value == "q")
      break;
    else if (value == "p")
    {
      try
      {
        int popped = iv.pop();
        std::cout << "Popped value: " << popped << std::endl;
      }
      catch (std::exception &e)
      {
        std::cout << e.what() << std::endl;
      }
    }
    else
    {
      // User may have inputted an invalid value
      try
      {
        iv.push(std::stoi(value));
      }
      catch (std::invalid_argument)
      {
        std::cout << "Invalid argument." << std::endl;
      }

      iv.print();
    }
  }

  return 0;
}
