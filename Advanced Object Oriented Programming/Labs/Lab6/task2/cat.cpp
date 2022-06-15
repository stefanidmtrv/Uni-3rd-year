#include <iostream>
#include "cat.h"

Cat::Cat() : name("Tom"), lives(9)
{
  std::cout << "Default constructor called..." << std::endl;
}
Cat::Cat(std::string name) : name(name), lives(9)
{
  std::cout << "Cat constructor called with name: " << name << std::endl;
}
Cat::Cat(std::string name, unsigned int lives) : name(name), lives(lives)
{
  std::cout << "Cat constructor called with name: " << name << " and lives: " << lives << std::endl;
}

Cat::Cat(Cat &&other) noexcept : name(other.name), lives(other.lives)
{
  std::cout << "Move constructor called..." << std::endl;

 
  other.name = "";
  other.lives = 0;
}


Cat &Cat::operator=(Cat &&a) noexcept
{
  std::cout << "Move assignment operator called..." << std::endl;

  
  if (&a == this)
    return *this;

  name = a.name;
  lives = a.lives;

  a.name = "";
  a.lives = 0;

  return *this;
}

Cat::~Cat()
{
  std::cout << "Destructing... " << name << std::endl;
}

std::string &Cat::get_name()
{
  return this->name;
}

unsigned int &Cat::get_lives()
{
  return this->lives;
}

void Cat::set_name(std::string &name)
{
  std::cout << "set_name called... " << std::endl;
  this->name = name;
}

void Cat::set_lives(unsigned int &lives)
{
  std::cout << "set_lives called... " << std::endl;

  if (lives > this->lives)
  {
    return;
  }
  else if (this->lives > 0 && lives == 0)
  {
    std::string newName = "The Cat formally known as " + this->name;
    this->set_name(newName);
  }

  this->lives = lives;
}

std::string Cat::to_string() const
{
  return "Cat: " + this->name + " has " + std::to_string(this->lives) + " lives.";
}

std::ostream& operator<<(std::ostream& os, const Cat& cat){
    return os << cat.to_string();
  }

bool operator==(const Cat& lhs, const Cat& rhs){
  return lhs.lives == rhs.lives && lhs.name == rhs.name;
}