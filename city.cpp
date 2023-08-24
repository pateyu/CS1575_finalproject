#include "city.h"
#include "jewel.h"
#include <iostream>
#include <cstdlib>

using namespace std;
City::
City() {
    jewelCount = 0;
// initialize grid with empty spaces
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '-';
    }
}

// seed the random number generator
srand(85);

// place jewels randomly
while (jewelCount < 47) {
        int i = rand() % 10;
        int j = rand() % 10;
        if (grid[i][j] == '-') {
            grid[i][j] = 'J';
            jewelPositions[jewelCount][0] = i;
            jewelPositions[jewelCount][1] = j;
            jewelCount++;
        }
    }

    cout<< "JEWEL COUNT: " << jewelCount    << endl;

    // place police randomly
    int i = rand() % 10;
    int j = rand() % 10;
    while (grid[i][j] == 'J') {
        i = rand() % 10;
        j = rand() % 10;
    }
    grid[i][j] = 'P';
    policeX = i;
    policeY = j;

    // place robbers randomly
    for (int k = 1; k < 5; k++) {
        int i = rand() % 10;
        int j = rand() % 10;
        while (grid[i][j] == 'P' || grid[i][j] == 'J') {
            i = rand() % 10;
            j = rand() % 10;
        }
        if (grid[i][j] == '2' || grid[i][j] == '3' || grid[i][j] == '4' || grid[i][j] == '1' || grid[i][j] == 'R') { // check if the cell already contains a robber
            grid[i][j] = '6'; // change to 'R' if there are already robbers in the cell
        }
        else {
            char c = k +'0';
            grid[i][j] = c; // change to the robber number if the cell is empty
        }
        // update the position of the current robber
        if (k == 1) {
            robber1X = i;
            robber1Y = j;
        }
        else if (k == 2) {
            robber2X = i;
            robber2Y = j;
        }
        else if (k == 3) {
            robber3X = i;
            robber3Y = j;
        }
        else if (k == 4) {
            robber4X = i;
            robber4Y = j;
        }
    }
    // print the grid before turns
    cout << "Starting Grid: " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl; // add newline character
    }
    cout << endl << endl;



}

// Description: searches grid for character
// Pre: gets 2 characters
// Post: replaces all instances of first character with second character

void City::searchGrid(char x, char y){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j]==x){
                grid[i][j]=y;
            }
        }
    }

}

// desc: checks the grid if any of the positions are the same
// pre: none
// post: returns true if positions are the same
bool City::checkMatch(int a,int b,int x, int y){
    if(a==x && b==y){
        return true;
    }
    else{
        return false;
    }
}


// Description: checks if city cell is occupied by a robber
// Pre: gets x and y of grid
// Post: returns true if cell is occupied by a robber
bool City::isOccupied(int x, int y){
    if (grid[x][y] == '1' || grid[x][y] == '2' || grid[x][y] == '3' || grid[x][y] == '4' || grid[x][y] == 'R'){
        return true;
    }
    else{
        return false;
    }
}

// checks if city cell is in grid
// Pre: gets x and y of grid
// Post: returns true if cell is in grid
bool City::checkCell(int x, int y){
    if(x<0 || x>9 || y<0 || y>9){
        return false;
    }
    else{
        return true;
    }
}


//Desc: Prints the entire city grid
//Post: none
//Pre: Prints city grid character by character = 10x10
void City::printGrid(){
    for (auto & i : grid) {
        for (int j = 0; j < 10; j++) {
            cout << i[j] << " ";
        }
        cout << endl; // add newline character
    }
    cout << "Jewel Count: " << jewelCount   << endl;
}
// Description: sets the number of jewels in the city
// Pre: none
// Post: jewelcount is equal to x parameter
int City::setJewelCount(int x){
    return jewelCount = x;
}

//Desc: returns police x coordinate
//Post: none
//Pre: returns police x coordinate

const int City::Xpolice(){
    return policeX;
}

//Desc: returns police y coordinate
//Post: none
//Pre: returns police y coordinate

const int City::Ypolice(){
    return policeY;
}
//Desc: returns the robber 1 x coordinate
//Post: none
//Pre: returns robber 1 x coordinate

const int City::Xrobber1(){
    return robber1X;
}
//Desc: returns the robber 1 y coordinate
//Post: none
//Pre: returns robber 1 y coordinate

const int City::Yrobber1(){
    return robber1Y;
}
//Desc: returns the x coordinate of robber 2
//Post: none
//Pre:  returns the x coordinate of robber 2

const int City::Xrobber2(){
    return robber2X;
}
//Desc: returns the Y coordinate of robber 2
//Post: none
//Pre: returns the Y coordinate of robber 2

const int City::Yrobber2(){
    return robber2Y;
}
// Desc: returns the x coordinate of robber 3
// Post: none
// Pre: returns the x coordinate of robber 3
const int City::Xrobber3(){
    return robber3X;
}

// Desc: returns the y coordinate of robber 3
// Post: none
// Pre: returns the y coordinate of robber 3

const int City::Yrobber3(){
    return robber3Y;
}
// Desc: returns the x coordinate of robber 4
// Post: none
// Pre: returns the x coordinate of robber 4

const int City::Xrobber4(){
    return robber4X;
}
// Desc: returns the y coordinate of robber 4
// Post: none
// Pre: returns the y coordinate of robber 4

const int City::Yrobber4(){
    return robber4Y;
}
// Desc: returns the number of jewels in the city
// Pre: none
// Post: returns the number of jewels in the city

int City::getJewelCount(){
    return jewelCount;
}
// Desc: returns the jewel position
// Pre: none
// Post: returns the jewel position
int City::getJewelPositions(int i, int j) {
    return jewelPositions[i][j];
}

// Desc: sets the jewel index
// Pre: none
// Post: sets the jewel index
void City::setJewelIndex(Jewel& jewel, int x){
    jewel.setJewelIndex(x);
}

// Desc: sets the jewel position
// Pre: none
// Post: sets the jewel position
void City::setJewelPositions(int i, int j, int x) {
    jewelPositions[i][j] = x;
}

// Desc: returns the character at the given position
// Pre: none
// Post: returns the character at the given position

char City::getCell(int i, int j){
    return grid[i][j];
}

// Desc: sets the character at the given position
// Pre: none
// Post: sets the character at the given position
void City::setCell(int i, int j, char c) {
    grid[i][j] = c;
}


// Desc: returns the number of turns
// Pre: none
// Post: returns the number of turns
void City::updatePolicePosition(int x, int y){
    policeX = x;
    policeY = y;
}
// Desc: updates the position of the robber
// Pre: none
// Post: updates the position of the robber
void City::updateRobber1Position(int x, int y, int newX, int newY) {
    grid[x][y] = '-';
    if (grid[newX][newY] == '2' || grid[newX][newY] == '3' || grid[newX][newY] == '4'){
        grid[newX][newY] = 'R';
    }
    else if(grid[newX][newY] == 'R'){
        grid[newX][newY] = 'R';
    }
    else{
        grid[newX][newY] = '1';
    }
    robber1X=newX;
    robber1Y=newY;
}
// Desc: updates the position of the robber
// Pre: none
// Post: updates the position of the robber
void City::updateRobber2Position(int x, int y, int newX, int newY) {
    grid[x][y] = '-';
    if (grid[newX][newY] == '1' || grid[newX][newY] == '3' || grid[newX][newY] == '4'){
        grid[newX][newY] = 'R';
    }
    else if(grid[newX][newY] == 'R'){
        grid[newX][newY] = 'R';
    }
    else{
        grid[newX][newY] = '2';
    }
    robber2X=newX;
    robber2Y=newY;

}
// Desc: updates the position of the robber
// Pre: none
// Post: updates the position of the robber
void City::updateRobber3Position(int x, int y, int newX, int newY) {

    grid[x][y] = '-';
    if (grid[newX][newY] == '1' || grid[newX][newY] == '2' || grid[newX][newY] == '4'){
        grid[newX][newY] = 'R';
    }
    else if(grid[newX][newY] == 'R'){
        grid[newX][newY] = 'R';
    }
    else{
        grid[newX][newY] = '3';
    }
    robber3X=newX;
    robber3Y=newY;
}
// Desc: updates the position of the robber
// Pre: none
// Post: updates the position of the robber

void City::updateRobber4Position(int x, int y, int newX, int newY) {
    grid[x][y] = '-';
    if (grid[newX][newY] == '1' || grid[newX][newY] == '2' || grid[newX][newY] == '3'){
        grid[newX][newY] = 'R';
    }
    else if(grid[newX][newY] == 'R'){
        grid[newX][newY] = 'R';
    }
    else {
        grid[newX][newY] = '4';
    }
    robber1X=newX;
    robber1Y=newY;
}



