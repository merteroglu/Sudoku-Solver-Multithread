#include "Checker.h"

int temp[9];

bool checkRow(int row, int num, int sudoku[9][9])
{
	int foundnum = 0;
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == num) {
			foundnum = 1;
			break;
		}
	}
	if (foundnum == 1)
		return false;
	else
		return true;
}

bool checkRow(int s[9][9]) {
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++)
			temp[j] = s[i][j];

		if (check(temp) == false)
			return false;
	}
	return true;
}

bool checkColumn(int column, int num, int sudoku[9][9])
{
	int foundnum = 0;
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][column] == num) {
			foundnum = 1;
			break;
		}
	}
	if (foundnum == 1)
		return false;
	else
		return true;
}

bool checkColumn(int s[9][9]) {
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++)
			temp[j] = s[j][i];

		if (check(temp) == false)
			return false;
	}
	return true;
}

bool check(int s[9]) {
	int lineartemp;
	for (int i = 0; i<9; i++) {
		lineartemp = s[i];
		for (int j = i + 1; j<9; j++) { 
			if (s[j] == lineartemp)
				return false;
		}
	}
	return true;
}

bool checkSquare(int row, int column, int num, int sudoku[9][9])
{
	int foundnum = 0;
	int startIndexRow = (row / 3) * 3;
	int startIndexColumn = (column / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sudoku[startIndexRow + i][startIndexColumn + j] == num) {
				foundnum = 1;
				break;
			}
		}
	}
	if (foundnum == 1)
		return false;
	else
		return true;
}

bool checkSquare(int s[9][9]) {
	int i,j,column,row,k;
	
	for (column = 0; column <= 6; column += 3) {
		for (row = 0; row <= 6; row += 3) {
			for (k = 0, i = 0; i<3; i++) {
				for (j = 0; j<3; j++)
					temp[k++] = s[row + i][column + j];
			}
			if (check(temp) == 0)
				return false;
		}
	}

	return true;
}

bool checkSolution(int sudoku[9][9])
{
	if (!checkRow(sudoku) || !checkColumn(sudoku) || !checkSquare(sudoku))
		return false;
	else
		return true;
}