#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int result = a+b;

    int *add_op = &result;

    std::cout<<*add_op<<std::endl;





    return 0;
}