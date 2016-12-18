#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "grid.h"

using namespace std;


/* http://i.imgur.com/Acmu61Y.png
 * ------------------------
 *| x 1 x | x x x | x x x |
 *| x 8 3 | x x x | x x x |
 *| x 7 5 | x x x | x x x |
 *------------------------
 *| x x x | x x x | x x x |
 *| x x x | x x x | x x x |
 *| x x x | x x x | x x x |
 *-------------------------
 *| x x x | x x x | x x x |
 *| x x x | x x x | x x x |
 *| x x x | x x x | x x x |
 *-------------------------
 */

//Note G is not passed by reference
void genPerms(Grid g, int idx){
    //cout << g << endl;
    if (idx >= BOARD_SIZE * BOARD_SIZE){
        if (g.validBoard(true)){
            //cout << g << endl;
            cout << "solved" << endl;
            throw 0;
        }
        return;
    }

    //TODO: rewrite rule checkers
    if (!g.validBoard()){
        return;
    }

    //if the element is numeric
    if (g.eltExist(idx)){

        genPerms(g, idx + 1);
        return;
    }



    //try everything
    for (int i = 0; i < BOARD_SIZE; ++i){

        g.setElement(i + 1, idx);
        genPerms(g, idx + 1);
    }

}

int main(){

    string filename;
/*    cout << "Enter filename: ";
    cin >> filename;
    cout << endl;*/
    filename = "hard.txt";

    Grid board;
    board.loadBoard(filename);
    for (int i = 1; i <= 1000; ++i){
        cout << "Run #" << i << ": ";
        //abusing catches
        try{
            genPerms(board, 0);
        }
        catch(...) {
            i = i;
        }
        
    }

    

    return 0;
}