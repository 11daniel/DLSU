#ifndef SYSTEM_PROMPTS
#define SYSTEM_PROMPTS

#include <stdio.h>

int askPlayerInput();
void displayHPs(int nPlayerHP, int nEnemyHP);
void showPlayerAction(int nAction);
void showEnemyAction(int nAction);
void showPlayerWin();
void showPlayerLose();

#endif
