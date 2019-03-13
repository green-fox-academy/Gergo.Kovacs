#include "cohort.h"
#include <iostream>

Cohort::Cohort(std::string name)
{
    _name = name;
}
void Cohort::addStudent(Student *s)
{
_students.push_back(*s);
}
void Cohort::addMentor(Mentor *m)
{
    _mentors.push_back(*m);
}
void Cohort::info(){
    std::cout<<"The "<<_name<<" cohort has"<<_students.size()<<" students and"<<_mentors.size()<<std::endl;
}