#pragma once

bool checkRow(int row, int num, int sudoku[9][9]);
bool checkRow(int s[9][9]);
bool checkColumn(int column, int num, int sudoku[9][9]);
bool checkColumn(int s[9][9]);
bool check(int s[9]);
bool checkSquare(int row, int column, int num, int sudoku[9][9]);
bool checkSquare(int s[9][9]);
bool checkSolution(int sudoku[9][9]);