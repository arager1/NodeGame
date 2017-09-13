#ifndef NODEGAME_H
#define NODEGAME_H

#include "Node.h"
#include "Notes.h"

// Allocate space in nodes[]
const int maxNodes = 5; 
// Allocate space in buffer[]       
const int maxRecord = 128;

// Provides methods to record button presses and 
// compare them to other button sequences. When 
// using this library, the buffer must be compared 
// to arrays of ints that coorespond to an index 
// into NodeGame's nodes[]. This allows users to 
// create constant array patterns without knowledge 
// of the nodes themselves. Nodes are added in 
// order to ensure the user can find the node they
// want. The buffer clears itself when the recording 
// reaches the maxRecord limit.
class NodeGame {
  public:
    // Input noisemaker pin. Sets initial values.
    NodeGame(int p);
    // Delete nodes from heap
    ~NodeGame();

    // If there are less than maxNodes already added, 
    // construct a new node on the heap. Stores nodes
    // in nodes[] in order added.
    void addNode(const char *n, int l, int b, int p);
    // Return node pointer at index i in nodes[]
    // Returns NULL if i is out of range
    Node *getNode(int i);

    // Record button presses into buffer in the form 
    // of its index in nodes[]. Returns true when a 
    // button is released.
    bool read();    

    // Can input a const or non-const array to be 
    // compared to buffer. Must also input the array
    // size as len. If buffer matches arr for as many 
    // elements as are in buffer, return true. 
    bool compare(const int arr[], int len); 
    bool compare(int arr[], int len);

    // Can input a const or non-const array to be 
    // compared to buffer. Must also input the array
    // size as len. If buffer is identical to arr for 
    // all len elements, return true.
    bool match(const int arr[], int len); 
    bool match(int arr[], int len);

    // Clear the recording buffer.
    void clear();     
    // Return true if recording buffer is empty.      
    bool isEmpty();

    // Print the recording buffer
    void print(); 

  private:
    // Array storing ponters to nodes.
    Node *nodes[maxNodes];  
    int numNodes;     

    // Buffer to record button presses in the form
    // of the node's index in nodes[].
    int buffer[maxRecord];    
    int numRecorded;    

    int pinPiezo;
};


#endif
