#include <iostream>
#include <fstream>
#include <string>


    int line_number(std::string x) {

        std::ifstream theFile(x);
        std::string line;
        int y=0;
        if (theFile.is_open()) {
            while (std::getline(theFile, line)){
                //std::cout<<line<<std::endl;
                y += 1;
            }

            return y;
        }
}


int main () {


    std::cout << "give me the file name." << std::endl;

    std::string filename;

    std::cin>>filename;


    std::cout <<line_number(filename)<<std::endl;

    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    return 0;
}