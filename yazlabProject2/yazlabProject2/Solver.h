#pragma once

void storeClueGiven(int sudoku[9][9]);
void storePositions();
void storePositions2();
void storePositions3();
void storePositions4();
bool goBack(int &row, int &column, int sudoku[9][9]);
bool goBack2(int &row, int &column, int sudoku[9][9]);
bool goBack3(int &row, int &column, int sudoku[9][9]);
bool goBack4(int &row, int &column, int sudoku[9][9]);
bool placeNum(int row, int column, int sudoku[9][9]);
bool solveT1(int sudoku[9][9]);
bool solveT2(int sudoku[9][9]);
bool solveT3(int sudoku[9][9]);
bool solveT4(int sudoku[9][9]);
int getStepT1();
int getStepT2();
int getStepT3();
int getStepT4();