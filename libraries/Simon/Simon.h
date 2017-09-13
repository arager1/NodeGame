#ifndef SIMON_H
#define SIMON_H

#include "../NodeGame/NodeGame.h"

// Maximum number of levels. Matched with 
// NodeGame's buffer size.
const int numLevels = 128;


// Plays Simon Says with 4 nodes. 
class Simon {
  public:
    // Set up a NodeGame with (piezo pin,
    // red LED, red button, yellow LED,
    // yellow button, green LED, green 
    // button, blue LED, blue button).
    Simon(int p, int rl, int rb, 
          int yl, int yb, int gl, 
          int gb, int bl, int bb);
    ~Simon() { delete game; }

    // Either accept button input or display 
    // the correct sequence, depending on 
    // listening state. Increases in speed 
    // as game progresses. Clears game with 
    // incorrect input
    void play();

    // Creates a new random sequence to compare
    // to NodeGame's recording buffer.
    void newSequence();
    // Plays the correct sequence up to the 
    // current level. 
    void playSequence();

    // Signal user that they were incorrect.
    void playIncorrect();

    // Sets the verbose boolean to true, enabling
    // print statements throughout the program.
    void testing();
    // Prints randomized sequence through current
    // level.
    void printSequence();
    // Prints sequence and NodeGame's buffer.
    void printGame();

  private:
    // Pointer to dynamically allocated NodeGame
    NodeGame *game;

    // Current level. Initialized to 1
    int level;

    // Stores correct sequence for entire game.
    int correctSequence[numLevels];

    // Allows button input or sequence output
    bool listening;

    // Allows print statements
    bool verbose;

    // Noisemaker location
    int piezo;
};

#endif



