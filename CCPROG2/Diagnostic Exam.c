#include <stdio.h>

int displayMenu() {
	int nChoice;
	printf("1: BAL CHECK\n");
	printf("2: WITHDRAW\n");
	printf("3: DEPOSIT\n");
	printf("4: EXIT\n");
	printf("CHOOSE OPTION: ");
	scanf("%d", &nChoice);
	return nChoice;
}

int withdrawMenu() {
	int withdrawal;
	printf("How much would like to withdraw?: ");
	scanf("%d", &withdrawal);
	return withdrawal;
}

int depositMenu() {
	int nDeposit;
	printf("How much would like to deposit?: ");
	scanf("%d", &nDeposit);
	return nDeposit;
}

int main() {
	int PIN;
	int correctPIN = 1234;
	int count = 0;
	int nChoice;
	int BAL = 100000;
	int newBAL;
	int minusMoney;
	int addMoney;
	
	while (count < 3) {
		printf("Enter PIN number: ");
		scanf("%d", &PIN);
	
		if (PIN == correctPIN) {
			nChoice = displayMenu();
			
			if (nChoice == 1) {
				printf("BALANCE: %d", BAL);
				printf("\n");
			}
			else if (nChoice == 2) {
				minusMoney = withdrawMenu();
				
				if (minusMoney > BAL) {
					printf("Insufficient funds\n");
				}
				else {
					newBAL = BAL - minusMoney;
					BAL = newBAL;
					printf("BALANCE: %d", BAL);
					printf("\n");
				}
			}
			else if (nChoice == 3) {
				addMoney = depositMenu();
				newBAL = BAL + addMoney;
				BAL = newBAL;
				printf("BALANCE: %d", BAL);
				printf("\n");
			}
			else if (nChoice == 4) {
				printf("Thank you for using our services!\n");
				count += 3;
			}
		}
		else {
			printf("Error! Please try again!\n");
			count++;
		}

	}
	
	return 0;
}
