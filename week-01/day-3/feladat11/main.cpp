#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a = 3;
    // make the "a" variable's value bigger by 10
    std::cout << a+10 <<std::endl;


    int b = 100;
    // make b smaller by 7

    std::cout << b-7 << std::endl;

    int c = 44;
    // please double c's value

    std::cout << c*c << std::endl;

    int d = 125;
    // please divide by 5 d's value

    std::cout << d/5 << std::endl;

    int e = 8;
    // please cube of e's value

    std::cout << e*e*e << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)
bool ertek= true;
bool erteknincs=false;
    if (f1>f2) {
        std::cout << ertek << std::endl;
    } else {
        std::cout<< erteknincs << std::endl;
    }


    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    bool bacon = true;
    if ((g2*g2)>g1){
        std::cout <<bacon <<std::endl;
    } else {
        std::cout<<!bacon<<std::endl;
    }
    int h = 135798745;
    bool divisor = true;
    if ((h%11)==0) {
        std::cout << divisor <<std::endl;
    } else {
        std::cout<< !divisor<<std::endl;
    }
    // tell if it has 11 as a divisor (print as a boolean)

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    bool higher = true;
    if ((i1>(i2*i2)) && (i1<(i2*i2*i2))){
        std::cout<<higher<<std::endl;
    } else {
        std::cout<<!(higher)<<std::endl;
    }
    int j = 1521;
    bool asd = ((j%3)==0) || ((j%5)==0);
    std::cout<<asd<<std::endl;
    // tell if j is dividable by 3 or 5 (print as a boolean)

    std::string k = "Apple";
    //fill the k variable with its content 4 times

    std::cout << k+" "+k+" "+k+" "+k << std::endl;

    return 0;
}