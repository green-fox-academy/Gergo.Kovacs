#include <iostream>

class Fridge
{
 public:
  int temp;

 protected:
  bool HasFreeon;
};
class Truck
{
  int gas;

 public:
  int speed;
  void setGas(int mGas)
  {
      gas = mGas;
  }

  int getGas()
  {
      return gas;
  }
};

class FreezerTurck : public Truck, public Fridge
{
 public:
  void setFreeon()
  {
      this->HasFreeon = true;
  }
};
int main()
{

    FreezerTurck mTruck;
    mTruck.speed = 100;
    mTruck.temp = 20;

    std::cout << mTruck.speed << std::endl;

    std::cout << mTruck.temp << std::endl;
    mTruck.setGas(100);
    std::cout << mTruck.getGas() << std::endl;

    mTruck.setFreeon();

    return 0;
}