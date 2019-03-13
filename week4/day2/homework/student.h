#ifndef HOMEWORK_STUDENT_H
#define HOMEWORK_STUDENT_H
#include "person.h"

class Student : public Person
{
 public:
  Student();
  Student(int age, std::string name, Gender gender, std::string previousOrganization);

  void introduce() override;

  void getGoal() override;

 private:
  int _skippedDays;
  std::string _previousOrganization;

};

#endif //HOMEWORK_STUDENT_H
