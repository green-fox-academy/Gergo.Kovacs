#include <iostream>

class Enemy
{
 public:
  virtual void attack()//=0; //pure virtual function
   {
       std::cout << "i am the enemy class" << std::endl;
   };
};

class Ninja : /*virtual*/ public Enemy
{
 public:
  void attack()
  {
      std::cout << "ninja attack!" << std::endl;
  }
};

class Monster : public Enemy
{
 public:
  void attack()
  {
      std::cout << "monster attack!" << std::endl;
  }
};

int main()
{

    Ninja n;
    Monster m;
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;
    enemy1->attack();
    enemy2->attack();

    return 0;
}