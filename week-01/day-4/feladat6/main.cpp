#include <iostream>
#include <string>

void swap(int& a, int& b){
int c=a;
    a=b;
    b=c;
}

int main(int argc, char* args[]) {

    int a = 15;
    int b = 23;
    int c;

    std::cout << "the original numbers: " <<std::endl;
    std::cout << a <<std::endl;
    std::cout << b <<std::endl;

    swap(a,b);

    std::cout<<"swap numbers: " <<std::endl;
    std::cout<< a <<std::endl;
    std::cout<< b <<std::endl;

    return 0;
}
