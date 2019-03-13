#include "Animal.h"

Animal::Animal()
{
    _name = "Animal";
}

Animal::Animal(std::string name){
    _name = name;
}

std::string Animal::toString()
{
    return _name + " is healthy and adoptable";
}