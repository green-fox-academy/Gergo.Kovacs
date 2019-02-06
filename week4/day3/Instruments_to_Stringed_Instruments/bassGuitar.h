#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#include "strigedInstrument.h"

class BassGuitar : public StringedInstrument
{
 public:
BassGuitar(int numerOfString);
BassGuitar();
std::string sound() override;
};

#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
