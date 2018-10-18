#include "MazeStack.h"
#include "Maze.h"

int main(int argc, char *argv[]) {
  Maze M = CreateMazePrototype();
  M = GetMazeFromFile(M, "Maze0.txt");
  PrintMaze(M);
  DisposeMaze(M);
  return 0;
}