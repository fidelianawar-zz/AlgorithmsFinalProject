//
// Created by Fidelia Nawar on 4/29/20.
//

#include "TrivialSolution.h"
#include "BacktrackingSolution.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main(){

    std::ofstream outputFile, outputFileClear;
    std::ofstream outputMetrics, dataOutputClear;

    outputFileClear.open("output.txt", std::ios::out | std::ios::trunc); // clear contents
    dataOutputClear.open("outputMetrics.txt", std::ios::out | std::ios::trunc); // clear contents

    outputFile.open("output.txt", std::ios_base::app); //make the file appendable
    outputMetrics.open("outputMetrics.txt", std::ios_base::app);

    TrivialSolution trivial{8};
    BacktrackingSolution backtrack{8};

    outputFile << "Trivial Solution: ";
    auto trivialStart = std::chrono::steady_clock::now();
    trivial.solveNQueens(outputFile);
    auto trivialEnd = std::chrono::steady_clock::now();

    outputFile << endl << endl << "Sophisticated Solution: " << endl;
    auto sophisticatedStart = std::chrono::steady_clock::now();
    backtrack.solve(outputFile);
    auto sophisticatedEnd = std::chrono::steady_clock::now();

    outputMetrics << "Trivial Time: " << std::chrono::duration_cast<std::chrono::microseconds>(trivialEnd - trivialStart).count() << " us" << endl;
    outputMetrics << "Sophisticated Time: " << std::chrono::duration_cast<std::chrono::microseconds>(sophisticatedEnd - sophisticatedStart).count() << " us";

    return 0;
}