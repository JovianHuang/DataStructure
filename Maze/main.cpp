#include "MazeSolutionStack.h"
#include "MazeSolutionQueue.h"

int main(int argc, char *argv[]) {
  Maze M = CreateMazePrototype();
  puts("Please enter the name of the maze information source:");
  char filename[10];
  scanf("%s%*c", filename);
  M = GetMazeFromFile(M, filename);
  if (M->initialization) {
    puts("This is the maze you just got:");
    PrintMaze(M);
  }
  bool(*soulution)(Maze);
  while (true) {
    puts("What method are you going to find the way?");
    puts("a) Stack");
    puts("b) Queue");
    int t;
    t = getchar();
    if (t == 'a') {
      soulution = MazePathStack;
      break;
    } else if (t == 'b') {
      soulution = MazePathQueue;
      break;
    } else {
      puts("Invaild input, try again.");
    }
  }
  if ((*soulution)(M)) {
    puts("This maze can be solved, and this is the answer:");
    PrintMaze(M);
  } else {
    puts("This maze can not be solved.");
    PrintMaze(M);
  }
  DisposeMaze(M);
  return 0;
}