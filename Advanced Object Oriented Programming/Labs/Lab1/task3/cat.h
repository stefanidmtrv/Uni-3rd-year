#ifndef CAT_H
#define CAT_H
#pragma once

class Cat
{

  
// Private members.
private:
  std::string name;
  unsigned int lives;
  friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
  friend bool operator==(const Cat& lhs, const Cat& rhs);
  friend bool operator<(const Cat &lhs, const Cat &rhs);
public:
  // Constructors.
  Cat();
  Cat(Cat &&other) noexcept; // move constructor.
  Cat(std::string name);
  Cat(std::string name, unsigned int lives);

  Cat &operator=(Cat &&other) noexcept; 

  // Destructor.
  ~Cat();

  // Getters.
  std::string &get_name();
  unsigned int &get_lives();

  // Setters.
  void set_name(std::string &name);
  void set_lives(unsigned int &lives);

  // Other methods.
  std::string to_string() const;

};

namespace std {
    template <>
    struct hash <Cat> {
      size_t operator()(const Cat &obj) const {
        
        return std::hash<std::string>()(obj.to_string());
      }
    };
  }

#endif