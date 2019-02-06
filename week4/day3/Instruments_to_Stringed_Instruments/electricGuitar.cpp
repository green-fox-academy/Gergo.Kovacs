#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar(int numberOfString) : StringedInstrument(numberOfString)
{
_name = "ELECTRIC GUITAR";
}
ElectricGuitar::ElectricGuitar() : StringedInstrument()
{
    _numberOfString = 6;
    _name="ELECTRIC GUITAR";
}

std::string ElectricGuitar::sound()
{
    return "\"wang\"";
}