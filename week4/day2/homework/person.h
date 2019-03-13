#ifndef HOMEWORK_PERSON_H
#define HOMEWORK_PERSON_H
#include <string>
#include <istream>

enum Gender
{
  MALE,
  FEMALE,   //nagy betűvel irjuk a consstans(állandó) dolgokat
};
std::string getGenderString(Gender gender);

class Person
{

 public:
  Person();

  Person(int age, std::string name, Gender gender);

  virtual void introduce();

  virtual void getGoal();

 protected:
  int _age;
  std::string _name;
  Gender _gender;
};

#endif //HOMEWORK_PERSON_H
