#include <windows.h>
#include <iostream>
#include "functions.h"

void setDrawColor(int color) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);

}

void goToXY(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void openFile(std::ifstream& file, const std::string& fileName) {
	file.open(fileName, std::ios::in);

	if (!file) {
		std::cout << "Failed to open file : " << fileName;
		exit(1);
	}
}

int readFile(std::ifstream& monFlux, Point points[]) {
	return 0;
}
