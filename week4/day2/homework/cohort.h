#ifndef HOMEWORK_COHORT_H
#define HOMEWORK_COHORT_H
#include <iostream>
#include <vector>
#include "person.h"
#include "mentor.h"
#include "student.h"

class Cohort : public Person
{
 public:
  Cohort(std::string name);
  void addStudent(Student *);
  void addMentor(Mentor *);
  void info();

 private:

  std::string _name;
  std::vector<Student> _students;
  std::vector<Mentor> _mentors;
};

#endif //HOMEWORK_COHORT_H
