

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "jewel.h"


using namespace std;



// constructor
Jewel::Jewel(int x, int y) : value((x+1) + (y+1)), x(x), y(y) {}

// default constructor
Jewel::Jewel() : value(0) {}

int Jewel::setJewelIndex(int x) {
    jewelIndex = x;
    return jewelIndex;
}

// Description: returns the worth of the jewel
// Pre: none
// Post: returns the worth of the jewel
int Jewel::getValue() const {
    return value;
}

// Description: sets the worth of the jewel
// Pre: none
// Post: sets the worth of the jewel
int Jewel::setValue(int v) {
    value = v;
    return value;
}
