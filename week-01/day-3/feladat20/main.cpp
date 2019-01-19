#include <iostream>

int main(int argc, char* args[]) {
    int a;
    int b;
    int bigger;


    std::cout << "kérek két számot." << std::endl;
    std::cin >> a >> b;

    if (a>b){
        std::cout<<a<<std::endl;
    } else {
        std::cout<<b<<std::endl;
    }

    // Write a program that asks for two numbers and prints the bigger one

    return 0;
}