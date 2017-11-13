#pragma once


public ref class FileProcessing {
public:

	System::IO::StreamWriter^ sw;

	FileProcessing(System::String^ fileName) {
		sw = gcnew System::IO::StreamWriter(fileName);
	}

	void writeFile(int sudoku[9][9]) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
			System::String^ c = sudoku[i][j] + " ";
				sw->Write(c);
			}
			sw->Write("\n");
		}
	}

	void writerClose() {
		sw->Close();
	}
	
	
	void readFile(System::String^ fileName, int step) {

	}


};

