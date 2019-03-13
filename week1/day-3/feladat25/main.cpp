
#include <iostream>

int main(int argc, char* args[]) {





    int a;
    int b=0;
    int result;
    std::cout<<"give me a number?"<<std::endl;
    std::cin>>a;

    while(b<11){
        result=(b*a);
        std::cout<<b << " * "<<a<<" = "<<result<<std::endl;
        b++;


    }
    return 0;
}