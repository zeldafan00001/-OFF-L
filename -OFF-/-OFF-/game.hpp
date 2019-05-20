#ifndef game_h
#define game_h

#include "const.h"

class Game
{
private:
	char amap[11][11];


	bool running = false;

	void mainloop();
public:
	Game(); // constructor 
	~Game(); // destructor
	void go();

	void RenderMap();
	void readFileMap();


	
	/* für eine spätere herausforderung

	void saveData();
	void loadData();
	
	*/
	
};

#endif // !game_h
