#include <iostream>

int main(int argc, char* args[]) {
    double a,b,c,felszin,terfogat;

    std::cout <<"kérem a téglatest első értékét?"<<std::endl;
    std::cin>>a;

    std::cout <<"kérem a téglatest második értékét?"<<std::endl;
    std::cin>>b;

    std::cout<<"kérem a téglatest harmadik értékét?"<<std::endl;
    std::cin >>c;

    felszin =(2*(a*b+a*c+b*c));
    std::cout<<"a téglatest felszine: "<<felszin<<std::endl;

    terfogat=(a*b*c);
    std::cout<<"a téglatest terfogata: "<< terfogat<<std::endl;

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000


    return 0;
}
