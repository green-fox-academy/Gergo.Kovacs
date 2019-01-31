#include <iostream>

int sum(int n);

int main()
{

    int n = 0;
    std::cout << "give me  number: " << std::endl;
    std::cin >> n;
    sum(n);
    std::cout<<sum(n)<<std::endl;
    return 0;
}
int sum(int n)
{
    if (n <= 10) { // mivel 1-es számrendszerben dolgozunk és 10 hatványaival ezért kell megadni hogy kisebb mint 10
        return 1;
    } else {
        return (n % 10 + sum(n / 10));
    }
}



// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
