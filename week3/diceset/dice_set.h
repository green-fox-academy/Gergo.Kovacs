#ifndef DICESET_DICE_SET_H
#define DICESET_DICE_SET_H

#include <iostream>
#include <vector>

class DiceSet
{
public:

    DiceSet();

    void roll();

    void roll(int i);

    std::vector<int> getCurrent() const;

    int getCurrent(int i) const;

private:
    std::vector<int> dices;
};


#endif //DICESET_DICE_SET_H
