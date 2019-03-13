#include <iostream>

int main(int argc, char* args[]) {
    int tyuk;
    int diszno;
    int tyuklab;
    int disznolab;


    std::cout<<"add meg a tyukok mennyiségét?"<<std::endl;
    std::cin>>tyuk;

    std::cout<<"add meg a disznók mennyiségét?"<<std::endl;
    std::cin>>diszno;

    tyuklab=(tyuk*2);
    disznolab=(diszno*4);

    std::cout<<"Összesen hány láb van a farmon: "<<tyuklab+disznolab<<std::endl;

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    return 0;
}