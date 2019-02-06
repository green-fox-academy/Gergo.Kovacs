#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
#include <iostream>

class Instrument
{
 public:
  virtual void play() = 0;
 protected:
  std::string _name;
};

#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
