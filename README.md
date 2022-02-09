# Tiles
Project is part of Stanford's CS 106B: Programming Abstractions Course and the code authored can be found in src/tilelist.cpp and src/tilelist.h

This problem focuses on manipulating a linked list using pointers, implemented as a C++ class.

Problem Description:

In this problem you will write the logic for a graphical program that allows the user to click on rectangular "tiles." This program is a bit like the window manager of your operating system. When the program runs, no tiles will be present, but you can click buttons to add random tiles to the window. Some tiles overlap and occupy the same (x, y) pixels. We think of the tiles as having a "z­ordering" where the tile created/added later is "on top" of prior tiles and is able to partially cover them on the screen.

Depending on the user's action, one of several different actions occurs:

Highlight: If the user clicks a tile while the "Highlight" radio button is selected, that tile's color is changed to yellow. (To do this, set the color member variable of the tile node to the string "yellow".) Its x/y position and z­ordering do not change.

Raise: If the user clicks a tile while the "Raise" radio button is selected, that tile is moved to the very top of the list's z­ordering (the front of the linked list).

Lower: If the user clicks a tile while the "Lower" radio button is selected, that tile is moved to the very bottom of the list's z­ ordering (the back of the linked list).

Remove: If the user clicks a tile while the "Remove" radio button is selected, that tile is removed from the tile list and disappears from the screen.

Remove All: If the user clicks an (x, y) pixel while the "Remove All" radio button is selected, all tiles that touch that (x, y) position are removed from the tile list and disappear from the screen.

Add to Front/Back: If the user clicks one of the Add buttons, one or more new random tiles are created and added to the front or back of the list.

Clear: If the user clicks the Clear button, all tiles are removed from the list and screen.
