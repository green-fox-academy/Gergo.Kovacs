//
// Created by Kovacs család on 2019-01-30.
//

#ifndef FLEETOFTHING_THING_H
#define FLEETOFTHING_THING_H


#include <string>

class Thing
{
public:
    Thing(const std::string& name);

    void complete();
    std::string toString();

private:
    std::string _name;
    bool _completed;
};




#endif //FLEETOFTHING_THING_H
