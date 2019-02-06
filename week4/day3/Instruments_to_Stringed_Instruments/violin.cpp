#include <iostream>
#include "violin.h"

Violin::Violin(int numberOfString) : StringedInstrument(numberOfString)
{
_name = "VIOLIN";
}
Violin::Violin() : StringedInstrument()
{
    _numberOfString=4;
    _name = "VIOLIN";
}
std::string Violin::sound(){
    return "Screech";
}