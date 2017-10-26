#include "FileProcessing.h"

using namespace System;
using namespace System::IO;

void writeFile(System::String^ fileName, int sudoku[9][9]) {
	StreamWriter^ sw = gcnew StreamWriter(fileName,true);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			String^ c = sudoku[i][j] + " ";
			sw->Write(c);
		}
		sw->Write("\n");
	}
	sw->Close();
}