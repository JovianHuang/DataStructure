#ifndef MAZESTACK_H
#define MAZESTACK_H

/* standrad header files */
#include <stdio.h>
#include <stdlib.h>
/* standrad header files */

/* Predefine */
#define ROW 11
#define COLUMN 11
typedef int StatusType;
struct MNode {
  StatusType **status;  // To storage the status of this cell
  int row;              // The length of this maze
  int column;           // The width of this maze
  bool initialization;  // To identify if the maze has been initialized
};
typedef struct MNode *Maze;
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



#endif // !MAZESTACK_H
