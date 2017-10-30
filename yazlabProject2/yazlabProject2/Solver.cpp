#include "Solver.h"
#include "Checker.h"
#include "FileProcessing.h"

int isClueGiven[9][9] = { 0 };
int prevPosition[9][9][2];
int step1 = 0, step2 = 0, step3 = 0, step4 = 0 ;

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

//-------------------------------------------------------------- //

// Thread 1
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

// Thread 2
void storePositions2() {
	int temprow, tempcolumn;
	temprow = -1;
	tempcolumn = -1;

	for (int row = 8; row >= 0; row--)
	{
		for (int column = 8; column >= 0; column--)
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

// Thread 3
void storePositions3() {
	int temprow, tempcolumn;
	temprow = -1;
	tempcolumn = -1;

	for (int column = 0; column < 9; column++)
	{
		for (int row = 0; row < 9; row++)
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

// Thread 4
void storePositions4() {
	int temprow, tempcolumn;
	temprow = -1;
	tempcolumn = -1;

	for (int column = 8; column >= 0; column--)
	{
		for (int row = 8; row >= 0; row--)
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


//-------------------------------------------------------------- //

// Thread 1
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

// Thread 2
bool goBack2(int &row, int &column, int sudoku[9][9])
{
	int trow, tcolumn;

	if (row == 8 && column == 8)
		return false;
	sudoku[row][column] = 0;

	trow = prevPosition[row][column][0];
	tcolumn = prevPosition[row][column][1];
	tcolumn += 1;

	row = trow;
	column = tcolumn;

	return true;
}

// Thread 3
bool goBack3(int &row, int &column, int sudoku[9][9])
{
	int trow, tcolumn;

	if (row == 0 && column == 0)
		return false;
	sudoku[row][column] = 0;

	trow = prevPosition[row][column][0];
	tcolumn = prevPosition[row][column][1];
	trow -= 1;

	row = trow;
	column = tcolumn;

	return true;
}

// Thread 4
bool goBack4(int &row, int &column, int sudoku[9][9])
{
	int trow, tcolumn;

	if (row == 8 && column == 8)
		return false;
	sudoku[row][column] = 0;

	trow = prevPosition[row][column][0];
	tcolumn = prevPosition[row][column][1];
	trow += 1;

	row = trow;
	column = tcolumn;

	return true;
}

//-------------------------------------------------------------- //


bool placeNum(int row, int column,int sudoku[9][9])
{
	if (isClueGiven[row][column] == 1)
		return true;

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

//-------------------------------------------------------------- //


// Thread 1
bool solveT1(int sudoku[9][9])
{
	storeClueGiven(sudoku);
	storePositions();

	FileProcessing^ writer = gcnew FileProcessing("anims/thread1.txt");

	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			if (!placeNum(row, column,sudoku))
			{
				sudoku[row][column] = 0;
				if (!goBack(row, column, sudoku)) {
					writer->writerClose();
					return false;
					}
			}
			else {
				writer->writeFile(sudoku);
				step1++;
			}
			
		}
	}
	writer->writerClose();
	return true;
}

// Thread 2
bool solveT2(int sudoku[9][9])
{
	storeClueGiven(sudoku);
	storePositions2();
	FileProcessing^ writer = gcnew FileProcessing("anims/thread2.txt");

	for (int row = 8; row >= 0; row--)
	{
		for (int column = 8; column >= 0; column--)
		{
			if (!placeNum(row, column, sudoku))
			{
				sudoku[row][column] = 0;
				if (!goBack2(row, column, sudoku)) {
					writer->writerClose();
					return false;
				}
					
			}
			else {
				writer->writeFile(sudoku);
				step2++;
			}
			
		}
	}
	writer->writerClose();
	return true;
}

// Thread 3
bool solveT3(int sudoku[9][9])
{
	storeClueGiven(sudoku);
	storePositions3();

	FileProcessing^ writer = gcnew FileProcessing("anims/thread3.txt");
	
	for (int column = 0; column < 9; column++)
	{
		for (int row = 0; row < 9; row++)
		{
			if (!placeNum(row, column, sudoku))
			{
				sudoku[row][column] = 0;
				if (!goBack3(row, column, sudoku)) {
					writer->writerClose();
					return false;
				}
			}
			else {
				writer->writeFile(sudoku);
				step3++;
			}
			
		}
	}
	writer->writerClose();
	return true;
}

// Thread 4
bool solveT4(int sudoku[9][9])
{
	storeClueGiven(sudoku);
	storePositions4();
	FileProcessing^ writer = gcnew FileProcessing("anims/thread4.txt");

	for (int column = 8; column >= 0; column--)
	{
		for (int row = 8; row >= 0; row--)
		{
			if (!placeNum(row, column, sudoku))
			{
				sudoku[row][column] = 0;
				if (!goBack4(row, column, sudoku)) {
					writer->writerClose();
					return false;
				}
			}
			else {
				writer->writeFile(sudoku);
				step4++;
			}
			
		}
	}
	writer->writerClose();
	return true;
}

int getStepT1() {
	return step1;
}

int getStepT2() {
	return step2;
}

int getStepT3() {
	return step3;
}

int getStepT4() {
	return step4;
}