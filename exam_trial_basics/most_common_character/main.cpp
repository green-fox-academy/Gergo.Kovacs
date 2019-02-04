#include <iostream>
#include <fstream>

std::string mostCommonChar(std::string text)
{
    int max = 0;
    int count = 0;
    std::string maxCharcter;
    for (int q = ' '; q <= '~'; q++) {
        count = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == q)
                count++;
        }

        if (count > max) {
            max = count;
            maxCharcter = q;
        }
    }

    return maxCharcter;

}
int main()
{
    std::ifstream exampleFile;
    size_t pos;
    std::string line;
    exampleFile.open("countchar.txt");

    if (exampleFile.is_open()) {
        while (getline(exampleFile, line)) {
        //    pos = line.find(mostCommonChar());
        }
    } else {
        std::cout << "File does not exist!" << std::endl;
    }
    exampleFile.close();

    return 0;
}