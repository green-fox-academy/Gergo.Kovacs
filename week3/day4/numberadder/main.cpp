#include <iostream>

int sum(int num);
int main()
{
    int num;
    std::cout << "give me a number: ";
    std::cin >> num;

    std::cout<<sum(num)<<std::endl;

    return 0;
}

int sum(int num){
    if (num<=1){
        return 1;
    } else {
        return (num +sum(num -1));
    }
}

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.
