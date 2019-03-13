#include "student.h"
#include <iostream>

Student::Student() :
    Person()
{
    _previousOrganization = "The schoolof life! ";
    _skippedDays = 0;
}

Student::Student(int age, std::string name, Gender gender, std::string previousOrganization) :
    Person(age, name, gender)
{
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}
void Student::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << _gender << " from " << _previousOrganization
              << " who skipped " << _skippedDays << "days from the course already." << std::endl;
}
void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}
