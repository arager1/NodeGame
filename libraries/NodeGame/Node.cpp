#include "Node.h"

Node::Node() : name("NULL"), pinLED(0), pinButton(0), 
               pinPiezo(0), pitch(0) {}

Node::Node(const char *n, int l, int b, int p, int s) 
    : name(n), pinLED(l), pinButton(b), pinPiezo(p), pitch(s) {
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);
  pinMode(pinPiezo, OUTPUT);
}

bool Node::checkButton(){
  bool pressed = false;
  while (buttonPressed()){
    on();
    pressed = true;
  }
  off();
  return pressed;
}

void Node::play(int d){
  on();
  delay(d);
  off();
  delay(d);
}

void Node::light(int d){
  digitalWrite(pinLED, HIGH);
  delay(d);
  digitalWrite(pinLED, LOW);
}

void Node::sound(int note, int d){
  tone(pinPiezo, note);
  delay(d);
  noTone(pinPiezo);
}


void Node::on(){
  digitalWrite(pinLED, HIGH);
  tone(pinPiezo, pitch);
}

void Node::off(){
  digitalWrite(pinLED, LOW);
  noTone(pinPiezo);
}

bool Node::buttonPressed(){
  return digitalRead(pinButton);
}
