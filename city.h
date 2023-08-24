
#ifndef INC_2023_SP_A_FINALPROJECT_YBPKRK_CITY_H
#define INC_2023_SP_A_FINALPROJECT_YBPKRK_CITY_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "jewel.h"

using namespace std;


class City {
private:
    int jewelCount;
    char grid[10][10];
    int robber1X, robber1Y, robber2X, robber2Y, robber3X, robber3Y, robber4X, robber4Y, policeX, policeY;
    int jewelPositions[47][2];
public:
    City();
    void searchGrid(char x, char y);
    static bool checkMatch(int a, int b, int x, int y);
    bool isOccupied(int x, int y);
    static bool checkCell(int x, int y);
    void printGrid();
    void setCell(int x, int y, char c);
    int  getJewelCount();
    char getCell(int i, int j);
    int setJewelCount(int x);
    const int Xpolice();
    const int Ypolice();
    const int Xrobber1();
    const int Yrobber1();
    const int Xrobber2();
    const int Yrobber2();
    const int Xrobber3();
    const int Yrobber3();
    const int Xrobber4();
    const int Yrobber4();
    int getJewelPositions(int i, int j);
    void setJewelPositions(int i, int j, int x);
    void setJewelIndex(Jewel &jewel, int i);
    void updateRobber1Position(int x, int y, int newX, int newY);
    void updateRobber2Position(int x, int y, int newX, int newY);
    void updateRobber3Position(int x, int y, int newX, int newY);
    void updateRobber4Position(int x, int y, int newX, int newY);
    void updatePolicePosition(int x, int y);
};

#endif //INC_2023_SP_A_FINALPROJECT_YBPKRK_CITY_H
