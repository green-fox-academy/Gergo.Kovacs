#include <iostream>


int result1 (int *list, int size, int search) {

    int a =0;

    for (int i = 0; i < size; i++) {
        if (list[i] == search) {
            a = i+1;
        }
    }

    return a;
}

int main() {
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    int array[3] = {1, 2, 3};
    int size = 3;



    int result = result1(array, size, 2);
    std::cout<<result<<std::endl;




    return 0;
}