#include <iostream>

#include "dice_set.h"

int main(int argc, char* args[])
{

    DiceSet diceSet;
    diceSet.roll();

    for (int k =0; k<6; ++k){
        std::cout<<diceSet.getCurrent(k)<<" ";
    }

    std::cout<<""<<std::endl;

    for (int i = 0; i<6; ++i){
        while (diceSet.getCurrent(i)!=6){
            diceSet.roll(i);
    }

    }
    for (int j = 0; j<6; ++j){
        std::cout<<diceSet.getCurrent(j)<<" ";
    }

    return 0;
}


// You have a `DiceSet` class which has a list for 6 dices
//    // You can roll all of them with roll()
//    // Check the current rolled numbers with getCurrent()
//    // You can reroll with roll()
//    // Your task is to roll the dices until all of the dices are 6