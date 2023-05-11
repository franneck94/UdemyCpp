#include <iostream>

#include "Weapons.h"

int main()
{
    Axe axe{"Great dwarfen axe", 12.0F, 1.2F};
    Longbow longbow{"Bow of the emperer", 25.0F, 0.5F};

    axe.attack();
    longbow.attack();

    return 0;
}
