#include <stdbool.h>
#include <stdio.h>

// Global variables; they are used for convenience.
// System initialization.
bool turn = true, over = false;
int S[3][3] = {0}, Peg[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
// printTiles prints a 3 x 3 board.
void printTiles(void) {
  printf("  1 2 3\n\n");
  for (int i = 0; i < 3; i++) {
    switch (i) {
    case 0:
      printf("1 ");
      break;
    case 1:
      printf("2 ");
      break;
    case 2:
      printf("3 ");
      break;
    }
    for (int j = 0; j < 3; j++) {
      if (S[i][j] != 0) {
        if (j < 2)
          printf("%d|", S[i][j]);
        else
          printf("%d\n", S[i][j]);
      } else {
        if (j < 2)
          printf(" |");
        else
          printf(" \n");
      }
    }
    if (i < 2)
      printf("  -----\n");
    else
      printf("\n\n");
  }
}

/*
nextPlayerMove places a number on a specific tile and returns boolean values
for input validation.
@param peg - an integer
@param x - an integer x - coordinate of a tile.
@param y - an integer y - coordinate of a tile.
@return false if at least one input is invalid.
@return true if all inputs are valid.
*/
bool nextPlayerMove(int peg, int x, int y) {
  // Peg[peg - 1]: peg is an element of Peg.
  // 1 <= x && x <= 3 && 1 <= y && y <= 3 && S[y-1][y -1] == 0:
  // pos is an element of Free.
  if (Peg[peg - 1] && 1 <= x && x <= 3 && 1 <= y && y <= 3 &&
      S[y - 1][x - 1] == 0) {
    Peg[peg - 1] = 0;      // A selected integer is removed from a set.
    S[y - 1][x - 1] = peg; // An inputed slot becomes occupied.
    return true;
  }
  return false;
}

/*
gameOver checks the conditions for game over and displays outcomes as well as
exits a game if there are.
*/
void gameOver(void) {
  // Existential quantifier
  // In a column or row or all, there should not be 0.
  // The sum of the numbers must be less than 15.

  // Universal quantifier
  // In all columns and rows, there should not be 0.
  // The sum of the numbers must be equal to 15.
  // There are 16 solutions.

  // uq - universal quantifier  eq - existential quantifier
  // uq = uq && (conditions)    eq = eq || (conditions)
  int y, x, sumRow, sumCol, countRow, countCol;
  bool uq = true, eq = false;

  // Rows: One, Two, and Three
  // Computes and checks the sum and the cardinality of each row.
  for (y = 0; y < 3; y++) {
    sumRow = 0;
    countRow = 0;
    for (x = 0; x < 3; x++) {
      sumRow += S[y][x];
      if (S[y][x] > 0)
        countRow++;
    }
    eq = eq || (sumRow < 15 && countRow == 3);
    uq = uq && (sumRow == 15) && (countRow == 3);
  }

  // Columns: Four, Five, and Six
  // Computes and checks the sum and the cardinality of each column.
  for (x = 0; x < 3; x++) {
    sumCol = 0;
    countCol = 0;
    for (y = 0; y < 3; y++) {
      sumCol += S[y][x];
      if (S[y][x] > 0)
        countCol++;
    }
    eq = eq || (sumCol < 15 && countCol == 3);
    uq = uq && (sumCol == 15) && (countCol == 3);
  }

  if (eq || uq) { // Checks for gameover conditions.
    over = !over; // A game is finished.
    if (turn) {
      if (eq)
        printf("B wins.\n"); // Outcome 1 *Check CCDSTRU MP specifications.
      if (uq)
        printf("A wins.\n"); // Outcome 3
    } else {
      if (eq)
        printf("A wins.\n"); // Outcome 2
      if (uq)
        printf("B wins.\n"); // Outcome 4
    }
  } else
    turn = !turn; // If no gameover conditions, next turn for an opponent.
}

int main(void) {
  int peg, row, col;
  bool ok;
  printTiles(); // Print a 3 x 3 game.
  while (!over) {
    /*Player B or A enters a specific integer from 1 to 9
    and places in a coordinate*/
    if (turn)
      printf("Player B:\n"); // Player B's turn
    else
      printf("Player A:\n"); // Player A's turn
    do {
      printf("Choose a number from 1 to 9: ");
      scanf("%d", &peg); // Asks to enter an unpicked integer from 1 to 9.
      printf("Enter a coordinate (row, column): ");
      scanf("%d %d", &row, &col); // Asks to enter a coordinate of a free slot.
      printf("y: %d  x: %d\n", row, col);
      // Checks entered inputs.
      if (!(ok = nextPlayerMove(peg, col, row)))
        printf("Invalid input(s)\n"); // Reminds a player for invalid inputs.
      // If the inputs are invalid, a player is again asked to enter correct
      // ones.
    } while (!ok);
    printTiles(); // Print a 3 x 3 game.
    // Checks for gameover conditions.
    // If none, turn variable is inverted for an opponent's turn.
    // If there are, results are displayed and over is inverted to exit the
    // game.
    gameOver();
  }
  return 0;
}