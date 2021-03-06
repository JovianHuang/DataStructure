#ifndef MAZE_H
#define MAZE_H

/* standrad header files */
#include <stdio.h>
#include <stdlib.h>
/* standrad header files */

/* Predefine */
#define ROW 11
#define COLUMN 11
typedef char StatusType;
struct MNode {
  StatusType **status;  // To storage the status of this cell
  int row;              // The length of this maze
  int column;           // The width of this maze
  bool initialization;  // To identify if the maze has been initialized
};
typedef struct MNode *Maze;
struct Position {
  int row;
  int column;
};
enum DirEnum {
  Up = 0,
  Right,
  Down,
  Left
};
/* Predefine */

Maze CreateMazePrototype(void);
// Operation-result: Create an uninitialized maze.

Maze GetMazeFromFile(Maze M, const char * filename);
// Preconditions: Maze M and the file containing maze information already exists.
// Operation-result: The maze is initialized.

void PrintMaze(Maze M);
// Preconditions: Maze M already exists.
// Operation-result: Print the maze to the screen.

void DisposeMaze(Maze M);
// Preconditions: Maze M already exists
// Operation-result: The two-dimensional array standing of maze was freed.

void FindGate(Maze M, Position & start, Position & end);
// Preconditions: Maze M already exists, besides both entrance and exit must exists
// Operation-result: Find the gate of the maze

bool Pass(const Maze M, Position curpos);
// Operation-result: To know can it pass

bool OutOfBound(Position pos);
// Operation-result: To check if this position out of bound

void FootPrint(Maze &M, Position curpos);
// Operation-result: Identifies this block to show that it have passed

void MarkPrint(Maze &M, Position curpos);
// Operation-result: Identifies this block to show that no way to go\

void NextDir(DirEnum & dir);
// Operation-result: To change the dir

Position NextPos(Position curpos, DirEnum dir);
// Operation-result: To know next block to go

Maze CopyMaze(Maze source);
// Operation-result: Copy a maze

#endif // !MAZE_H
