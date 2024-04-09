/*
    Compile:    gcc -Wall Prompts.c CW5.c -o run.exe
    Execution:  run.exe or ./run.exe
*/

#include <stdio.h>
#include "Prompts.h"

int EnemyMoves(int m)
{
    int EnemyAction = 0;
    switch(m) {
        case 1:
            showEnemyAction(1);
            EnemyAction = 1;
            break;
        case 2:
            showEnemyAction(2);
            EnemyAction = 2;
            break;
        case 3:
            showEnemyAction(1);
            EnemyAction = 1;
            break;
        case 4:
            showEnemyAction(3);
            EnemyAction = 3;
            break;
        case 5:
            showEnemyAction(2);
            EnemyAction = 2;
            break;
    }
    return EnemyAction;
}

int isPlayerWins(int PlayerHP, int MachineHP) {
    if (PlayerHP > 0 && MachineHP == 0) 
    {
        return 1;
    }
    return 0;
}

int isMachineWins(int PlayerHP, int MachineHP) 
{
    if (PlayerHP == 0) 
    {
        return 1;
    }
    return 0;
}

int main()
{
    int PlayerHP = 9;
    int MachineHP = 9;
    int EnemyMovement = 1;
    int PlayerAction = 0;
    int EnemyAction = 0;

    while(!isPlayerWins(PlayerHP, MachineHP) && !isMachineWins(PlayerHP, MachineHP)) {
        displayHPs(PlayerHP, MachineHP);
        PlayerAction = askPlayerInput();
        switch(PlayerAction) 
        {
            case 1:
                showPlayerAction(PlayerAction);
                MachineHP -= 3;
                break;
            case 2:
                showPlayerAction(PlayerAction);
                break;
            case 3:
                if (PlayerHP < 9)
                {
                    showPlayerAction(PlayerAction);
                    PlayerHP += 3;
                }
                break;
        }
        
        //printf("Enemy movement: %d\n", EnemyMovement);
        EnemyAction = EnemyMoves(EnemyMovement);
        EnemyMovement++;
        switch(EnemyAction) 
        {
            case 1:
                if (PlayerAction == 1) {
                    PlayerHP -= 3;
                }
                break;
            case 2:
                if(PlayerAction == 1) {
                    MachineHP += 3;
                }
                break;
            case 3:
                if (MachineHP < 9)
                {
                    MachineHP += 3;
                }
                break;
        }
        if (EnemyMovement > 5) 
        {
            EnemyMovement = 1;
        }
        //PlayerHP--;
        //printf("Player HP: %d\n", PlayerHP);
    }

    if (isPlayerWins(PlayerHP, MachineHP))
    {
        showPlayerWin();
    }
    else
    {
        showPlayerLose();
    }

    return 0;
}
