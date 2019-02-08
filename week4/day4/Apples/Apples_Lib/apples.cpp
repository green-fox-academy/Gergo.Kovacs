#include <iostream>
#include "apples.h"
#include <string>
#include <vector>

std::string Apples::getApple()
{
    return "apples";
}
int Apples::sum(std::vector<int> numbers)
{
    int sum=0;
    for (int i =0; i<numbers.size(); ++i){
        sum+=numbers[i];
    }
    return sum;
}