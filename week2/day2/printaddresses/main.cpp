#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int array[] = {1,2,3,4,5};

    int *p_array = array;

    for (int i = 0; i <sizeof(array)/sizeof(array[0]); i++){
        std::cout<<&array[i]<<std::endl;
    }


    return 0;
}