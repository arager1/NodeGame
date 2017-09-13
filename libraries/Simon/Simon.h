#ifndef SIMON_H
#define SIMON_H

#include "../NodeGame/NodeGame.h"

const int numLevels = 128;



class Simon {

private:

	NodeGame *game;

	int piezo;
	int correctSequence[numLevels];
	bool listening;
	bool verbose;

public:

	int level;

	Simon(int p, int rl, int rb, 
		  int yl, int yb, int gl, 
		  int gb, int bl, int bb);		
	~Simon();

	void play();

	void newSequence();
	void playSequence();

	void playIncorrect();

	void testing();
	void printSequence();
	void printGame();

};

#endif



