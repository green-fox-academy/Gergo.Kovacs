#include <iostream>
#include <string>

int main(int argc, char *args[])
{
    std::string myList = "My todo:\n";
    std::string todoText = " - Buy milk\n";
    std::string todogame = " - Download games\n";
    std::string gamename = "\t - Diablo";

    std::cout << myList << todoText << todogame << gamename << std::endl;

    return 0;
}

// Add "My todo:" to the beginning of the todoText
// Add " - Download games" to the end of the todoText
// Add " - Diablo" to the end of the todoText but with indentation

// Expected outpt:

// My todo:
//  - Buy milk
//  - Download games
//      - Diablo