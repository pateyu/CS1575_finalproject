
#include "police.h"
#include "jewel.h"
#include "robber.hpp"


// Desc: constructor
// Pre:  takes in police id, x, y
// Post: creates a police with the given id and position


Police::Police(int id, int x, int y) : id(id), x(x), y(y), confiscatedLoot(0), totalArrests(0) {}


// Desc: returns the id of the police
// Pre: none
// Post: returns the id of the police

int Police::getId() const {
    return id;
}

// Desc: returns the x coordinate of the police
// Pre: none
// Post: returns the x coordinate of the police

int Police::getX() const {
    return x;
}
// Desc: returns the y coordinate of the police
// Pre: none
// Post: returns the y coordinate of the police


int Police::getY() const {
    return y;
}
// Desc: returns the total worth of the loot confiscated so far
// Pre: none
// Post: returns the total worth of the loot confiscated so far

int Police::getConfiscatedLoot() const {
    return confiscatedLoot;
}
// Desc: returns the total number of robbers caught by the police
// Pre: none
// Post: returns the total number of robbers caught by the police

int Police::getTotalArrests() const {
    return totalArrests;
}


//Desc: Arrests the Robber and empties their bag into the Police's confiscated Loot
//Pre: robber, city, x and y coordinates
// Post: Updates confiscated loot and loot bag total - deactivates robber and increases total arrests

void Police::arrest(Robber<Jewel> &robber, City &city, int x, int y) {
    if (x == robber.getX() && y == robber.getY()) {
        if (robber.getActive() == true) {
            city.setCell(x, y, 'P');
            confiscatedLoot += robber.getBagValue();
            robber.setTotalLoot(robber.getTotalLoot()-robber.getBagValue());
            robber.emptyBag();
            city.setCell(x, y, 'P');
            robber.setActive(false);
            totalArrests++;
        }
        else{
            city.setCell(x, y, 'P');
        }

    }
}

// Desc: gets random direction for police
// Pre: none
// Post: returns a random direction for police
int Police::moveDirection(){
    int direction = rand() % 8; // random number between 0 and 7
    return direction;
}

// picks up jewels for police
// Pre: city, x and y coordinates
// Post: updates confiscated loot and jewel count
void Police::pickUpLootPolice(City& city, int newX, int newY){
    if (city.getCell(newX, newY) == 'J') {
        confiscatedLoot += (newX+newY);
        city.setJewelCount(city.getJewelCount() - 1);

    }
}

// Desc: moves the police in the city
// Pre: city
// Post: moves the police in the city


void Police::move(City& city, int direction) {
    int newX = x, newY = y;    // initialize new coordinates to current position
    switch (direction) {
        case 0: // NW
            newX--;
            newY--;
            pickUpLootPolice(city, newX, newY);
            break;
        case 1: // N
            newY--;
            pickUpLootPolice(city, newX, newY);
            break;
        case 2: // NE
            newX++;
            newY--;
            pickUpLootPolice(city, newX, newY);
            break;
        case 3: // E
            newX++;
            pickUpLootPolice(city, newX, newY);
            break;
        case 4: // SE
            newX++;
            newY++;
            pickUpLootPolice(city, newX, newY);
            break;
        case 5: // S
            newY++;
            pickUpLootPolice(city, newX, newY);
            break;
        case 6: // SW
            newX--;
            newY++;
            pickUpLootPolice(city, newX, newY);
            break;
        case 7: // W
            newX--;
            pickUpLootPolice(city, newX, newY);
            break;
    }
// check if new coordinates are within the city limits


    if (city.checkCell(newX, newY) == true){

        city.setCell(x, y, '-');
        city.setCell(newX, newY, 'P');
        city.updatePolicePosition(newX, newY);
        x = newX;
        y = newY;
    }
    else{
        direction= moveDirection();
        move(city, direction);
    }
}

