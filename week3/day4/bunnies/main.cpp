#include <iostream>

int bunnies(int num_bunny, int num_ears);
int main() {

    int bunny;
    int num_ears=2;
    std::cout<<"give me the number of bunnies: "<<std::endl;
    std::cin>>bunny;

    std::cout<<"number of bunnies: "<<" "<<bunny<<" how many ears they have: "<<bunnies(bunny,num_ears);
    return 0;
}

int bunnies(int num_bunny, int num_ears){
    if(num_bunny<=1){
        return num_ears;{}
    } else {
        return (num_ears+bunnies(num_bunny-1,num_ears));
    }
}


// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
