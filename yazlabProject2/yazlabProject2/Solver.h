#pragma once

void storeClueGiven(int sudoku[9][9]);
void storePositions();
bool goBack(int &row, int &column, int sudoku[9][9]);
bool placeNum(int row, int column, int sudoku[9][9]);
bool solveT1(int sudoku[9][9]);
bool solveT2(int sudoku[9][9]);
bool solveT3(int sudoku[9][9]);
bool solveT4(int sudoku[9][9]);