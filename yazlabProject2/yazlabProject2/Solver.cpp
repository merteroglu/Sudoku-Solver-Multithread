#include "Solver.h"
#include "Checker.h"

int isClueGiven[9][9] = { 0 };
int prevPosition[9][9][2];

void storeClueGiven(int sudoku[9][9]) {
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (sudoku[row][column] != 0)
				isClueGiven[row][column] = 1;
		}
	}
}

void storePositions() {
	int temprow, tempcolumn;
	temprow = -1;
	tempcolumn = -1;

	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (isClueGiven[row][column] == 0)
			{
				prevPosition[row][column][0] = temprow;
				prevPosition[row][column][1] = tempcolumn;
				temprow = row;
				tempcolumn = column;
			}
		}
	}
}

bool goBack(int &row, int &column,int sudoku[9][9])
{
	int trow, tcolumn;

	if (row == 0 && column == 0)
		return false;
	sudoku[row][column] = 0;

	trow = prevPosition[row][column][0];
	tcolumn = prevPosition[row][column][1];
	tcolumn -= 1;

	row = trow;
	column = tcolumn;

	return true;
}

bool placeNum(int row, int column,int sudoku[9][9])
{
	if (isClueGiven[row][column] == 1)
		return 1;

	for (int num = sudoku[row][column] + 1; num <= 9; num++)
	{
		if (checkRow(row, num,sudoku) && checkColumn(column, num, sudoku) && checkSquare(row, column, num, sudoku))
		{
			sudoku[row][column] = num;
			return true;
		}
	}

	sudoku[row][column] = 0;

	return false;
}

bool solve(int sudoku[9][9])
{
	storeClueGiven(sudoku);
	storePositions();

	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (!placeNum(row, column,sudoku))
			{
				sudoku[row][column] = 0;
				if (!goBack(row, column,sudoku))
					return 0;
			}
		}
	}

	return 1;
}