#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a=24;
    int out = 0;
    // if a is even increment out by one


    if (a%2==0){
        std::cout << out++ << std::endl;
    } else {
        std::cout << out << std::endl;
    }

    int b = 9;
    std::string out2 ="sweet";
    std::string out3 ="less";
    std::string out4 ="more";

    if ((10 <= b) && (a<=20)){
        std::cout<< out2 <<std::endl;
    }
    else if (b<10){
        std::cout<< out3 <<std::endl;
    }
    else if (b>20){
        std::cout<< out4 <<std::endl;
    }


    // if b is between 10 and 20 set out2 to "Sweet!"
    // if less than 10 set out2 to "Less!",
    // if more than 20 set out2 to "More!"




    int c = 123;
    int credits = 20;
    bool isBonus = false;
    int c1;
    int c2;
    c1=c-2;
    c2=c-1;

    if ((credits >= 50) && (isBonus=false)){

        std::cout<<c1<<std::endl;

    } else if ((credits <50) && (isBonus=false)){
        std::cout<<c2<<std::endl;
    } else if (isBonus=true){
        std::cout<<c<<std::endl;
    }
    // if credits are at least 50,
    // and isBonus is false decrement c by 2
    // if credits are smaller than 50,
    // and isBonus is false decrement c by 1
    // if isBonus is true c should remain the same

    return 0;
}

int d = 8;
int time = 120;
std::string out3 = "";
// if d is dividable by 4
// and time is not more than 200
// set out3 to "check"
// if time is more than 200
// set out3 to "Time out"
// otherwise set out3 to "Run Forest Run!"

std::cout << out3 << std::endl;

return 0;
}