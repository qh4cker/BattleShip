#include <iostream>
#include <string>
#include "point.h"

#ifdef _WIN32
#include <windows.h>
#endif

void setDrawColor(int color) {
#ifdef _WIN32
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
#else

	switch (color) {
		case 0: //black
			std::cout << "\033[30m;40m";
			break;
		case 1: //blue
			std::cout << "\033[34;40m";
			break;
		case 2: //green
			std::cout << "\033[32;40m";
			break;
		case 3: //aqua
			std::cout << "\033[1;34;40m";
			break;
		case 4: //red
			std::cout << "\033[31;40m";
			break;
		case 5: //purple
			std::cout << "\033[35;40m";
			break;
		case 6: //yellow
			std::cout << "\033[1;33;40m";
			break;
		case 7: //white
			std::cout << "\033[37;40m";
			break;
		case 8: //gray
			std::cout << "\033[1;30;40m";
			break;
		case 9: //light blue
			std::cout << "\033[1;34;40m";
			break;
		case 10: //light green
			std::cout << "\033[1;32;40m";
			break;
		case 11: //light aqua
			std::cout << "\033[1;40m";
			break;
		case 12: //light red
			std::cout << "\033[1;31;40m";
			break;
		case 13: //light purple
			std::cout << "\033[1;35;40m";
			break;
		case 14: //light yellow
			std::cout << "\033[1;33;40m";
			break;
		case 15: // bright white
			std::cout << "\033[1;37;40m";
			break;
		default:
			exit(1);
	}
#endif
}

void goToXY(int xpos, int ypos) {
#ifdef _WIN32
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
#else
	std::cout << "\033[" << ypos << ";" << xpos<< "H";
#endif
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


Point::Point(Point& point) {
	x = point.x;
	y = point.y;
	color = point.color;

}
Point::Point(const Point& point) {
	x = point.x;
	y = point.y;
	color = point.color;

}

Point::~Point() {
	x = y = color = 0;
}

int Point::getX() const {
	return x;
}
int Point::getY() const {
	return y;
}
int Point::getColor() const {
	return color;
}
Point Point::getPoint() const {
	return *this;
}

void Point::setX(int x) {
	this->x = x;
}

void Point::setY(int y) {
	this->y = y;
}

void Point::setPosition(int _x, int _y) {
	x = _x; y = _y;
}

void Point::setColor(int color) {
	this->color = color;
}

void Point::setPoint(Point point) {
	*this = point;
}

void Point::draw(std::ostream& os) const {
	goToXY(x, y);
	setDrawColor(color);

	os << "\xFE";
}

void Point::print(std::ostream& os) const {
	os << "(" << x << "," << y << ") " << color << std::endl;
}

void Point::read(std::istream& os) {

	std::string temp_x;
	std::string temp_y;
	std::string temp_color;
	std::string input;
	getline(os, input);



	int i = 1;
	while (input[i] != ',' && i < input.length()) {
		temp_x += input[i];
		i++;
	}
	
	i++;
	int j = i;
	while (input[i] != ')' && i < input.length()) {
		temp_y += input[i];
		i++;
	}
	i += 2;
	j = i;
	while (i < input.length()) {
		temp_color += input[i];
		i++;
	}

		//std::cout << temp_color << std::endl;
	std::cout << temp_x;
	x =	std::stoi(temp_x);
	y =	std::stoi(temp_y);
	color = std::stoi(temp_color);

}

bool Point::operator==(const Point& other) const {
	if (x != other.x || y != other.y || color != other.color)
		return false;
	return true;
}
bool Point::operator!=(const Point& other) const {
	if (x != other.x || y != other.y || color != other.color)
		return true;
	return false;
}

Point& Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;
	color = other.color;
	return *this;
}


Point Point::operator+(const Point& other) const {
	return {x + other.x, y + other.y, color + other.color};
}



Point Point::operator-(const Point& other) const {
	return {x - other.x, y - other.y, color};
}


std::ostream& Point::operator<<(std::ostream& out) const {
	print(out);
	return out;
}

std::istream& Point::operator>>(std::istream& in) {
	read(in);
	return in;
}


