#include <iostream>
#include "rect.h"
#include "game.h"
#include "grid.h"
#include "point.h"
#include "ship.h"
//using namespace std;

int main() {
	/******************************************************/
	/* PLACEZ VOS TESTS ICI, MAIS RETIREZ-LES DU "MAIN()" */
	/* UNE FOIS QUE VOTRE JEU DE BATTLESHIP EST COMPLÉTÉ. */
	/******************************************************/

	//Grid grid;
	//grid.draw(std::cout);

	Game game;
	game.play(std::cout);

	//Rect rect;
	//rect.setPosition(5,5);
	//rect.setHeight(4);
	//rect.setWidth(12);
	//rect.draw(std::cout);
}