#include "Ocarina.h"

Ocarina::Ocarina(int p, int wl, int wb, int rl, int rb, int yl, int yb, int gl, int gb, int bl, int bb){
	game = new NodeGame(p);
	game->addNode("White", wl, wb, NOTE_D4);
	game->addNode("Red", rl, rb, NOTE_F4);
	game->addNode("Yellow", yl, yb, NOTE_A4);
	game->addNode("Green", gl, gb, NOTE_B4);
	game->addNode("Blue", bl, bb, NOTE_D5);
	piezo = p;
	verbose = false;
}

Ocarina::~Ocarina(){
	delete game;
}

void Ocarina::testing(){
	Serial.begin(9600);
	verbose = true;
}

void Ocarina::playSong(const Note arr[], int len, int tempo){
	delay(tempo/4);
	for (int i = 0; i < len; i++){
		tone(piezo, arr[i].pitch);
		delay(tempo/arr[i].duration);
	}
	noTone(piezo);
}

void Ocarina::play(){
	game->read();
	if (verbose) game->print();
	testInput(1000);
}

void Ocarina::testInput(int tempo){
	int numImpossible = 0;
	for (int i = 0; i < numSongs; i++){
		if (game->compare(sequences[i], sequenceLength[i])){
			if (game->match(sequences[i], sequenceLength[i])){
				if (verbose) Serial.println("Success");
				playSong(songs[i], songLength[i], tempo);
				game->clear();
			}
		}
		else numImpossible++;
	}
	if (numImpossible == numSongs) game->clear();
}



