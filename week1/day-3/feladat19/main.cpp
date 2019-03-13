#include <iostream>

int main(int argc, char* args[]) {
    int a;

    std::cout<<"give me a number"<<std::endl;
    std::cin>>a;

    if (a==0){
        std::cout<<"not enough"<<std::endl;
    } else if (a==1){
        std::cout<<"one"<<std::endl;
    } else if (a==2){
        std::cout<<"two"<<std::endl;
    } else if (a>2){
        std::cout<<"a lot"<<std::endl;
    }
    // Write a program that reads a number form the standard input,
    // If the number is zero or smaller it should print: Not enough
    // If the number is one it should print: One
    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    return 0;
}