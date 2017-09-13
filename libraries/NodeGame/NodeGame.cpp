#include "NodeGame.h"

NodeGame::NodeGame(int p) : numNodes(0), numRecorded(0), pinPiezo(p) {}

NodeGame::~NodeGame(){
  for (int i = 0; i < numNodes; i++) delete nodes[i];
}
void NodeGame::addNode(const char *n, int l, int b, int p){
  if (numNodes < maxNodes){
    nodes[numNodes] = new Node(n, l, b, pinPiezo, p);
    numNodes++;
  }
}

Node *NodeGame::getNode(int i){
  if (i < numNodes) return nodes[i];
  else return NULL;
}

bool NodeGame::read(){
  if (numRecorded == maxRecord) clear();
  for (int i = 0; i < numNodes; i++){
    if (nodes[i]->checkButton()){
      buffer[numRecorded] = i;
      numRecorded++;
      return true;
    }
  }
  return false;
}

bool NodeGame::compare(const int arr[], int len){
  if (len < numRecorded) return false;
  for (int i = 0; i < numRecorded; i++){
    if (arr[i] != buffer[i]) return false;
  }
  return true;
}

bool NodeGame::compare(int arr[], int len){
  if (len < numRecorded) return false;
  for (int i = 0; i < numRecorded; i++){
    if (arr[i] != buffer[i]) return false;
  }
  return true;
}

bool NodeGame::match(const int arr[], int len){
  if (len != numRecorded) return false;
  compare(arr, len);
}

bool NodeGame::match(int arr[], int len){
  if (len != numRecorded) return false;
  compare(arr, len);
}

void NodeGame::clear(){
  numRecorded = 0;
}

bool NodeGame::isEmpty(){
  if (numRecorded == 0) return true;
  else return false;
}

void NodeGame::print(){
  Serial.print("[ ");
  for (int i = 0; i < numRecorded; i++){
    Serial.print(nodes[buffer[i]]->getName());
    Serial.print(" ");
  }
  Serial.print("]");
}

