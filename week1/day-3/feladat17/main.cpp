#include <iostream>

int main(int argc, char* args[]) {

    int a;
    int b;
    int c;
    int d;
    int e;
    float result;
    float result2;


    std::cout<<"adj meg öt szamot."<<std::endl;
    std::cin>>a>> b>> c>> d>> e;


    result=(a+b+c+d+e);
    std::cout<<"sum result!"<<result<<std::endl;

    result2=(result/5);

    std::cout<<"average result: "<<result2<<std::endl;

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4

    return 0;
}