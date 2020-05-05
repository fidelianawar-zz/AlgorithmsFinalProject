//
// Created by Fidelia Nawar on 5/4/20.
//

#include "BacktrackingSolution.h"
#include <iostream>

using std::cout;

//initializes the 2D vector of row/column size = numQueens
BacktrackingSolution::BacktrackingSolution(int numQueens) : numQueens(numQueens) {
    chessBoard.resize(numQueens);

    //setting the size of the board based upon integer passed into constructor
    for (auto &chessRow : chessBoard) {
        chessRow.resize(numQueens);
    }
}

//solve the problem
void BacktrackingSolution::solve() {

    //solve starting with first column
    if (placeQueens(0)) {
        printBoard();
    } else {
        cout << "There is no solution \n";
    }
}

//set queens in spots on board that are valid
bool BacktrackingSolution::placeQueens(int colIndex) {

    //if the number of queens is = to the column index, then we have searched the entire board and found valid spots
    if (colIndex == numQueens) {
        return true;
    }

    //check all rows in each column
    for (int rowIndex = 0; rowIndex < numQueens; rowIndex++) {
        if (isValid(rowIndex, colIndex)) { //check if location cannot be attacked by another queen
            chessBoard[rowIndex][colIndex] = 1; //valid spot for queen
            if (placeQueens(colIndex + 1)) { //check if queen can be placed in next column and set to true if so
                return true;
            }
            //BACKTRACk -failed to put queen in column, so we must reinitialize the location back to 0 (no queen)
            //iterate considering the next row
            chessBoard[rowIndex][colIndex] = 0;
        }
    }
    //all rows considered without any result so there is no solution
    //backtrack here again to maybe change the position of previous queens
    return false;
}

//check if a queen can be placed in a spot or not
bool BacktrackingSolution::isValid(int rowIndex, int colIndex) const {

    //checks to make sure queens are not in the same row
    for (int i = 0; i < colIndex; i++) {
        if (chessBoard[rowIndex][i] == 1) {
            return false;
        }
    }

    //checks to see if queens are diagonal from top left to bottom right
    for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--) {
        if (chessBoard[i][j] == 1) {
            return false;
        }
    }

    //checks to see if queens are diagonal from top right to bottom left
    for (int i = rowIndex, j = colIndex; i < numQueens && j >= 0; i++, j++) {
        if (chessBoard[i][j] == 1) {
            return false;
        }
    }

    //queen can be safely put in the spot
    return true;
}

//prints out contents of board displaying the queens
void BacktrackingSolution::printBoard() const {
    for (int i = 0; i < chessBoard.size(); i++) {
        for (int j = 0; j < chessBoard.size(); j++) {
            if (chessBoard[i][j] == 1) {
                cout << " 1 "; //queen
            } else {
                cout << " 0 "; //empty space
            }
        }
        cout << std::endl;
    }
}