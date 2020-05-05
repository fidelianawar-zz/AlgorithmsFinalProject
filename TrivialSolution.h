//
// Created by Fidelia Nawar on 4/30/20.
//

#ifndef ALGORITHMSFINALPROJECT_TRIVIALSOLUTIONS_H
#define ALGORITHMSFINALPROJECT_TRIVIALSOLUTIONS_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class TrivialSolution {

private:
    vector<vector<int>> chessBoard;
    int numQueens;

public:
    TrivialSolution(int numQueens);
    bool isValid(int row, int column, vector<int>& queens);
    void helper(int row, vector<int>&q, vector<vector<string>>& result);
    vector<vector<string>> solveNQueens(std::ofstream&);
};
#endif //ALGORITHMSFINALPROJECT_TRIVIALSOLUTIONS_H