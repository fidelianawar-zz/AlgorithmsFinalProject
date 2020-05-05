//
// Created by Fidelia Nawar on 5/4/20.
//

#include "TrivialSolution.h"
#include <iostream>

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

void TrivialSolution::helper(int row, vector<int> &q, vector<vector<string> > &result) {
    if(row == numQueens){
        vector<string> tempVec(numQueens, string(numQueens, '0'));
        for(int i=0; i<numQueens; i++) {
            tempVec[i][q[i]] = '1';
        }
        result.push_back(tempVec);
    } else {
        for(int i=0; i<numQueens; i++) {
            if(isValid(row, i, q)){
                q[row] = i;
                helper(row+1, q, result);
            }
        }
    }
}

vector<vector<string>> TrivialSolution::solveNQueens() {
    vector<int> q(numQueens, 0);
    helper(0, q, chessBoard);
    for(int i = 0; i < chessBoard.size(); i++){
        for(int j = 0; j < chessBoard[i].size(); j++) {
            if((j/numQueens)==0){
                cout << endl;
            }
            for(char c : chessBoard[i][j]){
                std::cout << " " << c <<" ";
            }
        }
        cout << endl;
    }
    return chessBoard;
}