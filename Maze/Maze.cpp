#include "MazesolutionStack.h"
#include "Maze.h"

Maze CreateMazePrototype(void) {
  Maze M;
  M = (Maze)malloc(sizeof(MNode));
  // malloc a two-dimensional array
  M->status = (StatusType **)malloc(sizeof(StatusType *) * ROW);
  for (int i = 0; i < ROW; i++) {
    M->status[i] = (StatusType *)malloc(sizeof(StatusType) * COLUMN);
  }
  M->row = ROW;
  M->column = COLUMN;
  M->initialization = false;
  return M;
}

Maze GetMazeFromFile(Maze M, const char * filename) {
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("The file: \"%s\" does not exist, maze initialization failed!", filename);
    return M;
  }
  int temp;
  for (int i = 0; i < M->row; i++) {
    for (int j = 0; j < M->column; j++) {
      temp = fgetc(fp);
      if (temp == '\n') {
        j--;  // Avoid getting carriage return
        continue;
      } else {
        M->status[i][j] = temp;
      }
    }
  }
  fclose(fp);
  M->initialization = true;
  return M;
}

void PrintMaze(Maze M) {
  if (M->initialization == false) {
    puts("Note: This maze has not been initialized yet.");
  }
  for (int i = 0; i < M->row; i++) {
    for (int j = 0; j < M->column; j++) {
      printf("%c", M->status[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void DisposeMaze(Maze M) {
  if (M != NULL) {
    for (int i = 0; i < M->column; i++) {
      free(M->status[i]);
    }
    free(M->status);
    free(M);
  }
}

void FindGate(Maze M, Position& start, Position& end) {
  if (M->initialization == false) {
    puts("ERROR: This maze has not been initialized yet.");
    puts("Failed to find gate.");
    return;
  }
  int i, j;
  bool found = false;
  for (i = 0; i < M->row && !found; i++) {
    for (j = 0; j < M->column; j++) {
      if (M->status[i][j] == '2') {
        start.row = i;
        start.column = j;
        found = true;
        break;
      }
    }
  }
  found = false;
  for (i; i < M->row && !found; i++) {
    for (j = 0; j < M->column; j++) {
      if (M->status[i][j] == '2') {
        end.row = i;
        end.column = j;
        found = true;
        break;
      }
    }
  }
}

bool Pass(const Maze M, Position curpos) {
  if (OutOfBound(curpos)) {
    return false;
  }
  if (M->status[curpos.row][curpos.column] == '0' || M->status[curpos.row][curpos.column] == '2') {
    return true;
  } else {
    return false;
  }
}

bool OutOfBound(Position pos) {
  if (pos.row < 0 || pos.row > ROW) {
    return true;
  } else if (pos.column < 0 || pos.column > COLUMN) {
    return true;
  } else {
    return false;
  }
}

void FootPrint(Maze &M, Position curpos) {
  M->status[curpos.row][curpos.column] = '*';
}

void MarkPrint(Maze &M, Position curpos) {
  M->status[curpos.row][curpos.column] = '@';
}

void NextDir(DirEnum& dir) {
  switch (dir) {
    case Up:
    {
      dir = Right;
      break;
    }
    case Right:
    {
      dir = Down;
      break;
    }
    case Down:
    {
      dir = Left;
      break;
    }
    case Left:
    {
      dir = Up;
      break;
    }
  }
}

Position NextPos(Position curpos, DirEnum dir) {
  switch (dir) {
    case Up:
    {
      curpos.row--;
      break;
    }
    case Right:
    {
      curpos.column++;
      break;
    }
    case Down:
    {
      curpos.row++;
      break;
    }
    case Left:
    {
      curpos.column--;
      break;
    }
  }
  return curpos;
}

Maze CopyMaze(Maze source) {
  Maze newMaze = CreateMazePrototype();
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN; j++) {
      newMaze->status[i][j] = source->status[i][j];
    }
  }
  newMaze->initialization = true;
  return newMaze;
}