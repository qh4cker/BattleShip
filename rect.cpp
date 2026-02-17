#include <iostream>
#include "rect.h"

Rect::Rect() {
	coord.setPosition(0, 0);
	w = h = 0;
}

Rect::Rect(int x, int y, int w, int h) : w(w), h(h) {
	coord.setPosition(x, y);
}

Rect::~Rect() {
	w = h = 0;
	coord.~Point();
}

Point Rect::getPosition() const {
	return coord;
}

int Rect::getWidth() const {
	return w;
}

int Rect::getHeight() const {
	return h;
}

Rect Rect::getRectangle() const {
	return *this;
}

void Rect::setWidth(int width) {
	if (width < 0) {
		std::cout << "Valeur invalide!\n";
		exit(1);
	}
	w = width;
}

void Rect::setHeight(int height) {
	if (height < 0) {
		std::cout << "Valeur invalide!\n";
		exit(1);
	}
	h = height;
}

void Rect::setSize(int width, int height) {
	if (width < 0 || height < 0) {
		std::cout << "Valeur invalide!\n";
		exit(1);
	}
	w = width;
	h = height;
}

void Rect::setRectangle(Rect& rectangle) {
	*this = rectangle;
}

void Rect::read(std::istream& os) {
	std::string input;


	
	
	std::string temp_x;
	std::string temp_y;
	std::string temp_color;
	std::string temp_width;
	std::string temp_height;



	os >> input >> temp_color >> temp_width >> temp_height >> temp_height;

	int i = 1;
	while (input[i] != ',' && i < input.length()) {
		temp_x += input[i];
		i++;
	}

	i++;

	while (input[i] != ')' && i < input.length()) {
		temp_y += input[i];
		i++;
	}

	coord.setX(std::stoi(temp_x));
	coord.setY(std::stoi(temp_y));
	coord.setColor(std::stoi(temp_color));
	setWidth(std::stoi(temp_width));
	setHeight(std::stoi(temp_height));
}

void Rect::print(std::ostream& os) const {
	std::cout << "(" << getPosition().getX() << "," << getPosition().getY() << ") " << getPosition().getColor() << " " << getWidth() << " X " << getHeight() << std::endl;
}


void Rect::draw(std::ostream& os) const {
	Point temp;
	for (int x = getPosition().getX(); x < w + getPosition().getX(); x++) {
		for (int y = getPosition().getY(); y < h + getPosition().getY(); y++) {
			if (x == getPosition().getX() || x == getPosition().getX() + w || y == getPosition().getY() || y == getPosition().getY() + h) {
				temp.setPoint({x, y, coord.getColor()});
				temp.draw(os);
			}
		}
	}

}

int Rect::surface() const {
	return w * h;
}

int Rect::perimeter() const {
	return 2 * (w + h);
}
