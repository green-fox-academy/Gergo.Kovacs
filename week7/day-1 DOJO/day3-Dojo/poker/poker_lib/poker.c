#include <memory.h>
#include "poker.h"

int get_card_value(char card[3])
{
    if (card[0] == 'T')
        return 10;
    if (card[0] == 'J')
        return 11;
    if (card[0] == 'Q')
        return 12;
    if (card[0] == 'K')
        return 13;
    if (card[0] == 'A')
        return 14;
    return card[0] - '0';
}
int isBigger(char card1[3], char card2[3])
{
    if (get_card_value(card1) > get_card_value(card2)) {
        return 0;
    } else {
        return 1;
    }
}

int isEqual(char card1[3], char card2[3])
{
    if (get_card_value(card1) == get_card_value(card2))
        return 0;
    return 1;
}

int hasPair(char hand[5][3])
{
    for (int i = 0; i < strlen(hand); ++i) {
        int appearance = 2;
        int cardValue_1 = get_card_value(hand[i][0]);
        for (int j = 0; j < strlen(hand); ++j) {
            if (get_card_value(hand[j][0]) == cardValue_1) {
                appearance--;
            }
            if (appearance == 0) {
                return 1;
            }
        }
    }
    return 0;
}