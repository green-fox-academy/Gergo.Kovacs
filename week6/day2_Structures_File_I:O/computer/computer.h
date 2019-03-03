#ifndef COMPUTER_COMPUTER_H
#define COMPUTER_COMPUTER_H
#include <stdio.h>
#include <stdlib.h>

struct computer
{
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
};

typedef struct
{
  float cpu_speed_GHz;
  int ram_size_GB;
  int bits;
} notebook_t;

#endif //COMPUTER_COMPUTER_H
