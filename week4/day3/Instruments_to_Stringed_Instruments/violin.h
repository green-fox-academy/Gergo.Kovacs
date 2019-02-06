#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#include "strigedInstrument.h"

class Violin : public StringedInstrument
{
 public:
  Violin(int numberOfString);
  Violin();
  std::string sound() override;
};

#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
