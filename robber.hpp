#ifndef INC_2023_SP_A_FINALPROJECT_YBPKRK_ROBBER_HPP
#define INC_2023_SP_A_FINALPROJECT_YBPKRK_ROBBER_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "jewel.h"
#include "city.h"
#include "police.h"
using namespace std;



// Desc: represents a robber
template <class Jewel>
class Robber {
private:
    static int totalLoot;   // total worth of the loot collected by ALL the robbers so far
    int id;                 // unique id
    int x, y;               // current coordinate for the robber's position in the city grid
    Jewel bag[17];          // array of jewels in the robber's bag
    int bagCount;           // current number of jewels in the robber's bag
    bool isActive;          // indicates whether the robber is still active
    bool isGreedy;

public:
    // Desc: constructor
    //  creates a robber with the given id, position, and greediness

    Robber(int id, int x, int y, bool isGreedy) : id(id), x(x), y(y), bagCount(0), isActive(true), isGreedy(isGreedy) {
        for(int i = 0; i < 17; i++){
            bag[i] = Jewel(); // set each element to the default value of Jewel, which is zero
        }
    }
    ~Robber() {
        emptyBag(); // call the emptyBag() function to delete all the jewels in the bag
    }

    // Desc: makes the bag empty
    // Pre: none
    // Post: makes the bag empty

    void emptyBag(){
        for(int i= 0; i < bagCount; i++){
            bag[i] = Jewel();
        }
        bagCount = 0;

    }
    void setTotalLoot(int x){
        Robber<Jewel>::totalLoot = x;
    }

    static int getTotalLoot(){
        return totalLoot;
    }


    // Desc: returns the total value of the jewels in the bag
    // Pre: none
    // Post: returns the total value of the jewels in the bag

     int getBagValue(){
        int Value = 0;
        for (int i = 0; i < getBagCount(); i++){
            Value += bag[i].getValue();
        }
        return Value;
    }



    // Desc: returns the total count of the jewels in the bag
    // Pre: none
    // Post: returns the total count of the jewels in the bag


    int getBagCount(){
        return bagCount;
    }


    // gets Id of the robber
    // Pre: none
    // Post: returns the id of the robber

    int getId() const {
        return id;
    }

    // gets x coordinate of the robber
    // Pre: none
    // Post: returns the x coordinate of the robber

    int getX() const {
        return x;
    }
    // gets y coordinate of the robber
    // Pre: none
    // Post: returns the y coordinate of the robber

    int getY() const {
        return y;
    }
    // description: gets active status of the robber
    // Pre: none
    // Post: returns the active status of the robber

    bool getActive() const {
        return isActive;
    }
    // sets active setus for the robber
    // takes in a bool value
    // Post: sets the active status for the robber
    void setActive(bool active) {
        isActive = active;
    }

    // desc: picks up loots
    // Pre: City object, x and y coordinates
    // Post: picks up loots, increments bagcount

    void pickUpLoot(City& city, int newX, int newY){
        if (city.getCell(newX, newY) == 'J') {
            if (bagCount < 17) {
                int value= Jewel(newX, newY).getValue();
                bag[bagCount] = Jewel(newX, newY);
                setTotalLoot(getTotalLoot() + value);
                bagCount++;

                city.setJewelCount(city.getJewelCount() - 1);
                city.setCell(newX, newY, '-');
            }
            else{
                bagCount = 17;
            }
        }
    }
    // Desc: gets random direction for robber
    // Pre: none
    // Post: returns a random direction for robber
    int robber1Direction(){
        int direction = rand() % 8;
        return direction;
    }
    // Desc: gets random direction for robber
    // Pre: none
    // Post: returns a random direction for robber
    int robber2Direction(){
        int direction = rand() % 8;
        return direction;
    }
    // Desc: gets random direction for robber
    // Pre: none
    // Post: returns a random direction for robber
    int robber3Direction(){
        int direction = rand() % 8;
        return direction;
    }
    // Desc: gets random direction for robber
    // Pre: none
    // Post: returns a random direction for robber
    int robber4Direction(){
        int direction = rand() % 8;
        return direction;
    }
    // Desc: moves the robber
    // Pre: City object, direction
    // Post: moves the robber, updates the city grid
    void move(City& city, int direction) {
        if (isActive == false){
            return;
        }
        else {
            int newX = x, newY = y;    // initialize new coordinates to current position
            switch (direction) {
                case 0: // NW
                    newX--;
                    newY--;
                    pickUpLoot(city, newX, newY);
                    break;
                case 1: // N
                    newY--;
                    pickUpLoot(city, newX, newY);
                    break;
                case 2: // NE
                    newX++;
                    newY--;
                    pickUpLoot(city, newX, newY);
                    break;
                case 3: // E
                    newX++;
                    pickUpLoot(city, newX, newY);
                    break;
                case 4: // SE
                    newX++;
                    newY++;
                    pickUpLoot(city, newX, newY);
                    break;
                case 5: // S
                    newY++;
                    pickUpLoot(city, newX, newY);
                    break;
                case 6: // SW
                    newX--;
                    newY++;
                    pickUpLoot(city, newX, newY);
                    break;
                case 7: // W
                    newX--;
                    pickUpLoot(city, newX, newY);
                    break;

            }
             // if the new coordinates are within the city grid
            if (city.checkCell(newX, newY) == true){
                if (city.getCell(newX, newY) == '1' ||city.getCell(newX, newY) == '2' || city.getCell(newX, newY) == '3' ||city.getCell(newX, newY) == '4' || city.getCell(newX, newY) == 'R' ) { // if the new coordinates are occupied by another robber
                    if (isGreedy == true){ // if the robber is greedy
                        for (int i=0; i < (bagCount /2) ; i++){ // loop through the bag
                            bag[i].setValue(0); // set the value of the jewels to 0

                        }
                    }
                    city.setCell(x, y, '-'); // set the current cell to '-'
                    x = newX; // update the coordinates
                    y = newY;
                }
                 // if the new coordinates are not occupied by another robber
                if (city.getCell(newX, newY) == '-') {
                    city.setCell(x, y, '-');
                    x = newX;
                    y = newY;
                }
                else {
                    city.setCell(x, y, '-');
                    x = newX;
                    y = newY;

                }
            }
            else {
                direction = rand() % 8;
                move(city, direction);


            }
        }
    }

};




#endif //INC_2023_SP_A_FINALPROJECT_YBPKRK_ROBBER_HPP


