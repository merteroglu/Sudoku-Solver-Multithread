#pragma once
#include "Controller.h"
#include "FileProcessing.h"
#include <Windows.h>

public ref class Solver {
public:

	array<int^, 2>^ isClueGiven = gcnew array<int^, 2>(9, 9);
	array<int^, 3>^ prevPosition = gcnew array<int^, 3>(9, 9, 2);
	array<int^, 2>^ sudokuMatrix = gcnew array<int^, 2>(9, 9);
	
	int workingTime;

	Controller^ checker = gcnew Controller();
	FileProcessing^ writer;

	bool finish = false;
	
	int step1 = 0, step2 = 0, step3 = 0, step4 = 0;

	Solver(int sudoku[9][9]) {
		fillClueGiven();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudokuMatrix[i, j] = sudoku[i][j];
			}
		}
	}

	void fillClueGiven() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				isClueGiven[i, j] = 0;
			}
		}
	}

	void storeClueGiven(int sudoku[9][9]) {
		for (int row = 0; row < 9; row++)
		{
			for (int column = 0; column < 9; column++)
			{
				if (sudoku[row][column] != 0)
					isClueGiven[row,column] = 1;
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
				if ((int)isClueGiven[row,column] == 0)
				{
					prevPosition[row,column,0] = temprow;
					prevPosition[row,column,1] = tempcolumn;
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
				if ((int)isClueGiven[row,column] == 0)
				{
					prevPosition[row,column,0] = temprow;
					prevPosition[row,column,1] = tempcolumn;
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
				if ((int)isClueGiven[row,column] == 0)
				{
					prevPosition[row,column,0] = temprow;
					prevPosition[row,column,1] = tempcolumn;
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
				if ((int)isClueGiven[row,column] == 0)
				{
					prevPosition[row,column,0] = temprow;
					prevPosition[row,column,1] = tempcolumn;
					temprow = row;
					tempcolumn = column;
				}
			}
		}
	}


	//-------------------------------------------------------------- //

	// Thread 1
	bool goBack(int &row, int &column, int sudoku[9][9])
	{
		int trow, tcolumn;

		if (row == 0 && column == 0)
			return false;
		sudoku[row][column] = 0;

		trow = (int) prevPosition[row,column,0];
		tcolumn = (int) prevPosition[row,column,1];
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

		trow = (int) prevPosition[row,column,0];
		tcolumn = (int) prevPosition[row,column,1];
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

		trow = (int) prevPosition[row,column,0];
		tcolumn = (int) prevPosition[row,column,1];
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

		trow = (int) prevPosition[row,column,0];
		tcolumn = (int) prevPosition[row,column,1];
		trow += 1;

		row = trow;
		column = tcolumn;

		return true;
	}

	//-------------------------------------------------------------- //


	bool placeNum(int row, int column, int sudoku[9][9])
	{
		if ((int)isClueGiven[row,column] == 1)
			return true;

		for (int num = sudoku[row][column] + 1; num <= 9; num++)
		{
			if (checker->checkRow(row, num, sudoku) && checker->checkColumn(column, num, sudoku) && checker->checkSquare(row, column, num, sudoku))
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
	void solveT1()
	{
		SYSTEMTIME st; 
		SYSTEMTIME ft;
		GetSystemTime(&st);
		int sudoku[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				  sudoku[i][j] = (int) sudokuMatrix[i, j];
			}
		}
		fillClueGiven();
		storeClueGiven(sudoku);
		storePositions();
		step1 = 0;
		writer = gcnew FileProcessing("anims/thread1.txt");

		for (int row = 0; row < 9; row++)
		{
			for (int column = 0; column < 9; column++)
			{
				if (!placeNum(row, column, sudoku))
				{
					sudoku[row][column] = 0;
					if (!goBack(row, column, sudoku)) {
						writer->writerClose();
						finish = false;
					}
				}
				else {
					writer->writeFile(sudoku);
					step1++;
				}

			}
		}
		writer->writerClose();
		GetSystemTime(&ft);
		workingTime = (ft.wSecond - st.wSecond) * 1000 + (ft.wMilliseconds - st.wMilliseconds);
		finish = true;
	}

	// Thread 2
	void solveT2()
	{
		SYSTEMTIME st, ft;
		GetSystemTime(&st);
		int sudoku[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = (int)sudokuMatrix[i, j];
			}
		}
		fillClueGiven();
		storeClueGiven(sudoku);
		storePositions2();
		step2 = 0;
		writer = gcnew FileProcessing("anims/thread2.txt");

		for (int row = 8; row >= 0; row--)
		{
			for (int column = 8; column >= 0; column--)
			{
				if (!placeNum(row, column, sudoku))
				{
					sudoku[row][column] = 0;
					if (!goBack2(row, column, sudoku)) {
						writer->writerClose();
						finish = false;
					}

				}
				else {
					writer->writeFile(sudoku);
					step2++;
				}

			}
		}
		writer->writerClose();
		GetSystemTime(&ft);
		workingTime = (ft.wSecond - st.wSecond) * 1000 + (ft.wMilliseconds - st.wMilliseconds);
		finish = true;
	}

	// Thread 3
	void solveT3()
	{
		SYSTEMTIME st, ft;
		GetSystemTime(&st);
		int sudoku[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = (int)sudokuMatrix[i, j];
			}
		}
		fillClueGiven();
		storeClueGiven(sudoku);
		storePositions3();
		step3 = 0;
		writer = gcnew FileProcessing("anims/thread3.txt");

		for (int column = 0; column < 9; column++)
		{
			for (int row = 0; row < 9; row++)
			{
				if (!placeNum(row, column, sudoku))
				{
					sudoku[row][column] = 0;
					if (!goBack3(row, column, sudoku)) {
						writer->writerClose();
						finish = false;
					}
				}
				else {
					writer->writeFile(sudoku);
					step3++;
				}

			}
		}
		writer->writerClose();
		GetSystemTime(&ft);
		workingTime = (ft.wSecond - st.wSecond) * 1000 + (ft.wMilliseconds - st.wMilliseconds);
		finish = true;
	}

	// Thread 4
	void solveT4()
	{
		SYSTEMTIME st, ft;
		GetSystemTime(&st);
		int sudoku[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				sudoku[i][j] = (int)sudokuMatrix[i, j];
			}
		}
		fillClueGiven();
		storeClueGiven(sudoku);
		storePositions4();
		step4 = 0;
		writer = gcnew FileProcessing("anims/thread4.txt");

		for (int column = 8; column >= 0; column--)
		{
			for (int row = 8; row >= 0; row--)
			{
				if (!placeNum(row, column, sudoku))
				{
					sudoku[row][column] = 0;
					if (!goBack4(row, column, sudoku)) {
						writer->writerClose();
						finish = false;
					}
				}
				else {
					writer->writeFile(sudoku);
					step4++;
				}

			}
		}
		writer->writerClose();
		GetSystemTime(&ft);
		workingTime = (ft.wSecond - st.wSecond) * 1000 + (ft.wMilliseconds - st.wMilliseconds);
		finish = true;
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

	int getWorkingTime() {
		return workingTime;
	}

};

