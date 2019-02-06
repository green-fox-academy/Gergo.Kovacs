#include "bassGuitar.h"
#include <iostream>

BassGuitar::BassGuitar(int numberOfString) : StringedInstrument(numberOfString)
{
_name = "Bass Guitar";
}
BassGuitar::BassGuitar() : StringedInstrument()
{
    _numberOfString=4;
    _name= "BASS GUitar";
}
std::string BassGuitar::sound()
{
    return " \"Duum-duum-duum\" ";
}
