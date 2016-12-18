#include "grid.h"

ostream& operator<<(ostream &out, Grid &g){
    
    for (int i = 0; i < BOARD_SIZE; ++i){
        //Print horizontal rule
        if (i % 3 == 0)
            out << "-------------------------\n";
        
        for (int j = 0; j < BOARD_SIZE; ++j){
            //Print vertical bars
            if (j % 3 == 0)
                out << "| ";
            out << g.board[i][j] << ' ';
        }
        out << '|';
        out << endl;
    }
    out << "-------------------------" << endl;
    return out;
}


Grid::Grid(){
    emptyCount = 0;
}

void Grid::loadBoard(string &fileName){

    fstream fin(fileName.c_str());

    char c;
    int idx = 0;
    while (fin >> c){
        //Load in board with valid input
        board[idx / 9][idx % 9] = c;
        ++idx;
        if (c == 'x')
            ++emptyCount;
    }

    fin.close();  
}

bool Grid::validRow(int rowNum, bool countX){
    bool exists[BOARD_SIZE] = {false};

    for (int i = 0; i < BOARD_SIZE; ++i){
        //case if we have an x
        if (board[rowNum][i] == 'x'){
            if (countX)
                return false;
            continue;
        }

        //check if our board already had the same digit
        if (exists[board[rowNum][i] - '1'])
            return false;

        exists[board[rowNum][i] - '1'] = true;
    }
    return true;
}

bool Grid::validCol(int colNum, bool countX){
    bool exists[BOARD_SIZE] = {false};

    for (int i = 0; i < BOARD_SIZE; ++i){
        //case if we have an x
        if (board[i][colNum] == 'x'){
            if (countX)
                return false;
            continue;
        }

        //check if our board already had the same digit
        if (exists[board[i][colNum] - '1'])
            return false;

        exists[board[i][colNum] - '1'] = true;
    }
    return true;
}

bool Grid::validBox(int num, bool countX){
    //these values will offset and let us select the correct box
    int rowOffset;
    int colOffset;
    switch(num){
        case 0:
            rowOffset = 0;
            colOffset = 0;
            break;
        case 1:
            rowOffset = 3;
            colOffset = 0;
            break;
        case 2:
            rowOffset = 6;
            colOffset = 0;
            break;
        case 3:
            rowOffset = 0;
            colOffset = 3;
            break;
        case 4:
            rowOffset = 3;
            colOffset = 3;
            break;
        case 5:
            rowOffset = 6;
            colOffset = 3;
            break;
        case 6:
            rowOffset = 0;
            colOffset = 6;
            break;
        case 7:
            rowOffset = 3;
            colOffset = 6;
            break;
        case 8:
            rowOffset = 6;
            colOffset = 6;
            break;
    }

    bool exists[BOARD_SIZE] = {false};
    for (int i = 0; i < (int)sqrt(BOARD_SIZE); ++i){
        for (int j = 0; j < (int)sqrt(BOARD_SIZE); ++j){

            if (board[i + rowOffset][j + colOffset] == 'x'){
                if (countX)
                    return false;
                continue;
            }

            //check if our board already had the same digit
            if (exists[board[i + rowOffset][j + colOffset] - '1'])
                return false;

            exists[board[i + rowOffset][j + colOffset] - '1'] = true;
        }
    }
    return true;
}

bool Grid::validBoard(bool countX){
    for (int i = 0; i < BOARD_SIZE; ++i){
        if (!validRow(i) || !validCol(i) || !validBox(i))
            return false;
    }
    return true;
}

void Grid::setElement(char val, int row, int col){
    board[row][col] = val;
    emptyCount--;
}

void Grid::setElement(char val, int idx){
    board[idx / 9][idx % 9] = val;
    emptyCount--;
}

bool Grid::eltIsNumeric(int idx){
    return board[idx / 9][idx % 9] <= '9' && board[idx / 9][idx % 9] >= '1';
}
