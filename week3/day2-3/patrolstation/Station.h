#ifndef PATROLSTATION_STATION_H
#define PATROLSTATION_STATION_H

#include "Car.h"

class Station {
    int gasAmount;
public:
    Station(int amount);

    int fill(Car tank);


};


#endif //PATROLSTATION_STATION_H
