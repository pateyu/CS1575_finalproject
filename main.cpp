// Programmer: Yug Patel
// Date: 4/26/23.
// Student ID: 12592642
// Section: 101
// Section: 101
// Programmer 2: Mitchell Baer
// Programmer 2 ID: 18215520
// Section: 101
// Instructor: San Yeung
// Description: This program simulates a city with a police and 4 robbers. The police and robbers move around the city


#include <iostream>
#include "jewel.h"
#include "city.h"
#include "police.h"
#include "robber.hpp"



using namespace std;
template <>
int Robber<Jewel>::totalLoot = 0;

int main() {

    //Initializing everything
    City city;
    int polX = city.Xpolice();
    int polY = city.Ypolice();
    // creating the police
    Police police(5, polX, polY);

    // getting the original coordinates for all the robbers
    int R1X = city.Xrobber1();
    int R1Y = city.Yrobber1();
    int R2X = city.Xrobber2();
    int R2Y = city.Yrobber2();
    int R3X = city.Xrobber3();
    int R3Y = city.Yrobber3();
    int R4X = city.Xrobber4();
    int R4Y = city.Yrobber4();

// using the original coordinates to create the robbers
    Robber<Jewel> robber1(1, R1X, R1Y, false);
    Robber<Jewel> robber2(2, R2X, R2Y, false);
    Robber<Jewel> robber3(3, R3X, R3Y, true);
    Robber<Jewel> robber4(4, R4X, R4Y, true);
    // count to keep track of turns
    static int count = 0;


// while loop to keep the game going until the conditions are met
    while (city.getJewelCount() > 0 && Robber<Jewel>::getTotalLoot() < 438 && count < 30) {

        // if the robber is inactive, then the robber does not move
        if (robber1.getActive() == false) {
            if (police.getX() != robber1.getX() && police.getY() != robber1.getY()) {
                city.searchGrid('1','-' );
                city.setCell(robber1.getX(), robber1.getY(), '1');
            }
        }
        if (robber2.getActive() == false) {
            if (police.getX() != robber2.getX() && police.getY() != robber2.getY()) {
                city.searchGrid('2','-' );
                city.setCell(robber2.getX(), robber2.getY(), '2');
            }
        }
        if (robber3.getActive() == false) {
            if (police.getX() != robber3.getX() && police.getY() != robber3.getY()) {
                city.searchGrid('3','-' );
                city.setCell(robber3.getX(), robber3.getY(), '3');
            }
        }
        if (robber4.getActive() == false) {
            if (police.getX() != robber4.getX() && police.getY() != robber4.getY()) {
                city.searchGrid('4','-' );
                city.setCell(robber4.getX(), robber4.getY(), '4');
            }
        }


        // gets robber direction
        int robber1D = robber1.robber1Direction();
        int robber2D = robber2.robber2Direction();
        int robber3D = robber3.robber3Direction();
        int robber4D = robber4.robber4Direction();


        //if robber is active, then the robber moves
        if (robber1.getActive() == true) {
            robber1.move(city, robber1D);
            city.updateRobber1Position(R1X, R1Y, robber1.getX(), robber1.getY());
        }
        if (robber2.getActive() == true) {
            robber2.move(city, robber2D);
            city.updateRobber2Position(R2X, R2Y, robber2.getX(), robber2.getY());
        }
        if (robber3.getActive() == true) {
            robber3.move(city, robber3D);
            city.updateRobber3Position(R3X, R3Y, robber3.getX(), robber3.getY());
        }
        if (robber4.getActive() == true) {
            robber4.move(city, robber4D);
            city.updateRobber4Position(R4X, R4Y, robber4.getX(), robber4.getY());
        }

        city.updateRobber1Position(R1X, R1Y, robber1.getX(), robber1.getY());
        R1X = robber1.getX();
        R1Y = robber1.getY();



        city.updateRobber2Position(R2X, R2Y, robber2.getX(), robber2.getY());
        R2X = robber2.getX();
        R2Y = robber2.getY();


        city.updateRobber3Position(R3X, R3Y, robber3.getX(), robber3.getY());
        R3X = robber3.getX();
        R3Y = robber3.getY();


        city.updateRobber4Position(R4X, R4Y, robber4.getX(), robber4.getY());
        R4X = robber4.getX();
        R4Y = robber4.getY();





        //police arrest robbers if they move to his location
        police.arrest(robber1, city, police.getX(), police.getY());
        police.arrest(robber2, city, police.getX(), police.getY());
        police.arrest(robber3, city, police.getX(), police.getY());
        police.arrest(robber4, city, police.getX(), police.getY());



        // gets police direction
        int direction = police.moveDirection();
        int newX = polX;
        int newY = polY;
        switch (direction) {
            case 0: // NW
                newX--;
                newY--;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }

                break;
            case 1: // N
                newY--;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }


                break;
            case 2: // NE
                newX++;
                newY--;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }


                break;
            case 3: // E
                newX++;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }


                break;
            case 4: // SE
                newX++;
                newY++;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }


                break;
            case 5: // S
                newY++;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);

                    }
                }


                break;
            case 6: // SW
                newX--;
                newY++;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }


                break;
            case 7: // W
                newX--;
                if (city.checkCell(newX, newY) == true) {
                    if (city.isOccupied(newX, newY) == true) {
                        police.arrest(robber1, city, newX, newY);
                        police.arrest(robber2, city, newX, newY);
                        police.arrest(robber3, city, newX, newY);
                        police.arrest(robber4, city, newX, newY);
                    }
                }
                break;

        }

        city.searchGrid('P','-');
        city.searchGrid('R','-');

        if (city.checkMatch(robber1.getX(), robber1.getY(), robber2.getX(), robber2.getY()) == true || city.checkMatch(robber1.getX(), robber1.getY(), robber3.getX(), robber3.getY()) == true || city.checkMatch(robber1.getX(), robber1.getY(), robber4.getX(), robber4.getY()) == true) {
            city.setCell(robber1.getX(), robber1.getY(), 'R');
        }
        if (city.checkMatch(robber2.getX(), robber2.getY(), robber1.getX(), robber1.getY()) == true || city.checkMatch(robber2.getX(), robber2.getY(), robber3.getX(), robber3.getY()) == true || city.checkMatch(robber2.getX(), robber2.getY(), robber4.getX(), robber4.getY()) == true) {
            city.setCell(robber2.getX(), robber2.getY(), 'R');
        }
        if (city.checkMatch(robber3.getX(), robber3.getY(), robber1.getX(), robber1.getY()) == true || city.checkMatch(robber3.getX(), robber3.getY(), robber2.getX(), robber2.getY()) == true || city.checkMatch(robber3.getX(), robber3.getY(), robber4.getX(), robber4.getY()) == true) {
            city.setCell(robber3.getX(), robber3.getY(), 'R');
        }
        if (city.checkMatch(robber4.getX(), robber4.getY(), robber1.getX(), robber1.getY()) == true || city.checkMatch(robber4.getX(), robber4.getY(), robber2.getX(), robber2.getY()) == true || city.checkMatch(robber4.getX(), robber4.getY(), robber3.getX(), robber3.getY()) == true) {
            city.setCell(robber4.getX(), robber4.getY(), 'R');
        }



        // police movement
        police.move(city, direction);
        polX = police.getX();
        polY = police.getX();
        city.updatePolicePosition(police.getY(), police.getY());





        //Prints city grid
        city.printGrid();

        // incrementing count

        count += 1;
        cout << "Count: " << count << endl;
        if (count == 30) {
            break;
        }
    }
        //Outputing Summary of all robbers and police





        cout << endl << "Summary of the chase:" << endl << endl;




        cout <<"Total Loot taken by Robbers collectively: $" << Robber<Jewel>::getTotalLoot() << endl;

        cout << "Turns taken: " << count << endl << endl;
        cout << "Robber 1 Active(1 = yes, 0 = no): " << robber1.getActive() << endl
             << "Robber 2 Active (1 = yes, 0 = no): " << robber2.getActive() << endl
             << "Robber 3 Active (1 = yes, 0 = no): " << robber3.getActive() << endl
             << "Robber 4 Active (1 = yes, 0 = no): " << robber4.getActive() << endl;
        cout << "Police id: " << police.getId() << endl;
        cout << "Confiscated jewels amount: $" << police.getConfiscatedLoot() << endl;
        cout << "Final number of robbers caught: " << police.getTotalArrests() << endl << endl;

        cout << "Ordinary Robber id: " << robber1.getId() << endl;
        cout << "Final number of jewels picked up: " << robber1.getBagCount() << endl;
        cout << "jewels worth: $" << robber1.getBagValue() << endl << endl;

        cout << "Ordinary Robber id: " << robber2.getId() << endl;
        cout << "Final number of jewels picked up: " << robber2.getBagCount() << endl;
        cout << "jewels worth: $" << robber2.getBagValue() << endl << endl;

        cout << "Greedy Robber id: " << robber3.getId() << endl;
        cout << "Final number of jewels picked up: " << robber3.getBagCount() << endl;
        cout << "jewels worth: $" << robber3.getBagValue() << endl << endl;


        cout << "Greedy Robber id: " << robber4.getId() << endl;
        cout << "Final number of jewels picked up: " << robber4.getBagCount() << endl;
        cout << "jewels worth: $" << robber4.getBagValue() << endl;


        return 0;
    }



