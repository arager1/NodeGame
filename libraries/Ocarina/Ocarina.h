#ifndef OCARINA_H
#define OCARINA_H

#include "../NodeGame/NodeGame.h"

const int numSongs = 12;  			// Number of songs in library
const int maxSequenceLength = 8;	// Maximum input sequence length
const int maxSongLength = 16;		// Maximum song length

class Ocarina {
private:
	bool verbose;					// Whether or not to print data
	int piezo;						// Location of piezo
	void testInput(int tempo);		// Test whether input matches a sequence and respond
public:
	NodeGame *game;					// Pointer to NodeGame
	Ocarina(int p, int wl, int wb, 	// Initialize nodes and member variables
			int rl, int rb, int yl, 
			int yb, int gl, int gb, 
			int bl, int bb);
	~Ocarina();						// Delete NodeGame
	void testing();					// Set up Serial and set verbose
	void playSong(const Note arr[], // Play array of notes at tempo speed
				  int len, int tempo);
	void play();					// Update NodeGame and testInput

};

const int sequences[numSongs][maxSequenceLength] = {
	{3, 4, 2, 3, 4, 2},
	{1, 2, 3, 1, 2, 3},
	{4, 3, 2, 4, 3, 2},
	{2, 1, 4, 2, 1, 4},
	{2, 0, 1, 2, 0, 1},
	{0, 1, 4, 0, 1, 4},
	{0, 4, 3, 2, 3, 2},
	{1, 0, 1, 0, 2, 1, 2, 1},
	{0, 1, 2, 2, 3},
	{3, 2, 2, 0, 3, 2, 1},
	{0, 1, 0, 2, 1, 0},
	{4, 2, 4, 2, 3, 4},
	// {4, 3, 4, 3, 0, 2, 0},
	// {0, 2, 3, 0, 2, 3, 2, 0},
	// {3, 4, 3, 2, 1, 3, 2},
	// {2, 3, 2, 1, 2, 4, 3},
	// {2, 1, 0, 1, 2, 4},
	// {3, 2, 1, 3, 2, 1},
	// {1, 3, 4, 1, 3, 4},
	// {2, 2, 0, 0, 1, 1},
	// {1, 0, 2, 1, 0, 2}
};

const int sequenceLength[numSongs] = {6, 6, 6, 6, 6, 6, 6, 8, 5, 7, 6, 6/*, 7, 8, 7, 7, 6, 6, 6, 6, 6*/};

const Note songs[numSongs][maxSongLength]{

	{	{.pitch = NOTE_B4, .duration = 1},
		{.pitch = NOTE_D5, .duration = 2},
		{.pitch = NOTE_A5, .duration = 1},
		{.pitch = NOTE_G5, .duration = 2},
		{.pitch = NOTE_D5, .duration = 1} },

	{	{.pitch = NOTE_F4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_E5, .duration = 4},
		{.pitch = NOTE_D5, .duration = 2},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_C5, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_G4, .duration = 4},
		{.pitch = NOTE_E4, .duration = 2} },

	{	{.pitch = NOTE_D5, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_B4, .duration = 2},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_REST, .duration = 100},
		{.pitch = NOTE_A4, .duration = 2} },

	{	{.pitch = NOTE_D6, .duration = 1} },

	{	{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_C5, .duration = 4},
		{.pitch = NOTE_B4, .duration = 2},
		{.pitch = NOTE_G4, .duration = 2},
		{.pitch = NOTE_F4, .duration = 4},
		{.pitch = NOTE_G4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_D4, .duration = 2},
		{.pitch = NOTE_C4, .duration = 4},
		{.pitch = NOTE_E4, .duration = 4},
		{.pitch = NOTE_D4, .duration = 1} },

	{	{.pitch = NOTE_E5, .duration = 2},
		{.pitch = NOTE_F5, .duration = 8},
		{.pitch = NOTE_E5, .duration = 8},
		{.pitch = NOTE_F5, .duration = 8},
		{.pitch = NOTE_E5, .duration = 8},
		{.pitch = NOTE_C5, .duration = 8},
		{.pitch = NOTE_A4, .duration = 2} },

	{	{.pitch = NOTE_D4, .duration = 4},
		{.pitch = NOTE_D5, .duration = 4},
		{.pitch = NOTE_B4, .duration = 1},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 1} },

	{	{.pitch = NOTE_F4, .duration = 4},
		{.pitch = NOTE_D4, .duration = 4},
		{.pitch = NOTE_F4, .duration = 4},
		{.pitch = NOTE_D4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_F4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_F4, .duration = 4} },

	{	{.pitch = NOTE_D4, .duration = 2},
		{.pitch = NOTE_F4, .duration = 2},  
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_REST, .duration = 100},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_B4, .duration = 2} },

	{	{.pitch = NOTE_B4, .duration = 2},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_REST, .duration = 100},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_D4, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_F4, .duration = 2} },

	{	{.pitch = NOTE_D4, .duration = 2},
		{.pitch = NOTE_F4, .duration = 4}, 
		{.pitch = NOTE_D4, .duration = 4},
		{.pitch = NOTE_A4, .duration = 2},
		{.pitch = NOTE_F4, .duration = 2},
		{.pitch = NOTE_D4, .duration = 2} },

	{	{.pitch = NOTE_D5, .duration = 4},
		{.pitch = NOTE_A4, .duration = 1},
		{.pitch = NOTE_D5, .duration = 4},
		{.pitch = NOTE_A4, .duration = 4},
		{.pitch = NOTE_B4, .duration = 4},
		{.pitch = NOTE_D5, .duration = 2} }

	// {	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 2},
	// 	{.pitch = NOTE_D4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D4, .duration = 2} },

	// {	{.pitch = NOTE_D4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 2},
	// 	{.pitch = NOTE_B4, .duration = 2},
	// 	{.pitch = NOTE_D4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 2},
	// 	{.pitch = NOTE_B4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 2},
	// 	{.pitch = NOTE_D4, .duration = 1} },

	// {	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 2} },

	// { 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 2} },

	// {	{.pitch = NOTE_A4, .duration = 1}, 
	// 	{.pitch = NOTE_F4, .duration = 2},
	// 	{.pitch = NOTE_D4, .duration = 2},
	// 	{.pitch = NOTE_F4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 2},
	// 	{.pitch = NOTE_D5, .duration = 1} },

	// {	{.pitch = NOTE_B4, .duration = 2},
	// 	{.pitch = NOTE_A4, .duration = 2},
	// 	{.pitch = NOTE_E4, .duration = 4},
	// 	{.pitch = NOTE_D4, .duration = 4},
	// 	{.pitch = NOTE_E4, .duration = 1} },

	// {	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 2} },

	// {	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 2} },

	// {	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 1},
	// 	{.pitch = NOTE_D5, .duration = 4},
	// 	{.pitch = NOTE_A4, .duration = 4},
	// 	{.pitch = NOTE_B4, .duration = 4},
	// 	{.pitch = NOTE_D5, .duration = 2} }

};

const int songLength[] = {5, 10, 7, 1, 11, 7, 6, 8, 6, 8, 6, 6/*, 7, 8, 6, 6, 6, 5, 6, 6, 6*/};

#endif

