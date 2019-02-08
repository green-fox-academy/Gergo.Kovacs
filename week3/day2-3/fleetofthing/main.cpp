
#include <iostream>
#include "thing.h"
#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;


    Thing first("Get milk");
    fleet.add(first);

    Thing second("Remove the obstacles");
    fleet.add(second);

    Thing third("Stand up");
    third.complete();
    fleet.add(third);

    Thing four("Eat lunch");
    four.complete();
    fleet.add(four);



    std::cout << fleet.toString() << std::endl;
    return 0;
}

// Create a fleet of things to have this output:
// 1. [ ] Get milk
// 2. [ ] Remove the obstacles
// 3. [x] Stand up
// 4. [x] Eat lunch
