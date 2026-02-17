#pragma once
#include <fstream>
#include "point.h"

void setDrawColor(int color);
void goToXY(int xpos, int ypos);

void openFile(std::ifstream& file, const std::string& fileName);
int readFile(std::ifstream& monFlux, Point points[]);