#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#include <iostream>
#include "strigedInstrument.h"


class ElectricGuitar : public StringedInstrument
{
 public:
  ElectricGuitar();
  ElectricGuitar(int numberOfString);
      std::string sound() override;


};
#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
