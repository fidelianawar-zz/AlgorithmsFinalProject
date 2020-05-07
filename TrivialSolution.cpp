//
// Created by Fidelia Nawar on 5/4/20.
//

#include "TrivialSolution.h"
#include <iostream>
#include <fstream>

using std::cout;

//initializes the 2D vector of row/column size = numQueens
TrivialSolution::TrivialSolution(int numQueens) : numQueens(numQueens) {
    chessBoard.resize(numQueens);

    //setting the size of the board based upon integer passed into constructor
    for (auto &chessRow : chessBoard) {
        chessRow.resize(numQueens);
    }
}

bool TrivialSolution::isValid(int row, int column, vector<int> &queens) {
    //checks if adjacent/diagonal columns/rows make the position invalid
    for(int i=0; i<row; i++){
        if(queens[i] == column){
            return false;
        }
        if(queens[i]-column == i-row){
            return false;
        }
        if(queens[i]-column == row-i){
            return false;
        }
    }
    return true;
}

void TrivialSolution::placeQueens(int row, vector<int> &q, vector<vector<string>> &result) {
    if(row == numQueens){ //check to see if end of row is reached
        vector<string> tempVec(numQueens, string(numQueens, '0'));
        for(int i=0; i<numQueens; i++) {
            tempVec[i][q[i]] = '1';
        }
        result.push_back(tempVec);
    } else { //for each row, check to see if position of queen is valid
        for(int i=0; i<numQueens; i++) {
            if(isValid(row, i, q)){ //if it is valid, mark this position
                q[row] = i;
                placeQueens(row+1,q, result); //check the adjacent row using same process
            }
        }
    }
}

vector<vector<string>> TrivialSolution::solveNQueens(std::ofstream& outputFile) {
    vector<vector<string>> chessBoard;
    vector<int> q(numQueens, 0); //initialize temp vec of all 0s
    placeQueens(0, q, chessBoard);
    //formatting to print out the result in consistent manner
    for(int i = 0; i < chessBoard.size(); i++){
        for(int j = 0; j < chessBoard[i].size(); j++) {
            if((j/numQueens)==0){
                outputFile << endl;
            }
            for(char c : chessBoard[i][j]){
                outputFile << " " << c <<" ";
            }
        }
        outputFile << endl;

    }
    return chessBoard;
}