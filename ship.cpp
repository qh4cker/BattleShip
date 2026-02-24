#include "ship.h"

#include <chrono>

#include "rect.h"

using namespace std;

/********************************************/
/* NE MODIFIEZ PAS LA MÉTHODE QUI SUIT !    */
/* ELLE EST DÉJÀ PLEINEMENT FONCTIONNELLE ! */
/********************************************/
void Ship::updatePoints() {
	for (int i = 0; i < _length; i++) {
		if (_direction == HORIZONTAL) {
			_points[i].setX(_x + i);
			_points[i].setY(_y);
		}

		else {
			_points[i].setX(_x);
			_points[i].setY(_y + i);
		}
	}
}

void Ship::updateSunkStatus() {
	for (int i = 0; i < _length; i++) {
		if (_points[i].getColor() == SHIP_HIT_COLOR)
			continue;
		return;
	}

	for (int i = 0; i < _length; i++)
		_points[i].setColor(SHIP_SUNK_COLOR);
	_hasSunk = true;
}

Ship::Ship(const std::string &name, int length) : _name(name), _length(length) {
	_x = 0;
	_y = 0;
	_direction = Direction::HORIZONTAL;
	_hasSunk = false;
	updatePoints();
}

Ship::~Ship() {
	_name = "";
	_x = 0;
	_y = 0;
	_direction = Direction::HORIZONTAL;
	_hasSunk = false;
	_length = 0;
}

int Ship::getLength() const {
	return _length;
}

const Direction & Ship::getDirection() const {
	return _direction;
}

bool Ship::getSunkStatus() const {
	return _hasSunk;
}

void Ship::setColor(const int color) {
	for (Point& point : _points)
		point.setColor(color);
}

void Ship::setPosition(int x, int y) {
	if (x < 0 || y < 0)
		exit(1);
	_x = x;
	_y = y;
	updatePoints();
}

void Ship::setLength(int length) {
	if (length < 0 || _length >= SHIP_MAX_LENGTH )
		exit(1);
	_length = length;
	updatePoints();
}

void Ship::setDirection(const Direction &direction) {
	_direction = direction;
	updatePoints();
}

void Ship::rotate() {
	if (_direction == Direction::HORIZONTAL)
		_direction = VERTICAL;
	else
		_direction = HORIZONTAL;
	updatePoints();
}

void Ship::hide() {
	for (Point& point : _points)
		point.setColor(SHIP_HIDDEN_COLOR);
}

bool Ship::checkCollision(const Ship &otherShip) const {
	for (int i = 0; i < this->_length; i++) {
		for (int j = 0; j < otherShip._length; j++) {
			if (_points[i].getX() == otherShip._points[j].getX() && _points[i].getY() == otherShip._points[j].getY())
				return true;
		}
	}
	return false;
}

int Ship::placeHit(const Point &hitPosition) {
	for (int i = 0; i < _length; i++) {
		if (hitPosition.getX() == _points[i].getX() && hitPosition.getY() == _points[i].getY()) {
			if (_hasSunk)
				return 1;
			if (_points[i].getColor() == SHIP_HIT_COLOR)
				return 2;
			_points[i].setColor(SHIP_HIT_COLOR);
			updateSunkStatus();
			return 3;
		}
	}
		return 0;
	std::cout << "empty boat :/";
	exit(1);
}

void Ship::print(std::ostream &output) const {
	std::cout << _name << " (" << _length << ")";
}

void Ship::draw(std::ostream &output) const {
	for (int i = 0; i < _length; i++)
		_points[i].draw(output);
}

bool Ship::read(std::istream &input) {
	std::string temp, tempLength;
	input >> _name >> temp;
	if (_name.empty() || temp.empty())
		return false;

	for (int i = 1; i < temp.size() -1; i++) {
		if (temp.at(i) == ')')
			break;
		tempLength.push_back(temp.at(i));
	}

	_length = stoi(tempLength);
	return true;
}

std::ostream& operator<<(std::ostream &output, const Ship &ship) {
	ship.draw(output);
	return output;
}

std::istream& operator>>(std::istream &input, Ship &ship) {
	ship.read(input);
	return input;
}


/******************************************************/
/* CODEZ ICI LES AUTRES MÉTHODES DE LA CLASSE "SHIP". */
/******************************************************/