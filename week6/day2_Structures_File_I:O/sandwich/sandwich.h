#ifndef SANDWICH_SANDWICH_H
#define SANDWICH_SANDWICH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[30];
  float price;
  float weight;
} sandwich_t;
int sandwich_price_calcluator(sandwich_t, int order);

#endif //SANDWICH_SANDWICH_H
