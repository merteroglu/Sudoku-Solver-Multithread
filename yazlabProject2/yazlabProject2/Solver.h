#pragma once

void storeClueGiven(int sudoku[9][9]);
void storePositions();
bool goBack(int &row, int &column, int sudoku[9][9]);
bool placeNum(int row, int column, int sudoku[9][9]);
bool solve(int sudoku[9][9]);