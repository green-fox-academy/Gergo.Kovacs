#ifndef PATROLSTATION_CAR_H
#define PATROLSTATION_CAR_H


class Car {


    int gasAmount;
    int capacity;
public:
    Car(int amount, int tank);

    bool isfull();

    void fill();

};


#endif //PATROLSTATION_CAR_H
