/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Daniel Gavrie Clemente - 12206202 - S19B    
******************************************************************************/
/*   
     Description:      This program runs and creates a turn-based tile shooter game.
     Programmed by:    Daniel Gavrie Clemente   S19B
     Last modified:    12/04/22
     Version:          28
    [Acknowledgements: <list of sites or borrowed libraries and sources>]
*/
#include <stdio.h>


/*   The function draws the columns for the board and also draws the enemy to their respective positions
     Precondition: values for the enemy rows and columns are pre-defined and are postive values
     @param e1row is the enemy 1 row position
     @param e2row is the enemy 2 row position
     @param e3row is the enemy 3 row position
     @param e1col is the enemy 1 column position
     @param e2col is the enemy 2 column position
     @param e3col is the enemy 3 column position
     @param currentRow is a parameter to check if either e1row/e2row/e3row are on the same row
     @return the positions of the enemy in their respective columns
*/
void drawColumns(int e1Row, int e1Col, int e2Row, int e2Col, int e3Row, int e3Col, int currentRow) {
  char enemy = 'X';
  int enemyHasCollision = 0;
  for (int i = 0; i < 9; i++) {
    enemyHasCollision = 0;
    if (i % 2 == 0) {
      printf("|");
    }
    else {
      if ((e1Col == i && e1Row == currentRow) || (e2Col == i && e2Row == currentRow) || (e3Col == i && e3Row == currentRow)) {
        if ((e1Col == i && e1Row == currentRow)) {
          // checks if E1 column is equal to i and E1 row is equal to current row
          if (e2Row == currentRow || e3Row == currentRow) {
            if (e1Col == e2Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (e1Col == e3Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (enemyHasCollision == 0) {
              printf("%c", enemy);
            }
          }
          else {
          printf("%c", enemy);
          }
        }
        if (e2Col == i && e2Row == currentRow) {
          if (e1Row == currentRow || e3Row == currentRow) { 
            //checks if enemy 1 or enemy 3 are on the same row as the currentRow
            if (e2Col == e1Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (e2Col == e3Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (enemyHasCollision == 0) {
              printf("%c", enemy);
            }
          }
          else {
            printf("%c", enemy);
          }
        }
        if (e3Col == i && e3Row == currentRow) {
          if (e1Row == currentRow || e2Row == currentRow) {
            //checks if enemy 1 or enemy 2 are on the same row as the currentRow
            if (e3Col == e2Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (e3Col == e1Col && enemyHasCollision == 0) {
              printf("%c", enemy);
              enemyHasCollision = 1;
            }
            if (enemyHasCollision == 0) {
              printf("%c", enemy);
            }
          }
          else {
            printf("%c", enemy);
          }
        }
      } 
      else {
        printf(" ");
      }
    }
  }
}


/*   This function draws the empty columns not filled by the enemy
     @return empty columns for the game board
*/
void drawEmptyColumns() {
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      printf("|");
    }
    else {
      printf(" ");
    }
  }
}

/*   This function draws the rows needed for the game board
     Precondition: positions of enemy rows and columns are positive
     @param e1row is the enemy 1 row position
     @param e2row is the enemy 2 row position
     @param e3row is the enemy 3 row position
     @param e1col is the enemy 1 column position
     @param e2col is the enemy 2 column position
     @param e3col is the enemy 3 column position
     @return the rows drawn
*/
void drawRows(int e1Row, int e1Col, int e2Row, int e2Col, int e3Row, int e3Col) {
  for (int i = 0; i < 5; i++) {
    if (e1Row == i || e2Row == i || e3Row == i) {
      drawColumns(e1Row, e1Col, e2Row, e2Col, e3Row, e3Col, i);
    } 
    else {
      drawEmptyColumns();
    }
    printf("\n");
  }
}


/*   This function draws the row where the player is positioned
     Precondition: player column starts at the 1st column
     @param pCol is the column where the player is positioned
     @return the row where the player is positioned
*/
void drawPlayerRow(int pCol) {
  for (int i = 0; i < 9; i++) {
    if (i % 2 == 0) {
      printf("|");
    } 
    else {
      if (i == pCol) {
        printf("P");
      }
      else {
        printf(" ");
      }
    }
  }
}

/*   This function draws the game board
     Precondition: all parameters are met and have values stored in them
     @param e1row is the enemy 1 row position
     @param e2row is the enemy 2 row position
     @param e3row is the enemy 3 row position
     @param e1col is the enemy 1 column position
     @param e2col is the enemy 2 column position
     @param e3col is the enemy 3 column position
     @param pCol is the column where the player is positioned
     @return the game board
*/
void drawGrid(int e1Row, int e1Col, int e2Row, int e2Col, int e3Row, int e3Col, int pCol) {
  drawRows(e1Row, e1Col, e2Row, e2Col, e3Row, e3Col);
  printf("|-------|\n");
  drawPlayerRow(pCol);
}

/*   This function displays choices for the player movement and receives the action from the player
     @return the action of the player as an integer
*/
int askPlayerInput(){
  //This function asks the player input by giving choices on what key controls the player movement.
  int nInput;
  printf("\nActions:\n");
  printf("1 - Move Left\n");
  printf("2 - Move Right\n");
  printf("3 - Fire Laser\n");
  printf("4 - Reset Board\n");
  printf("Input Action: ");
  scanf("%d", &nInput);
  return nInput;
}

/*   This function checks whether the input is valid or not
     Precondition: the input is a positive integer from 1 to 4
     @param nInput is the value of the input
     @return the resulting value if the input is greater than 4 or not
*/
int isInputValid(int nInput) {
  if (nInput > 4) {
    return 0;
  }
  return 1;
}

/*   This functions checks the enemy's position and decides whether its should move down or not
     Precondition: enemyRow and enemyCol are positive integers
     @param enemyRow is the enemy's position on a certain row
     @param enemyCol is the enemy's position on a certain column
     @return True (1) or False (0) 
*/
int shouldEnemyMoveDown(int enemyRow, int enemyCol) {
  if (enemyRow % 2 == 0) {
    if (enemyCol + 2 > 7) {
      return 1;
    }
  } 
  else {
    if (enemyCol - 2 < 1) {
      return 1;
    }
  }
  return 0;
}

/*   This function checks if the game has ended 
     Precondition: score is below 100 and enemyWins does not equal 0
     @param score is the score value of the player
     @return the result when the score reaches 100 points or enemy passes the line 
*/
int hasGameEnded(int score, int enemyWins){
  if(score >=100){
    return 1;
  }
  if(enemyWins == 0) {
    return 1;
  }
  return 0;
}

int main() {
  int e1Row = 0, e1Col = 1;
  int e2Row = 0, e2Col = 3;
  int e3Row = 0, e3Col = 5;
  int pCol = 1;
  int score = 0;

  drawGrid(e1Row, e1Col, e2Row, e2Col, e3Row, e3Col, pCol);

  int input = 100; // arbitrary number not equal to 0, 0 ends the game

  while (!hasGameEnded(score, input)) {
    do {
    input = askPlayerInput();
    }
    while (!isInputValid(input));

    if (input == 1 || input == 2) {
      //player moves 
      if (input == 1) {
        if (!(pCol - 2 < 1)) {
          pCol -= 2;
        }
      }

      if (input == 2) {
        if (!(pCol + 2 > 7)) {
          pCol += 2;
        }
      }
    }

    //fire laser
    if (input == 3) {
      int hit = 0;
  
      if (pCol == e1Col) { //hit counting
          hit++;
      }
      if (pCol == e2Col) {
          hit++;
      }
      if (pCol == e3Col) {
        hit++;
      }

      if (pCol == e1Col) {
        printf("Hit : E1\n");
        score += 10;
        //spawn
        e1Row = 0;
        e1Col = 1;

        //check if coordinates is empty
        for (int i = 0; i < hit; i++) {
          if ((e1Col == e2Col && e1Row == e2Row) || (e1Col == e3Col && e1Row == e3Col)) {
            e1Col += 2;
          }
        }
      }

      if (pCol == e2Col) {
        printf("Hit : E2\n");
        score += 10;
        //spawn
        e2Row = 0;
        e2Col = 1;

        //check if coordinates is empty
        for (int i = 0; i < hit; i++){
          if ((e2Col == e1Col && e2Row == e1Row) || (e2Col == e3Col && e2Row == e3Row)) {
            e2Col += 2;
          } 
        }
      }

      if (pCol == e3Col) {
        printf("Hit : E3\n");
        score += 10;
        //spawn
        e3Row = 0;
        e3Col = 1;

        //check if coordinates is empty
        for (int i = 0; i < hit; i++) {
          if ((e3Col == e1Col && e3Row == e1Row ) || (e3Col == e2Col && e3Row == e2Row)) {
            e3Col += 2;
          }
        }
      }

      if(score >= 100){
        printf("\n");
        printf("You Win!");
        printf("\n");
      }
    }
    
    //enemy moves
    int moveE1 = 0, moveE2 = 0, moveE3 =0;
    //detemine which enemy is on the same row
    if (e1Row == e2Row && e1Row == e3Row) {
      moveE1 = 1;
      moveE2 = 1;
      moveE3 = 1;
    }
    else if (e1Row == e2Row) {
      moveE1 = 1;
      moveE2 = 1;
    }
    else if (e1Row == e3Row) {
      moveE1 = 1;
      moveE3 = 1;
    }
    else if (e2Row == e3Row) {
      moveE2 = 1;
      moveE3 = 1;
    }

    //move only the enemy on the same row at the same time
    //all Enemies are on the same row
    if(moveE1 == 1 && moveE2 == 1 && moveE3 == 1){
      if(shouldEnemyMoveDown(e1Row, e1Col) || shouldEnemyMoveDown(e2Row, e2Col) || shouldEnemyMoveDown(e3Row, e3Col)){
        e1Row += 1;
        e2Row = e1Row;
        e3Row = e1Row;
      } 
      else {
        //move left or right
        if (e1Row % 2 == 0) {
          e1Col += 2;
          e2Col += 2;
          e3Col += 2;
        } 
        else {
          e1Col -= 2;
          e2Col -= 2;
          e3Col -= 2;
        }
      }
    } 
    //E1 and E2 are on the same row
    else if(moveE1 == 1 && moveE2 == 1){
      // Move E1 & E2 at the same time
      if(shouldEnemyMoveDown(e1Row, e1Col) || shouldEnemyMoveDown(e2Row, e2Col)){
        e1Row += 1;
        e2Row = e1Row;
      } else {
        //move left or right
        if (e1Row % 2 == 0) {
          e1Col += 2;
          e2Col += 2;
        } else {
          e1Col -= 2;
          e2Col -= 2;
        }
      }
      // Move E3 independently
      if(shouldEnemyMoveDown(e3Row, e3Col)) {
        e3Row += 1;
      } else {
        //move left or right
        if (e3Row % 2 == 0) {
          e3Col += 2;
        } else {
          e3Col -= 2;
        }
      }
    } 
    //E1 and E3 are on the same row
    else if(moveE1 == 1 && moveE3 == 1){
      // Move E1 & E3 at the same time
      if(shouldEnemyMoveDown(e1Row, e1Col) || shouldEnemyMoveDown(e3Row, e3Col)){
        e1Row += 1;
        e3Row = e1Row;
      } 
      else {
        //move left or right
        if (e1Row % 2 == 0) {
          e1Col += 2;
          e3Col += 2;
        } else {
          e1Col -= 2;
          e3Col -= 2;
        }
      }
      // Move E2 independently
      if(shouldEnemyMoveDown(e2Row, e2Col)) {
        e2Row += 1;
      } 
      else {
        //move left or right
        if (e2Row % 2 == 0) {
          e2Col += 2;
        } else {
          e2Col -= 2;
        }
      }
    } 
    //E2 and E3 are on the same row
    else if(moveE2 == 1 && moveE3 == 1){
      if(moveE2 == 1 && moveE3 == 1){
        // Move E2 & E3 at the same time
        if(shouldEnemyMoveDown(e2Row, e2Col) ||
          shouldEnemyMoveDown(e3Row, e3Col)){
          e2Row += 1;
          e3Row = e2Row;
        } 
        else {
          //move left or right
          if (e2Row % 2 == 0) {
            e2Col += 2;
            e3Col += 2;
          } else {
            e2Col -= 2;
            e3Col -= 2;
          }
        }
        // Move E1 independently
        if(shouldEnemyMoveDown(e1Row, e1Col)) {
          e1Row += 1;
        } 
        else {
          //move left or right
          if (e1Row % 2 == 0) {
            e1Col += 2;
          } else {
            e1Col -= 2;
          }
        }
      }
    } 
    else {
      if (shouldEnemyMoveDown(e1Row, e1Col)) {
        e1Row += 1;
      }
      else {
        //move left or right
        if (e1Row % 2 == 0) {
          e1Col += 2;
        } else {
          e1Col -= 2;
        }
      }
      if (shouldEnemyMoveDown(e2Row, e2Col)) {
        e2Row += 1;
      }
      else {
        //move left or right
        if (e2Row % 2 == 0) {
          e2Col += 2;
        } else {
          e2Col -= 2;
        }
      }
      if (shouldEnemyMoveDown(e3Row, e3Col)) {
        e3Row += 1;
      }
      else {
        //move left or right
        if (e3Row % 2 == 0) {
          e3Col += 2;
        } else {
          e3Col -= 2;
        }
      }
    }

    //enemy wins if it reaches the fifth row
    if(e1Row > 4 || e2Row > 4 || e3Row > 4){
      printf("\n");
      printf("You Lose!");
      printf("\n");
      input = 0;
    }

    if (input == 4){ // resets board
      e1Row = 0; e1Col = 1;
      e2Row = 0; e2Col = 3;
      e3Row = 0; e3Col = 5;
      pCol = 1;
      score = 0;
    }

    drawGrid(e1Row, e1Col, e2Row, e2Col, e3Row, e3Col, pCol);
    printf("\n");
    printf("Score : %d", score);
  }
}