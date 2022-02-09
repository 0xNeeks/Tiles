/* Name: Nicholas Cuevas (SCPD Student)
 * Course: CS106B
 * Section Leader: Diwakar Ganesan (cganesan)
 * Assignment Description:
 * This assignment file is the cpp file of the TileList Assignment.
 * In this file, you will find the function implementations for the tilelist class.
 * Late Days Used: 0
*/

#include "tilelist.h"

/*
 * The TieList default constructor sets the front pointer to nullptr when a new TileList is created.
 * The front pointer will point to the first TileNode of the list when added to the list.
 */
TileList::TileList() {
    front = nullptr;
}

/*
 * The TieList destructor sets calls the clear method in order to remove each TileNode
 * and deallocate the memory.
 */
TileList::~TileList() {
    clear();
}

/*
 * The addBack function passes a pointer to a TileNode as its parameter.
 * The function adds the TileNode to the back of the TileList based on two conditions.
 * The first check is if the TileList is empty (containing no TileNodes), then the front pointer will
 * point to this TileNode and its next pointer is nullptr.
 * Otherwise, traverse the TileList until the current node's next pointer is null, then add the new node
 * as current's next, as well as set the newNode's next to nullptr.
 */
void TileList::addBack(TileNode* newNode) {
    if (front == nullptr) {
        front = newNode;
        newNode->next = nullptr;

    } else {
        TileNode* curr = front;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = nullptr;
    }
}

/*
 * The addFront function passes a pointer to a TileNode as its parameter.
 * The function adds the TileNode to the front of the TileList based on two conditions.
 * The first check is if the TileList is empty (containing no TileNodes), then the front pointer will
 * point to this TileNode and its next pointer is nullptr.
 * Otherwise, this newNode's next pointer will point to the current front node,
 * then the front pointer will point to this newNode.
 */
void TileList::addFront(TileNode* newNode) {
    if (front == nullptr) {
        front = newNode;
        newNode->next = nullptr;

    } else {
        newNode->next = front;
        front = newNode;
    }
}

/*
 * The debug function is optional and is used to traverse the list, keep count of the nodes,
 * as well as provide additional information like the address of the node and its next node.
 */
void TileList::debug() {
    TileNode* curr = front;
    int count = 0;
    cout << "Front points to: " << front << endl;
    while (curr != nullptr) {
        cout << "This is linked list node: " << count << endl;
        cout << "It is color: " << curr->color << endl;
        cout << "The address is: " << curr << endl;
        cout << "The next node is: " << curr->next << endl;
        curr = curr->next;
        count++;
    }
}

/*
 * The getFront function returns a TileNode pointer.
 * This function returns a pointer to the front node of the TileList.
 */
TileNode* TileList::getFront() const {
   return front;
}

/*
 * The highlight function passes an x and y integer coordinate of the tile.
 * The function highlights the front TileNode with the given x and y coordinate.
 * This is done by traversing the list, checking if a node contains the x and y coordinate, and if
 * it does then sets that node's color to yellow before breaking out of the loop.
 */
void TileList::highlight(int x, int y) {
    TileNode* curr = front;
    while (curr != nullptr) {
        if (curr->contains(x,y)) {
            curr->color = "yellow";
            break;
        }
        curr = curr->next;
    }
}

/*
 * The lower function passes an x and y integer coordinate of the tile.
 * The function lowers the front TileNode with the given x and y coordinate to the back of the TileList.
 * This is done by traversing the list, checking if a node contains the x and y coordinate, and if
 * it does then adds that node to the back of the list, followed by breaking out of the loop.
 * A special case is when the front node contains the x and y coordinate and/or it is the only node in the list.
 * Then that node was the first TileNode with the correct x and y coordinate, so it is immediately added to the back of the list
 * and setting the front pointer to point to the current front's next.
 * Otherwise, the conditional statement checks the next of the current node for containing the x and y coordinate in order to
 * properly set the next pointer of the current node since there is no previous pointer to properly set pointers. This node is then added
 * to the back of the TileList.
 */
void TileList::lower(int x, int y) {
    TileNode* curr = front;
    while (curr->next != nullptr) {
        if (front->contains(x,y)) {
            TileNode* nodeToLower = front;
            front = front->next;
            addBack(nodeToLower);
            break;

        } else if (curr->next->contains(x,y)) {
            TileNode* nodeToLower = curr->next;
            curr->next = curr->next->next;
            addBack(nodeToLower);
            break;
        }

        curr = curr->next;
    }

}

/*
 * The raise function passes an x and y integer coordinate of the tile and returns a boolean of whether a tile was raised.
 * The function follows the same logic as lower, but instead of breaking out of the loop when the tile is raised, it returns true immediately.
 * A special case is when the front node contains the x and y coordinate and/or it is the only node in the list.
 * Then that node was the first TileNode with the correct x and y coordinate, so it is immediately added to the front of the list
 * and setting the front pointer to point to the current front's next, as well as returning true.
 * Otherwise, the conditional statement checks the next of the current node for containing the x and y coordinate in order to
 * properly set the next pointer of the current node since there is no previous pointer to properly set pointers. This node is then added
 * to the front of the TileList and the function returns true.
 * If no tile is found and the list has been fully traversed, the function returns false.
 */
bool TileList::raise(int x, int y) {
    TileNode* curr = front;
    while (curr->next != nullptr) {
        if (front->contains(x,y)) {
            TileNode* nodeToRaise = front;
            front = front->next;
            addFront(nodeToRaise);
            return true;

        } else if (curr->next->contains(x,y)) {
            TileNode* nodeToRaise = curr->next;
            curr->next = curr->next->next;
            addFront(nodeToRaise);
            return true;
        }
        curr = curr->next;
    }

    return false;
}

/*
 * The remove function passes an x and y integer coordinate of the tile and returns a TileNode pointer to the removed tile.
 * The function first checks if the front pointer is set to nullptr and if so, returns null ptr.
 * Next, the function checks if the front node of the TileList contains the x and y coordinate. If so, it sets a temporary TileNode
 * pointer to the current front node, then sets the front pointer to the current front's next. The node to return has its next pointer
 * set to nullptr and is returned.
 * Otherwise, the function traverses the list, checking the next of the current node for the x and y coordinate. This follows the same logic as
 * lower and raise functions for properly setting the current node's next pointer if the next node is the one to remove and return.
 * The TileNode to remove has its next set to null ptr and is returned.
 * If no TileNode is found with the x and y coordinate then nullptr is returned.
 */
TileNode* TileList::remove(int x, int y) {
    if (front == nullptr) {
        return nullptr;
    }

    if (front->contains(x,y)) {
        TileNode* tileToReturn = front;
        front = front->next;
        tileToReturn->next = nullptr;
        return tileToReturn;

    }

    TileNode* curr = front;
    while (curr->next != nullptr) {
        if (curr->next->contains(x,y)) {
            TileNode* tileToReturn = curr->next;
            curr->next = curr->next->next;
            tileToReturn->next = nullptr;
            return tileToReturn;
        }
        curr = curr->next;
    }

    return nullptr;
}

/*
 * The removeAll function removes all TileNodes from the list and deallocates the memory for the passed in x and y coordinate.
 * The function keeps count of the number of tiles removed for an x and y coordinate, as well as removing the tile and deallocating its memory from the list.
 * If the front pointer is null (when the list is empty) or there is no tile at the x,y coordinate, then the function returns a count of zero.
 * The function uses two TileNode pointers to keep track of location while traversing the list, as well as four cases for removing from the list.
 * First, the front node in a single-node list is checked and if it contains the x,y coordinate then that node is removed, setting the front pointer to nullptr
 * as an empty list and the breaks out of the loop because there are no more nodes to check.
 * Second, the case when the front node contains the x,y coordinate but is not the only node in the list. This resets the front pointer to the next node and removes
 * the front node which contains the x,y coordinates. The current pointer is set to the new front as well.
 * This has to be explicit and not grouped with the middle node case because the trail is still nullptr and won't be set to curr until the second iteration.
 * The third case is when the current pointer contains the x,y coordinate and is not at the end of the list. The trail pointer is used to reconnect the links
 * between the previous and next of the node to remove. The trail pointer is used because no previous pointer is allowed for this assignment.
 * The final case is when at the end of the list and the last node contains the x,y coordinate. This removes that node and sets the trailing pointer (the previous node
 * of the one removed) to nullptr then breaks out of the loop since there are no nodes left to check.
 */
int TileList::removeAll(int x, int y) {
    int countOfTileRemoved = 0;

    if (front == nullptr) {
        return countOfTileRemoved;
    }

    TileNode* curr = front;
    TileNode* trail = nullptr;
    while (curr != nullptr) {
        if (front->contains(x,y) && front->next == nullptr) { //removes the first node of a one node list
            TileNode* tileToRemove = front;
            countOfTileRemoved++;
            delete tileToRemove;
            front = nullptr;
            break;

        } else if (front->contains(x,y) && front->next != nullptr) { //removes the first node in a non-single-node list
            TileNode* tileToRemove = front;
            front = front->next;
            curr = front;
            delete tileToRemove;
            countOfTileRemoved++;

        } else if (curr->contains(x,y) && curr->next != nullptr) { //removes the middle node in a non-single-node list
            TileNode* tileToRemove = curr;
            trail->next = curr->next;
            curr = trail->next;
            countOfTileRemoved++;
            delete tileToRemove;

        } else if (curr->contains(x,y) && curr->next == nullptr) { //removes the last node in a non-single-node list
           TileNode* tileToRemove = curr;
           trail->next = nullptr;
           countOfTileRemoved++;
           delete tileToRemove;
           break;
        }

        trail = curr;
        curr = curr->next;

    }

    return countOfTileRemoved;
}

/*
 * The clear function removes all TileNodes from the list and deallocates the memory.
 * The function traverses the TileList while the front pointer is not nullptr, then sets a
 * temporary TileNode pointer to the current front node, sets the front pointer to the next node,
 * then deletes the current node. This deallocates all the memory as well as removing each TileNode.
 */
void TileList::clear() {
    while (front != nullptr) {
        TileNode* temp = front;
        front = front->next;
        delete temp;
    }

}
