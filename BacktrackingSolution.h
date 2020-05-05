//
// Created by Fidelia Nawar on 4/30/20.
//

#ifndef INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H
#define INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H


#include <stdbool.h>
#include <stdio.h>
#include <vector>

using std::vector;

class BacktrackingSolution{

    vector<vector<int>> chessBoard;
    int numQueens = 0;

private:
    bool placeQueens(int colIndex);
    bool isValid(int rowIndex, int colIndex);
    void printBoard(std::ofstream&);

public:
    BacktrackingSolution(int numQueens);
    void solve(std::ofstream&);
};
#endif //INC_20S_3353_PA04_BACKTRACKINGSOLUTION_H