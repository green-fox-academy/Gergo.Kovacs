
#include <iostream>

int main(int argc, char* args[]) {

    int a;
    int b;

    std::cout<<"mennyi lány van a bulin?"<<std::endl;
    std::cin>>a;

    std::cout<<"mennyi fiú van a bulin?"<<std::endl;
    std::cin>>b;

    if ((a+b>=20) && (a==b)){
        std::cout<<"the party is excellent"<<std::endl;

    } else if ((a+b>=20) && (a<b)){
        std::cout<<"quite cool party!"<<std::endl;
    } else if (a+b<20 && (a!=0)){
        std::cout<<"avarege party!"<<std::endl;
    } else if (a==0){
        std::cout<<"sausage party"<<std::endl;
    }

    // It should print: Quite cool party!
    // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
    //
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people

    return 0;
}