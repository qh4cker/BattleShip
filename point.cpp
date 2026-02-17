#include "functions.h"
#include "point.h"
#include <iostream>
#include <string>

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
	color = std::stoi(temp_color.c_str());

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

void Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;
	color = other.color;
}

Point Point::operator+(const Point& other) const {
	return {x + other.x, y + other.y, color + other.color};
}

Point Point::operator-(const Point& other) const {
	return {x - other.x, y - other.y, color};
}


std::ostream& Point::operator<<(std::ostream& out) {
	print(out);
	return out;
}

std::istream& Point::operator>>(std::istream& in) {
	read(in);
	return in;
}


