
#ifndef INC_2023_SP_A_FINALPROJECT_YBPKRK_JEWEL_H
#define INC_2023_SP_A_FINALPROJECT_YBPKRK_JEWEL_H

class Jewel {
private:
    int value;      // worth of the jewel
    int x, y;
    int jewelIndex;// coordinate of the jewel in the city grid
public:
    // constructor
    // the worth of the jewel is the sum of its x and y coordinates
    // the coordinates are passed in as parameters
    Jewel(int x, int y);

    // default constructor
    // the worth of the jewel is zero
    Jewel();

    int setJewelIndex(int x);

    // Description: returns the worth of the jewel
    // Pre: none
    // Post: returns the worth of the jewel
    int getValue() const;

    // Description: sets the worth of the jewel
    // Pre: none
    // Post: sets the worth of the jewel
    int setValue(int v);
};



#endif //INC_2023_SP_A_FINALPROJECT_YBPKRK_JEWEL_H
