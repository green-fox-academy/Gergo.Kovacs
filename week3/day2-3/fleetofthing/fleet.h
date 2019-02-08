

#ifndef FLEETOFTHING_FLEET_H
#define FLEETOFTHING_FLEET_H


#include <vector>
#include <string>

#include "thing.h"

class Fleet
{
public:
    Fleet();

    void add(const Thing& thing);
    std::string toString();

private:
    std::vector<Thing> things;
};


#endif //FLEETOFTHING_FLEET_H
