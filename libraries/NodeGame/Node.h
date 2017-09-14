#ifndef NODE_H
#define NODE_H

#include "Arduino.h"
#include "notes.h"

// Provides an abstraction over an Arduino 
// button, LED, and noisemaker (piezo). Synchronizes 
// a button press to LED and noisemaker activation 
// with checkButton(). Also contains functions to 
// activate LED or noisemaker independantly.
class Node {
  public:
    // Sets this Node to invalid state.
    Node();
    // Loads a (name, led location, button location, 
    // piezo location, and pitch) into this Node.
    Node(const char *n, int l, int b, int p, int s);   

    // Call checkButton() on a loop to listen and respond
    // to button presses. Calls on() during a button 
    // press. Calls off() otherwise. Does not return 
    // until button is released, at which point it 
    // returns true once. 
    bool checkButton();  
                         
    // Call on() for duration d then off() for duration d
    void play(int d);  
    // Light LED for duration d
    void light(int d);   
    // Activate noisemaker for duration d
    void sound(int note, int d);
    
    const char *getName() { return name; }

  private:
    // Activate LED and noisemaker
    void on();
    // Deactivate LED and noisemaker     
    void off();

    bool buttonPressed(); 

    const char *name; 
    int pinLED;           
    int pinButton;      
    int pinPiezo;     
    int pitch;
};

#endif