#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int array[] = {1,2,3,4,5};


    int *p_array= array;

    //int *p_array = reinterpret_cast<int *>(&array);

    for (int i = 0; i <sizeof(array)/sizeof(array[0]); i++){
        std::cout<<array[i]<<std::endl;
    }


    return 0;
}