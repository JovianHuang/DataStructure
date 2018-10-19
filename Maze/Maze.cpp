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
    printf("The file: %s does not exist, maze initialization failed!", filename);
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
        M->status[i][j] = temp - '0';
      }
    }
  }
  fclose(fp);
  M->initialization = true;
  return M;
}

void PrintMaze(Maze M) {
  for (int i = 0; i < M->row; i++) {
    for (int j = 0; j < M->column; j++) {
      printf("%d", M->status[i][j]);
    }
    printf("\n");
  }
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

