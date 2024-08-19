#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXROW 9
#define MAXCOL 8

typedef char str20[21];
typedef char str99[100];

typedef struct elevatorTag {
  int capacity;
  int currCapacity;
  int attraction;
  int coin;
  int mobility;
  int hp;
  int score;
  str20 drip;
} elevatorType;

typedef struct customerTag {
  int tip;
  int floor;
  str20 look;
  int size;
  int i;        // randomize
  int j;        // first 3 have index 1 and last 2 has index 7
  int movement; // + or - 1 based on j
} customerType;
