#include "game.hpp"

/*#include <fcntl.h> // FOR UNICODE
#include <io.h> // FOR UNICODE

_setmode(_fileno(stdout), _O_U16TEXT); // FOR UNICODE
wcout << L"";*/ 

int main()
{
	/*	Game* ist ein pointer auf die Class Game, mit spiel ist also im späteren 
		verlauf die class Game gemeint mit -> wird auf go() gezeigt was in diesem
		sinne auch gleichzeitig gestartet wird 
	*/
	Game* spiel = new Game();
	spiel->go();
	delete spiel;
 
	return 0;
}