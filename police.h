
#ifndef INC_2023_SP_A_FINALPROJECT_YBPKRK_POLICE_H
#define INC_2023_SP_A_FINALPROJECT_YBPKRK_POLICE_H
#include <iostream>

#include "jewel.h"

#include "city.h"

#include "robber.hpp"

using namespace std;
class Police {
private:
    int id; // unique id
    int x, y; // current coordinate for the police's position in the city grid
    int confiscatedLoot; // current count of the total worth of the loot confiscated so far
    int totalArrests; // total number of robbers caught by the police

public:
    Police(int id, int x, int y);
    int getId() const;
    int getX() const;
    int getY() const;
    int getConfiscatedLoot() const;
    int getTotalArrests() const;
    void arrest(Robber<Jewel> &robber, City &city, int x, int y);
    int moveDirection();
    void pickUpLootPolice(City &city, int newX, int newY);
    void move(City &city, int direction);
};


#endif //INC_2023_SP_A_FINALPROJECT_YBPKRK_POLICE_H
