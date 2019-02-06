#include "strigedInstrument.h"

StringedInstrument::StringedInstrument(int numberOfString)
{
    _numberOfString = numberOfString;
}

StringedInstrument::StringedInstrument(){
    _numberOfString = 0;
}
void StringedInstrument::play()
{
std::cout<<_name<<", a "<<_numberOfString<<"-Stringed instrument that goes "<<sound()<<std::endl;
};
