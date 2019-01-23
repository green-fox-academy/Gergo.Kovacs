#include <iostream>
#include <fstream>

    int div(int num){

    int b;

        if (num ==0){
            throw std::string("fail");
        }
        b = 10/num;

    return b;
}
int main() {

    int a;
    std::cout<<"give me a number"<<std::endl;
    std::cin >>a;

    try {
        std::cout << div(a) << std::endl;
    } catch (std::string e) {
        std::cout<<e<<std::endl;



    }
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    return 0;
}
