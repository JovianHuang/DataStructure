#include "MazeSolutionStack.h"

int main(int argc, char *argv[]) {
  Maze M = CreateMazePrototype();
  puts("Please enter the name of the maze information source:");
  char filename[10];
  scanf("%s", filename);
  M = GetMazeFromFile(M, filename);
  if (M->initialization) {
    puts("This is the maze you just got:");
    PrintMaze(M);
    if (MazePathStack(M)) {
      puts("This maze can be solved, and this is the answer:");
      PrintMaze(M);
    } else {
      puts("This maze can not be solved.");
      PrintMaze(M);
    }
  }
  DisposeMaze(M);
  return 0;
}