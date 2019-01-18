
#include <iostream>

int main(int argc, char* args[]) {
    int km;
    double miles;

    std::cout<<"érték km-ben?"<<std::endl;
    std::cin>>km;

    miles=(km*1.6093);

    std::cout<<"mérföldben: "<< miles<<std::endl;

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    return 0;
}