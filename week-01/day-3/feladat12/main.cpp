#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    double a = 6;
    double b = 10;
    double c = 10;
    std::cout<<"Surface Area\n"<< (a*b*c)<<std::endl;
    std::cout<<"Volume \n"<< (2*(a*b+a*c+b*c))<<std::endl;


    return 0;
}