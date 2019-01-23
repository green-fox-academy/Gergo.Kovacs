#include <iostream>
#include <fstream>
#include <string>

int main() {


    std::ofstream geriFile;

    geriFile.open("myfile");

    geriFile << "Kovacs Gergő"<< std::endl;


    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    return 0;
}