#ifndef POKER_POKER_H
#define POKER_POKER_H
#include <stdlib.h>
#include <stdio.h>

int get_card_value(char card[3]);
int isBigger(char card1[3],char card2[3]);
int isEqual(char card1[3],char card2[3]);
int hasPair(char[5][3]);
#endif //POKER_POKER_H
