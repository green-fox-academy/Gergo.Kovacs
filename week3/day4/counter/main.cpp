#include <iostream>

void counter(int count);

int main()
{
    int num;
    std::cout << "give me a number: " << std::endl;
    std::cin >> num;

    counter(num);

    return 0;
}

void counter(int count)
{

    if (count >= 1) {
        std::cout << "number: " << count << std::endl;
        counter(count - 1);
    }
}
// Write a recursive function that takes one parameter: n and counts down from n.
