#include "Simon.h"


Simon::Simon(int p, int rl, int rb, int yl, int yb, 
			 int gl, int gb, int bl, int bb) :
piezo(p), level(0), listening(false), verbose(false) {
	game = new NodeGame(p);
	game->addNode("Red", rl, rb, NOTE_A4);
	game->addNode("Yellow", yl, yb, NOTE_CS4);
	game->addNode("Green", gl, gb, NOTE_E5);
	game->addNode("Blue", bl, bb, NOTE_E4);
	randomSeed(analogRead(0));
	newSequence();
}


Simon::~Simon(){
	delete game;
}

void Simon::newSequence(){
	for (int i = 0; i < numLevels; i++) correctSequence[i] = random(0, 4);
	level = 1;
}

void Simon::playSequence(){
	delay(1000);
	int duration = 300 - (level * 10);
	for (int i = 0; i < level; i++){
		game->getNode(correctSequence[i])->play(duration);
		delay(duration/3);
	}
}

void Simon::printSequence(){
	Serial.print("[ ");
	for (int i = 0; i < level; i++){
		Serial.print(game->getNode(correctSequence[i])->name);
		Serial.print(" ");
	}
	Serial.print("]");
}

void Simon::printGame(){
	printSequence();
	Serial.print("\t");
	game->print();
	Serial.println();
}

void Simon::playIncorrect(){
	tone(piezo, NOTE_E2);
	for(int i = 0; i < 100; i++){
		game->getNode(random(0, 4))->light(10);
	}
	noTone(piezo);
}

void Simon::testing(){
	Serial.begin(9600);
	verbose = true;
}

void Simon::play(){
	if (listening){
		if (game->read() and verbose) printGame();
		if (game->compare(correctSequence, level)){
			if (game->match(correctSequence, level)){
				if (level == numLevels) newSequence();
				else level++;
				listening = false;
				game->clear();
			}
		}
		else{
			playIncorrect();
			newSequence();
			listening = false;
			game->clear();
			if (verbose) printGame();
		}
	}
	else{
		if (verbose) printGame();
		playSequence();
		listening = true;
	}
	
}


