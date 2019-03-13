#ifndef HOMEWORK_MENTOR_H
#define HOMEWORK_MENTOR_H
#include "person.h"

enum Level
{
  JUNIOR,
  INTERMEDIATE,
  SENIOR

};
std::string getLevelStrig(Level level);

class Mentor : public Person
{
 public:
  Mentor();
  Mentor(int age, std::string name, Gender gender, Level level);
  void introduce() override;
  void getGoal() override;
 protected:
 private:
  Level _level;

};

#endif //HOMEWORK_MENTOR_H
