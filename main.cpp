//
// Created by Fidelia Nawar on 4/29/20.
//

#include "TrivialSolution.h"
#include "BacktrackingSolution.h"
#include <iostream>
#include <chrono>

int main(){

    TrivialSolution solution;
    BacktrackingSolution backtrack{8};

    cout << "Trivial Solution: ";
    auto trivialStart = std::chrono::steady_clock::now();
    solution.solveNQueens(8);
    auto trivialEnd = std::chrono::steady_clock::now();

    cout << endl << endl << "Sophisticated Solution: " << endl;
    auto sophisticatedStart = std::chrono::steady_clock::now();
    backtrack.solve();
    auto sophisticatedEnd = std::chrono::steady_clock::now();

    cout << endl;
    cout << "Trivial Time: " << std::chrono::duration_cast<std::chrono::microseconds>(trivialEnd - trivialStart).count() << " us" << endl;
    cout << "Sophisticated Time: " << std::chrono::duration_cast<std::chrono::microseconds>(sophisticatedEnd - sophisticatedStart).count() << " us";

    return 0;
}