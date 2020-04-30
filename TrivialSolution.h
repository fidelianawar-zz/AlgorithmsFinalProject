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
    int N = 0;

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<vector<string>> ret;
        vector<int> q(N, 0);
        helper(0, q, ret);
        for(int i = 0; i < ret.size(); i++){
            for(int j = 0; j < ret[i].size(); j++) {
                if(j == 0){
                    cout << "['";
                }
                else if((j/4)==0 && (j != ret[i].size()-1)){
                    cout << "','";
                }
                else if(j == ret[i].size()-1){
                    cout << "'],";
                }
                std::cout << ret[i][j];
            }
        }
        return ret;
    }

    bool isValid(int row, int col, vector<int>& q) {
        for(int i=0; i<row; i++){
            if(q[i] == col) return false;
            if(q[i]-col == row-i)   return false;
            if(q[i]-col == i-row)   return false;
        }
        return true;
    }

    void helper(int row, vector<int>&q, vector<vector<string>>& ret) {
        if(row == N){
            vector<string> tem(N, string(N, '.'));
            for(int i=0; i<N; i++) {
                tem[i][q[i]] = 'Q';
            }
            ret.push_back(tem);

        } else {
            for(int i=0; i<N; i++) {
                if(isValid(row, i, q)){
                    q[row] = i;
                    helper(row+1, q, ret);
                }
            }
        }
    }
};

#endif //ALGORITHMSFINALPROJECT_TRIVIALSOLUTIONS_H
