#include <iostream>
#include "instrument.h"
#include "strigedInstrument.h"
#include "electricGuitar.h"
#include "bassGuitar.h"
#include "violin.h"

int main()
{
    std::cout << "Test 1, create Electric Guitar, Bass Guitar and Violin with default strings." << std::endl;
    ElectricGuitar guitar;
    BassGuitar bassGuitar;
    Violin violin;

    std::cout<<std::endl;

    std::cout<< "Test 1 Play" << std::endl;
    guitar.play();
    bassGuitar.play();
    violin.play();

    std::cout<<std::endl;

    std::cout << "Test 2, create Electric Guitar, Bass Guitar with 7 and 5 strings ." << std::endl;
    ElectricGuitar guitar2(7);
    BassGuitar bassGuitar2(5);

    std::cout<<std::endl;

    std::cout << "Test 2 Play" << std::endl;
    guitar2.play();
    bassGuitar2.play();

    return 0;
}