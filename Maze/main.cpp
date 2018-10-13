#include "Stack.h"
#include "MazeStack.h"

int main(int argc, char *argv[]) {
  Maze M = CreateMazePrototype();
  M = GetMazeFromFile(M, "Maze0.txt");
  PrintMaze(M);
  return 0;
}