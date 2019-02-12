#include <iostream>
#include <vector>

void calculator(char operation, int operand1, int operand2);

int main(int argc, char *args[])
{
    float num1, num2;
    char op;

    std::cout << "Plase type in the expression: " << std::endl;
    std::cin >> op >> num1 >> num2;

    calculator(op, num1, num2);

    return 0;
}
void calculator(char operation, int operand1, int operand2)
{
    switch (operation) {
        case '+' : std::cout << operand1 + operand2 << std::endl;
            break;
        case '-' : std::cout << operand1 - operand2 << std::endl;
            break;
        case '*' : std::cout << operand1 * operand2 << std::endl;
            break;
        case '/' : std::cout << operand1 / operand2 << std::endl;
            break;
        case '%': std::cout << operand1 % operand2 << std::endl;
        default:std::cout << "no no" << std::endl;
    }
}