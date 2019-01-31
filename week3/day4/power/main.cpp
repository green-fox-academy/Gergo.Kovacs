
#include <iostream>

int exp(int value, int value2);
int main()
{
    int value = 0;
    int value2 = 0;
    std::cout << "give me a number: " << std::endl;
    std::cin >> value>>value2;

    std::cout << exp(value, value2) << std::endl;
    return 0;
}

int exp(int value, int value2)
{
    if (value2 <= 1) {
        return value;
    } else {
        return (value * exp(value,(value2 - 1)));
    }
}
// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).