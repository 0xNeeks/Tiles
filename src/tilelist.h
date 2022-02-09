/* Name: Nicholas Cuevas (SCPD Student)
 * Course: CS106B
 * Section Leader: Diwakar Ganesan (cganesan)
 * Assignment Description:
 * This assignment file is the header file of the tilelist class for the TileList Assignment.
 * In this file, you will find the function declarations for the tilelist class,
 * as well ast he private member variable front (a pointer to the first TileNode).
 * Late Days Used: 0
*/

#ifndef _tilelist_h
#define _tilelist_h

#include <iostream>
#include <string>
#include "tilenode.h"
using namespace std;

class TileList {
public:
    TileList();
    ~TileList();
    void addFront(TileNode* node);
    void addBack(TileNode* node);
    void clear();
    void debug();
    TileNode* getFront() const;
    void highlight(int x, int y);
    void lower(int x, int y);
    bool raise(int x, int y);
    TileNode* remove(int x, int y);
    int removeAll(int x, int y);

private:
    TileNode* front;
};

#endif // _tilelist_h
