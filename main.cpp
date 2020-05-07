//
// Created by Fidelia Nawar on 4/29/20.
//

#include "TrivialSolution.h"
#include "BacktrackingSolution.h"
#include <iostream>
#include <fstream>
#include <chrono>

std::ofstream outputFile;
std::ofstream outputMetrics;

void performCalculations(int i, TrivialSolution solution, BacktrackingSolution solution1);

int main(){

    std::ofstream outputFileClear;
    std::ofstream dataOutputClear;
    outputFileClear.open("output.txt", std::ios::out | std::ios::trunc); // clear contents
    dataOutputClear.open("outputMetrics.txt", std::ios::out | std::ios::trunc); // clear contents

    outputFile.open("output.txt", std::ios_base::app); //make the file appendable
    outputMetrics.open("outputMetrics.txt", std::ios_base::app);


    //i keep this ranging from 5-14 for time's sake. increasing x<15 takes 30 seconds, x<16 takes 30 minutes, etc.
    for(int x = 5; x <7; x++){
        TrivialSolution trivial{x};
        BacktrackingSolution backtrack{x};
        performCalculations(x, trivial, backtrack);
    }

    return 0;
}

void performCalculations(int i, TrivialSolution trivial, BacktrackingSolution backtrack) {

    outputFile << "Trivial Solution for " << i << "x" << i << " board:";
    auto trivialStart = std::chrono::steady_clock::now();
    trivial.solveNQueens(outputFile);
    auto trivialEnd = std::chrono::steady_clock::now();

    outputFile << endl << endl << "Sophisticated Solution for " << i << "x" << i << " board:" << endl;
    auto sophisticatedStart = std::chrono::steady_clock::now();
    backtrack.solveNQueens(outputFile);
    auto sophisticatedEnd = std::chrono::steady_clock::now();

    outputFile << endl << endl << "------------------------------------------------------------------" << endl;

    outputMetrics << "Runtime for " << i << "x" << i << " board: " << endl;
    outputMetrics << "Trivial: " <<
        std::chrono::duration_cast<std::chrono::microseconds>(trivialEnd - trivialStart).count() << " us" << endl;
    outputMetrics << "Sophisticated: " <<
        std::chrono::duration_cast<std::chrono::microseconds>(sophisticatedEnd - sophisticatedStart).count() << " us";

    outputMetrics << endl << endl;
}
