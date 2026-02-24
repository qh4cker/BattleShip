#include "grid.h"

using namespace std;

bool Grid::initShips() {
	ifstream file;
	file.open(GRID_SHIPS_FILENAME, std::ios::in);
	this->read(file);
	file.close();
	if (!placeShips()) {
		std::cout << "Failed to read file : " << GRID_SHIPS_FILENAME << " \nclosing program :/ ";
		exit(1);
		//return false;
	}

	//hideShips();
	return true;
}

void Grid::hideShips() {
	for (Ship& ship : _ships)
		ship.hide();
}

/***********************************************/
/* NE MODIFIEZ PAS LES MÉTHODES QUI SUIVENT !  */
/* ELLES SONT DÉJÀ PLEINEMENT FONCTIONNELLES ! */
/***********************************************/
bool Grid::placeShips() {
	bool collides;
	int maxX, maxY;

	for (int i = 0; i < _nbShips; i++) {
		do {
			if ((_ships[i].getLength() > (GRID_WIDTH - 2)) ||
				(_ships[i].getLength() > (GRID_HEIGHT - 2))) {
				return false;
			}

			collides = false;
			_ships[i].setDirection(Direction(rand() % 2));

			if (_ships[i].getDirection() == HORIZONTAL) {
				maxX = GRID_INNER_MAX_X - _ships[i].getLength();
				maxX = ((maxX < GRID_INNER_MIN_X) ? GRID_INNER_MIN_X : maxX);
				maxY = GRID_INNER_MAX_Y;
			}

			else {
				maxX = GRID_INNER_MAX_X;
				maxY = GRID_INNER_MAX_Y - _ships[i].getLength();
				maxY = ((maxY < GRID_INNER_MIN_Y) ? GRID_INNER_MIN_Y : maxY);
			}

			const int randX = (rand() % (maxX - GRID_INNER_MIN_X + 1) + GRID_INNER_MIN_X);
			const int randY = (rand() % (maxY - GRID_INNER_MIN_Y + 1) + GRID_INNER_MIN_Y);
			_ships[i].setPosition(randX, randY);

			for (int j = 0; j < i; j++) {
				if ((i != j) && _ships[i].checkCollision(_ships[j])) {
					collides = true;
					break;
				}
			}
		} while (collides);
	}

	return true;
}

Grid::Grid() {
	_gridOutline.setPosition(GRID_INNER_MIN_X - 1, GRID_INNER_MIN_Y - 1);
	_gridOutline.setWidth(GRID_WIDTH);
	_gridOutline.setHeight(GRID_HEIGHT);
	_nbMissedHits = _nbShips = 0;
	initShips();
}

Grid::~Grid() {
	_nbShips = _nbMissedHits = 0;
}

int Grid::getNbRemainingShips() const {
	int count = 0;
	for (int i = 0; i < _nbShips; i++) {
		if (!_ships[i].getSunkStatus())
			count++;
	}
	return count;
}

bool Grid::placeHit(const Point& hitPosition) {
	if (hitPosition.getX() < GRID_INNER_MIN_X || hitPosition.getX() > GRID_INNER_MAX_X || hitPosition.getY() < GRID_INNER_MIN_Y || hitPosition.getY() > GRID_INNER_MAX_Y)
		return false;

	for (const Point& point : _missedHits) {
		if (hitPosition == point)
			return false;
	}

	for (int i = 0; i < _nbShips; i++) {

		switch (_ships[i].placeHit(hitPosition)) {
			case 1: //sunk
				return false;
			case 2: //already hit
				return false;
			case 3: //newly hit point
				return true;
			default: //missed ship
				_missedHits[_nbMissedHits].setColor(GRID_MISSED_HITS_COLOR);
				_nbMissedHits++;
				return false;
		}
	}
	return false;
}

void Grid::draw(std::ostream &output) const {
	_gridOutline.draw(output);
	//for (const Ship& ship : _ships)
	//	ship.draw(output);
	//for (const Point& hits : _missedHits)
	//	hits.draw(output);
}

void Grid::read(std::istream &input) {
	std::string line;
	while (_ships[_nbShips].read(input)) {
		_nbShips++;
	}
}

std::ostream & operator<<(std::ostream &output, const Grid &grid) {
	grid.draw(output);
	return output;
}

std::istream & operator>>(std::istream &input, Grid &grid) {
	grid.read(input);
	return input;
}

void Grid::printShipsStatus(ostream& output) const {
	goToXY(GRID_SHIPS_STATUS_X, GRID_SHIPS_STATUS_Y);
	output << "BATEAUX RESTANTS";

	goToXY((GRID_SHIPS_STATUS_X + 23), GRID_SHIPS_STATUS_Y);
	output << "BATEAUX COULES";

	for (int i = 1; i <= _nbShips; i++) {
		if (_ships[i - 1].getSunkStatus()) {
			goToXY((GRID_SHIPS_STATUS_X + 23), (GRID_SHIPS_STATUS_Y + i));
		} else {
			goToXY((GRID_SHIPS_STATUS_X), (GRID_SHIPS_STATUS_Y + i));
		}

		_ships[i - 1].print(output);
	}
}

/******************************************************/
/* CODEZ ICI LES AUTRES MÉTHODES DE LA CLASSE "GRID". */
/******************************************************/