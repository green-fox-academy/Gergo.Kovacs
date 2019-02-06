#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRIGEDINSTRUMENT_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRIGEDINSTRUMENT_H
#include "instrument.h"
#include <iostream>

class StringedInstrument : public Instrument
{
 public:
  StringedInstrument(int numberOfString);
  StringedInstrument();
  virtual std::string sound()=0;
  void play() override;
 protected:
  int _numberOfString;
};

#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRIGEDINSTRUMENT_H
