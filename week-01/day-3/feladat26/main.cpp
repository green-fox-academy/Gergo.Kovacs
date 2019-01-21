#include <iostream>

int main(int argc, char* args[]) {
    int a;
    int b;

    std::cout<<"give me a number"<<std::endl;
    std::cin>>a;

    std::cout<<"give me the second number"<<std::endl;
    std::cin>>b;

    if (a>b) {
        std::cout << "the second number should be bigger" << std::endl;
    }  for (int i =a; i < b; i++){
            std::cout<<i<<std::endl;
        }


    return 0;
}