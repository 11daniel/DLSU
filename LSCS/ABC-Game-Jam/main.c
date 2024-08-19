#include "structs.h"

void black() { printf("\033[0;30m"); }
void red() { printf("\033[0;31m"); }
void green() { printf("\033[0;32m"); }
void yellow() { printf("\033[0;33m"); }
void blue() { printf("\033[0;34m"); }
void purple() { printf("\033[0;35m"); }
void cyan() { printf("\033[0;36m"); }
void white() { printf("\033[0;37m"); }
void reset() { printf("\033[0m"); }

// this function initializes the playing field by assigning a character value to
// a specific cell in the array based on their position.
void initializeField(char S[][MAXCOL]) {
  int i, j;
  for (i = 0; i < MAXROW; i++)
    for (j = 0; j < MAXCOL; j++) {
      // '-' top and bottom
      if (i == 0 || i == MAXROW - 1)
        S[i][j] = '-';
      else
        S[i][j] = '|';
    }
}

// Initialize enemies.
void initializeEnemy(customerType C[][5]) {
  srand(time(NULL)); // For i and j.
  int tip_arr[10] = {2, 1, 5, 10, 5, 3, 10, 15, 20, 5},
      floor_arr[10] = {4, 1, 7, 5, 6, 2, 3, 1, 7, 4},
      size_arr[10] = {1, 2, 1, 5, 3, 2, 5, 10, 20, 2}, hori_arr[10],
      verti_arr[10], move_arr[10]; // i, j, movement
  str20 look_arr[10] = {"o", "O", "₱", "88", "B)", "T", "€>", "€D", "<^>", "€"};
  int i, j;
  // Stage 1 enemies
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 5; j++) {
      C[i][j].tip = tip_arr[i];
      C[i][j].floor = floor_arr[i];
      strcpy(C[i][j].look, look_arr[i]);
      C[i][j].size = size_arr[i];
      C[i][j].i = C[i][j].floor;
      // C[i][j].j
      switch (i) {
      case 0: // Stage 1
      case 1:
      case 2:
        if (rand() % 2 == 0)
          C[i][j].j = 0;
        else
          C[i][j].j = 6;
        break;
        /*
      case 3: // Stage 2
      case 4:
      case 5:
        switch (rand() % 4) {
        case 0:
          C[i][j].j = 0;
          break;
        case 1:
          C[i][j].j = 1;
          break;
        case 2:
          C[i][j].j = 5;
          break;
        case 3:
          C[i][j].j = 6;
        }
        break;
      case 6: // Stage 3
      case 7:
      case 8:
      case 9:
        switch (rand() % 6) {
        case 0:
          C[i][j].j = 0;
          break;
        case 1:
          C[i][j].j = 1;
          break;
        case 2:
          C[i][j].j = 2;
          break;
        case 3:
          C[i][j].j = 4;
          break;
        case 4:
          C[i][j].j = 5;
          break;
        case 5:
          C[i][j].j = 6;
        }
        break;
        */
      }
      // Movement
      switch (i) {
      // Stage 1
      case 0:
      case 1:
      case 2:
        if (0 <= j && j < 3)
          C[i][j].movement = 1;
        else
          C[i][j].movement = -1;
        break;
      // Stage 2
      default:
        if (0 <= j && j < 3)
          C[i][j].movement = 1;
        else
          C[i][j].movement = -1;
        break;
      }
    }
  }
}

void moveEnemy(customerType C[][5]) {
  int i, j, jfinal;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 5; j++) {
      jfinal = C[i][j].j + C[i][j].movement;
      if (0 <= jfinal && jfinal <= 6) {
        C[i][j].j = jfinal;
        if (C[i][j].j == 0 || C[i][j].j == 6)
          C[i][j].movement *= -1; // Movement is reversed.
      }
    }
  }
}

void attributeShop(elevatorType *e) {
  int nCase = 0;
  int confirm = 0;
  printf("\n|---------------------------------------|\n");
  printf("|              ELEVATOR SHOP!           |\n");
  printf("|---------------------------------------|\n");
  printf("|                                       |\n");
  printf("|        1 - Capacity Expansion         |\n");
  printf("|        2 - Speed Upgrade              |\n");
  printf("|        3 - Improve Attraction         |\n");
  printf("|        4 - Upgrade Exterior           |\n");
  printf("|        5 - Exit Shop                  |\n");
  printf("|                                       |\n");
  printf("|---------------------------------------|\n\n");
  do {
    printf("COINS: %d\n", e->coin);
    printf("What would you like to do?\n");
    scanf("%d", &nCase);
    switch (nCase) {
    case 1:
      if (e->capacity == 3) {
        printf("Purchase Upgrade for 10 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 10 && confirm) {
          printf("CAPACITY INCREASED BY 2!\n");
          e->capacity += 2;
          e->coin -= 10;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else if (e->capacity == 5) {
        printf("Purchase Upgrade for 50 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 50) {
          printf("CAPACITY INCREASED BY 5!");
          e->capacity += 5;
          e->coin -= 50;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else if (e->capacity == 10) {
        printf("Purchase Upgrade for 100 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 100) {
          printf("CAPACITY INCREASED BY 5!");
          e->capacity += 5;
          e->coin -= 100;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else if (e->capacity == 15) {
        printf("Purchase Upgrade for 250 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 250) {
          printf("CAPACITY INCREASED BY 10!");
          e->capacity += 10;
          e->coin -= 250;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else
        printf("MAX LEVEL REACHED!\n");
      break;

    case 2:
      if (e->mobility == 1) {
        printf("Purchase Upgrade for 30 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 30 && confirm) {
          printf("MOBILITY INCREASED BY 1!\n");
          e->mobility += 1;
          e->coin -= 30;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else if (e->mobility == 2) {
        printf("Purchase Upgrade for 100 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 100) {
          printf("MOBILITY INCREASED BY 1!");
          e->mobility += 1;
          e->coin -= 100;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
      } else if (e->mobility == 3) {
        printf("Purchase Upgrade for 250 COINS? PRESS 1 FOR YES, 0 IF NO\n");
        scanf("%d", &confirm);
        if (e->coin >= 250) {
          printf("MOBILITY INCREASED BY 1!");
          e->mobility += 1;
          e->coin -= 250;
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
        else
          printf("MAX LEVEL REACHED!\n");

        break;

      case 3:
        if (e->attraction == 0) {
          printf("Purchase Upgrade for 100 COINS? PRESS 1 FOR YES, 0 IF NO\n");
          scanf("%d", &confirm);
          if (e->coin >= 100 && confirm) {
            printf("ELEVATOR HAS BEEN DRIPPED OUT! TIP IS DOUBLED\n");
            e->attraction += 1;
            e->coin -= 100;
            strcpy(e->drip, "{|}");
          }
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
        else
          printf("MAX LEVEL REACHED!\n");

        break;

      case 4:
        if (e->hp == 2) {
          printf("Purchase Upgrade for 100 COINS? PRESS 1 FOR YES, 0 IF NO\n");
          scanf("%d", &confirm);
          if (e->coin >= 100 && confirm) {
            printf("ELEVATOR FORTIFIED!\n");
            e->hp += 1;
            e->coin -= 100;
          }
        } else if (confirm)
          printf("NOT ENOUGH MONEY!\n");
        else
          printf("MAX LEVEL REACHED!\n");
        break;

      case 5:

        break;
      }
    }
  } while (nCase != 5);
  system("clear");
}

void printAttrib(elevatorType e) {
  printf("CAPACITY: %d/%d  ", e.currCapacity, e.capacity);
  if (e.attraction == 1)
    printf("DOUBLE PAY! ");

  printf("MOBILITY: %d ", e.mobility);
}

void printTopBar(elevatorType e) {
  printf("HP: %d\t", e.hp);
  printf("SCORE: %d\t", e.score);
  printf("COINS: %d\n", e.coin);
}

void printFieldBuilding(char S[][MAXCOL], int playerPos, elevatorType e,
                        customerType C[][5]) {
  int i, j;
  for (i = 0; i < MAXROW; i++) { // prints the floor number
    if (i >= 1 && i <= 7)
      printf("\033[0;30m%d", i);
    for (j = 0; j < MAXCOL; j++)
      if (j == MAXCOL / 2 - 1 &&
          i == playerPos) { // prints the player and a corresponding '|'
                            // character if playerPos is equal to the i index
        printf("\033[0;30m%c", S[i][j]);
        printf(" \033[0;37m%s ", e.drip);
      } else if (j == MAXCOL / 2 - 1 &&
                 S[i][j] == '|') // prints bigger spaces for the middle column
                                 // from the character '|'
        printf("\033[0;30m%-6c", S[i][j]);
      else if (S[i][j] == '|')
      {// prints the rest of the | on the field
        if (C[i][j].i == i && C[i][j].j == j)
         {
            printf("\033[0;30m%c", S[i][j]);
            if(strlen(C[i][j].look) == 3)
              printf("%s", C[i][j].look);
           else if(strlen(C[i][j].look) == 2)
             printf("%s ", C[i][j].look);
           else
              printf(" %s ", C[i][j].look);
         }
        else
        printf("\033[0;30m%-4c", S[i][j]);
         
      }
      else { // prints the top and bottom borders
        printf("\033[0;37m%-2c", S[i][j]);
        printf("\033[0;37m%-2c", S[i][j]);
      }
    printf("\n");
  }
}

int main(void) {
  int playerPos = MAXROW / 2;
  char input;
  char dump;
  elevatorType e;        // An elevator (Player)
  customerType c[10][5]; // An enemy array
  char Field[MAXROW][MAXCOL];
  e.currCapacity = 0;
  e.hp = 2;
  e.score = 0;
  e.mobility = 1;
  e.coin = 100;
  e.capacity = 3;
  e.attraction = 0;
  strcpy(e.drip, "[|]");
  initializeField(Field);
  initializeEnemy(c);
  do {
    if (playerPos < 1 || playerPos > 7) { // if elevator goes out of bounds
      printf("\033[0;31m  Elevator can't go that far!\n\033[0m");
      if (playerPos > 7) {
        if (input == 's') {
          playerPos -= 1;
        } else if (input == 'a') {
          playerPos -= 2;
        } else if (input == 'd') {
          playerPos -= 3;
        }
      }
      if (playerPos < 1) {
        if (input == 'w') {
          playerPos += 1;
        } else if (input == 'q') {
          playerPos += 2;
        } else if (input == 'e') {
          playerPos += 3;
        }
      }
    }
    // prints the entire game area
    printTopBar(e);
    printFieldBuilding(Field, playerPos, e, c);
    printAttrib(e);
    do {
      moveEnemy(c);
      printf("\n\033[0mActions:\n  w - Move Up\n  s - Move Down\n  p - Open "
             "Shop\n");
      if (e.mobility >= 2)
        printf("\033[0m  q - Move Up 2\n  a - Move Down 2\n");
      if (e.mobility >= 3)
        printf(
            "\033[0m  e - Move Up 3\n  d - Move Down 3\n"); // updates list of
                                                            // instructions
                                                            // based on mobilitu
      printf("Input action: ");
      scanf("%c%c", &input, &dump);
    } while (input != 'w' && input != 's' && input != 'p' && input != 'q' &&
             input != 'a');

    switch (input) {
      // movement options
    case 'w':
      playerPos--;
      break;
    case 's':
      playerPos++;
      break;
    case 'p':
      system("clear");
      attributeShop(&e);
      scanf("%c", &dump);
      break;
    case 'q':
      if (e.mobility >= 2) {
        // if (playerPos > 2)
        playerPos -= 2;
        // else if (playerPos != 1)
        //   playerPos--;
      }
      break;
    case 'a':
      if (e.mobility >= 2) {
        // if (playerPos < 6)
        playerPos += 2;
        // else if (playerPos != 7)
        //  playerPos++;
      }
      break;
    }
    system("clear"); // cls on the command prompt
  } while (e.score < 300 && e.hp > 0);

  return 0;
}