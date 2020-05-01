//
// Created by Fidelia Nawar on 4/30/20.
//

#ifndef INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H
#define INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H

#define N 12

#include <stdbool.h>
#include <stdio.h>
#include <vector>

using std::vector;

class BacktrackingSolution {
public:

//print output of board
    void printSolution(vector<vector<int>>& board) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf(" %d ", board[i][j]);
            cout << endl;
        }
    }
    bool isSafe(vector<vector<int>>& board, int row, int col) {
        int i, j;
        for (i = 0; i < col; i++){
            if (board[row][i]){
                return false;
            }
        }
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;
        return true;
    }

    bool solveNQUtil(vector<vector<int>>& board, int col) {
        if (col >= N)
            return true;
        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                if (solveNQUtil(board, col + 1))
                    return true;
                board[i][col] = 0; // BACKTRACK
            }
        }
        return false;
    }

    bool solveNQ(int n) {
        vector<vector<int> > vec(N, vector<int>(N, 0));
        if (solveNQUtil(vec, 0) == false) {
            printf("Solution does not exist");
            return false;
        }
        printSolution(vec);
        return true;
    }

};
#endif //INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H
