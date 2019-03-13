#include <iostream>

int main(int argc, char* args[]) {

    int a = 6;
    int s =(7*17);
    std::cout<<"how many hours is spent with coding?"<<std::endl;
    std::cout<< a*s<<std::endl;

    int w = (5*17);
    std::cout<<"Coding on workdays?"<<std::endl;
    std::cout<<a*w<<std::endl;

    float h = 52.;
    std::cout<<(a*w) / (h*17)<<std::endl;
    std::cout<<(a*w) /(h*17) *100 <<"%"<<std::endl;



    // Print how many hours is spent with coding in a semester by an attendee,

    // if the attendee only codes on workdays.

    // Print the percentage of the coding hours in the semester if the average

    // working hours weekly is 52
    return 0;
}