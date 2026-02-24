#include <iostream>
#include "rect.h"
//#include "game.h"
#include "point.h"
#include "ship.h"
//using namespace std;

int main() {
	/******************************************************/
	/* PLACEZ VOS TESTS ICI, MAIS RETIREZ-LES DU "MAIN()" */
	/* UNE FOIS QUE VOTRE JEU DE BATTLESHIP EST COMPLÉTÉ. */
	/******************************************************/

	//goToXY(2,10);
	//setDrawColor(7);
	//std::cout << "arsawsaws";

	//Rect rect1(5,5,5,5);

	//rect1.draw(std::cout);

	//setDrawColor(7);
	Ship ship("Teto", 5);
	Ship ship2("miku", 3);
	ship2.setPosition(7,12);
	ship2.setColor(4);
	ship2.rotate();

	for (int i = 0; i < 16; i++) {
		ship.setPosition(5, i+1);
		ship.setColor(i);
		std::cout << "          " << i;
		ship.placeHit({5,2});
		ship.placeHit({6,2});
		ship.placeHit({7,2});
		ship.placeHit({8,2});
		ship.placeHit({9,2});
		ship.placeHit({9,2});
		//if (!ship.checkCollision(ship2)) {
			ship.hide();
			ship.draw(std::cout);
//
		//}
	}
		ship2.draw(std::cout);
	return 0;
}