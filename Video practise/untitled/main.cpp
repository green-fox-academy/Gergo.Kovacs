#include <iostream>
struct two_numbers
{
  int a;
  float b;
};
int main()
{

    two_numbers nums;
    nums.a = 5;
    nums.b = 8.3;

    two_numbers *p_nums = &nums;//& - ráállítom a nums-ra

    p_nums->a = 6;    // - ugyan az -   (*p_nums).a = 6;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}