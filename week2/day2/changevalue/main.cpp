#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;

    float *p_temp = &temperature;

    *p_temp = 17.5;

    std::cout<<*p_temp<<std::endl;





    return 0;
}