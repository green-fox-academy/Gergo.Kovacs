#include <iostream>
#include <fstream>
#include <string>

int main () {

    std::ifstream thefile("my-file.txt");

    std::string line;
    while (std::getline(thefile, line)){
        std::cout << line << '!'<<std::endl;
    }
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory




    return 0;
}