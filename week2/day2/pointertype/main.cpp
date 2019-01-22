
#include <iostream>
int main ()
{
// Create a pointer for each variable and print out the memory addresses of that variables
// Print out the values of the pointers 
    int a = 31;

    int *p_a = &a;

    double b = 432.2;

    double *p_b=&b;

    std::string name = "Bob";

    std::string *p_n=&name;

    std::cout<<p_a<<" "<<p_b<<" "<<p_n<<" "<<std::endl;
    std::cout<<*p_a<<" "<<*p_b<<" "<<*p_n<<" "<<std::endl;


return 0;
}
