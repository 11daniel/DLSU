#include <stdio.h>

int checkRow(int sudoku[9][9]) 
{
  int c[10] = {0};
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      c[sudoku[i][j]]++;
    }
    for (int k = 1; k <= 9; k++) {
      if (c[k] != 1) 
      {
        return 0;
      }
    }
    for (int k = 1; k <= 9; k++) {
      c[k] = 0;
    }
  }
  return 1;
}

int checkColumn(int sudoku[9][9]) 
{
  int c[10] = {0};
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      c[sudoku[j][i]]++;
    }
    for (int k = 1; k <= 9; k++) {
      if (c[k] != 1) 
      {
        return 0;
      }
    }
    for (int k = 1; k <= 9; k++) {
      c[k] = 0;
    }
  }
  return 1;
}

int checkCube (int sudoku[9][9]) {
  int c[10] = {0}, count = 0;
  for (int m = 0; m < 9; m += 3) {
    for (int b = 0; b < 9; b += 3) {
      for (int i = m; i < m + 3; i++) {
        for (int j = b; j < b + 3; j++) {
          c[sudoku[i][j]]++;
        }
      }
      count++;
      for (int k = 1; k <= 9; k++) {
        if (c[k] != 1) {
          return 0;
        }
      }
      for (int k = 1; k <= 9; k++) {
          c[k] = 0;
        }
    }
  }
  return 1;
}

int main(void) {
  int sudoku[9][9] = 
          { { 7, 9, 2, 1, 5, 4, 3, 8, 6 },
            { 6, 4, 3, 8, 2, 7, 1, 5, 9 },
            { 8, 5, 1, 3, 9, 6, 7, 2, 4 },
            { 2, 6, 5, 9, 7, 3, 8, 4, 1 },
            { 4, 8, 9, 5, 6, 1, 2, 7, 3 },
            { 3, 1, 7, 4, 8, 2, 9, 6, 5 },
            { 1, 3, 6, 7, 4, 8, 5, 9, 2 },
            { 9, 7, 4, 2, 1, 5, 6, 3, 8 },
            { 5, 2, 8, 6, 3, 9, 4, 1, 7 } };
  
  if (checkRow(sudoku) == 1 && checkColumn(sudoku) == 1 && checkCube(sudoku) == 1) {
    printf("Valid");
  }
  else {
    printf("Invalid!");
  }
  return 0;
}
