#include "mentor.h"
#include <iostream>

std::string getLevelStrig(Level level)
{
    if (level == Level::JUNIOR) {
        return "Junior";
    } else if (level == Level::INTERMEDIATE) {
        return "Intermediate";
    } else if (level == Level::SENIOR) {
        return "Senior";
    }
}

Mentor::Mentor() :
    Person();
{
_level = Level::INTERMEDIATE;
}

Mentor::Mentor(int age, std::string name, Gender gender, Level level) :
    Person(age, name, gender)
{
    _level = level;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << _gender << " " << _level << "mentor"
              << std::endl;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}