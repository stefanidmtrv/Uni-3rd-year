#ifndef CAT_H
#define CAT_H
#pragma once

class Cat
{
// Private members.
private:
  std::string name;
  unsigned int lives;

public:
  // Constructors.
  Cat();
  Cat(Cat &&other) noexcept; // move constructor.
  Cat(std::string name);
  Cat(std::string name, unsigned int lives);

  Cat &operator=(Cat &&other) noexcept; // move assignment operator.

  // Destructor.
  ~Cat();

  // Getters.
  std::string &get_name();
  unsigned int &get_lives();

  // Setters.
  void set_name(std::string &name);
  void set_lives(unsigned int &lives);

  // Other methods.
  std::string to_string();
};

#endif