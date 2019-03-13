#ifndef HOMEWORK_SPONSOR_H
#define HOMEWORK_SPONSOR_H

#include "person.h"
class Sponsor : public Person
{
 public:
  Sponsor();
  Sponsor(int age, std::string name, Gender gender, std::string company);
  void introduce() override;
  void getGoal() override;
  void hire();
 private:
  std::string _company;
  int _hiredStudents;

};

#endif //HOMEWORK_SPONSOR_H
