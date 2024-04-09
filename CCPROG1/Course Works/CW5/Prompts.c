#include "Prompts.h"

int askPlayerInput(){
    int nInput;
    printf("\n1 - Attack\n");
    printf("2 - Defend\n");
    printf("3 - Heal\n");
    printf("Input Action: ");
    scanf("%d", &nInput);
    return nInput;
}

void displayHPs(int nPlayerHP, int nEnemyHP){
    printf("\nPlayer %d/9\n", nPlayerHP);
    printf("Enemy  %d/9\n", nEnemyHP);
}

void showPlayerAction(int nAction){
    switch(nAction){
        case 1: printf("\nPlayer Attacks\n"); break;
        case 2: printf("\nPlayer defends\n"); break;
        case 3: printf("\nPlayer Heals 3HP\n"); break;
    }//end switch
}

void showEnemyAction(int nAction){
    switch(nAction){
        case 1: printf("\nEnemy Attacks\n"); break;
        case 2: printf("\nEnemy defends\n"); break;
        case 3: printf("\nEnemy Heals 3HP\n"); break;
    }//end switch
}

void showPlayerWin(){
	printf("\nPlayer Wins!\n");
}

void showPlayerLose(){
	printf("\nPlayer Loses\n");
}
