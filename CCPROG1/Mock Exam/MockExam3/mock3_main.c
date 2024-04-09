// compile cmd: gcc -Wall mock3_main.c -o run.exe

#include <stdio.h>
#include "mock3_last.c"

int main(){
	printf("Largest %d: %d\n", 927452, findLargestDigit(927452));
	printf("       Correct: %d\n", 9);
	printf("Largest %d: %d\n", 123456, findLargestDigit(123456));
	printf("       Correct: %d\n", 6);
	printf("PowOver %6d: %d\n", 3212, firstPowOver(3212));
	printf("       Correct: %d\n", 4096);
	printf("PowOver %6d: %d\n", 65530, firstPowOver(65530));
	printf("       Correct: %d\n", 65536);
	printf("Reverse %6d: %d\n", 927452, reverseDigits(927452));
	printf("       Correct: %d\n", 254729);
	printf("Reverse %6d: %d\n", 123456, reverseDigits(123456));
	printf("       Correct: %d\n", 654321);
	printf("Pallind %6d: %d\n", 12321, isPallindrome(12321));
	printf("       Correct: %d\n", 1);
	printf("Pallind %6d: %d\n", 927452, isPallindrome(927452));
	printf("       Correct: %d\n", 0);
	printf("Display Chart : %d\n", 927452);
	displayChart(927452);
	printf("Correct:\n");
	printf("       **\n");
    printf("    *****\n");
    printf("     ****\n");
    printf("  *******\n");
    printf("       **\n");
    printf("*********\n");

    printf("Display Chart : %d\n", 123456);
	displayChart(123456);
	printf("Correct:\n");
	printf("   ******\n");
    printf("    *****\n");
    printf("     ****\n");
    printf("      ***\n");
    printf("       **\n");
    printf("        *\n");
	return 0;
}
