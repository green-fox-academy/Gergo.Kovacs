#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int osszseconds =(((currentHours*60)*60)+(currentMinutes*60)+currentSeconds);

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    std::cout<<(60*60*24)-osszseconds<<std::endl;


    return 0;
}