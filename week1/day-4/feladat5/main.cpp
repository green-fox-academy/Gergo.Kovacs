#include <iostream>
#include <string>



void calculate_factorial(int maxnumber,int& factorial) {
    factorial = maxnumber;

    while (maxnumber > 1) {
        maxnumber--;
        factorial = factorial * maxnumber;
    }
}

    int main(int argc, char* args[]){

        std::cout<<"irj be egy számot."<<std::endl;
        int x, result;
        std::cin>> x;

        calculate_factorial(x, result);
        std::cout<<"faktoriált eredmény. "<<result<<std::endl;
        return 0;
    }