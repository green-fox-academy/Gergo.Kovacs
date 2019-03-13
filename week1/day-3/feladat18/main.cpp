#include <iostream>

int main(int argc, char* args[]) {
    int a;
    std::cout<<"add a number?"<<std::endl;
    std::cin>>a;

    if (a%2==0) {
        std::cout<<"odd number"<<std::endl;
    } else {
        std::cout<<"even number"<<std::endl;
    }

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    return 0;
}