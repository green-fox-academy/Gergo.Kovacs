#include "person.h"
#include <iostream>

std::string getGenderString(Gender gender)
{
    if (gender == Gender::FEMALE) {
        return "Female";
    } else if (gender == Gender::MALE) {
        return "Male";
    }
}
Person::Person()
{
    _age = 30;
    _name = "Jane Doe";
    _gender = Gender::FEMALE;
}
Person::Person(int age, std::string name, Gender gender)
{

    _age = age;
    _name = name;
    _gender = gender;

}
void Person::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << _gender << "." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}
