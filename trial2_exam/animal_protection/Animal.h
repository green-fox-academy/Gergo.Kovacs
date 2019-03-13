#ifndef ANIMAL_PROTECTION_ANIMAL_H
#define ANIMAL_PROTECTION_ANIMAL_H
#include <iostream>

class Animal
{
 public:
  Animal();
  Animal(std::string name);
  std::string toString();
 private:
  std::string _name;
};

#endif //ANIMAL_PROTECTION_ANIMAL_H
