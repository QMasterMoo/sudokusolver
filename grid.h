#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <string>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

const int BOARD_SIZE = 9;
const int BOARD_SQR  = 3;

class Grid{

private:
    int board[BOARD_SIZE][BOARD_SIZE];

    //test if rowNum is a valid row
    bool validRow(int rowNum, bool countX = false);

    //test if column is valid
    bool validCol(int colNum, bool countX = false);

    //test if box num is valid
    /* 0 1 2
     * 3 4 5
     * 6 7 8
     */
    bool validBox(int num, bool countX = false);



    //test with number N
    bool testN(int n);


public:
    Grid();

    //run all private tests
    bool validBoard(bool countX = false);

    void loadBoard(string &fileName);

    void setElement(int val, int row, int col);
    
    void setElement(int val, int idx);

    bool eltExist(int idx);

    void solve();

    //overloaded output operator
    friend ostream& operator<<(ostream &out, Grid &g);
};


#endif

/*
 * 0 1 2
 * 3 4 5
 * 6 7 8
 ===
 * 0 1 2 3 4 5 6 7 8
 */