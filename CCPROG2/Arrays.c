#include <stdio.h>
#define SIZE 8

int CountOdd(int A[], int n) {
  int i;
  int count = 0;
  for (i = 0; i < n; i++) {
    if (A[i] % 2 == 1) {
      count++;
    }
  }
  return count;
}

int Minimum(int A[], int n) {
  int i;
  int min = 0;

  for (i = 1; i < n; i++) {
    if (A[min] > A[i]) {
      min = i;
    }
  }
  return A[min];
}

int Maximum(int A[], int n) {
  int i;
  int max = 0;

  for (i = 1; i < n; i++) {
    if (A[max] < A[i]) {
      max = i;
    }
  }
  return A[max];
}

int Sum(int A[], int n) {
  int acc = 0;
  for (int i = 0; i < n; i++) {
    acc += A[i];
  }
  return acc;
}

int CountUpper(char S[], int n) {
  int i;
  int count = 0;
  for (i = 0; i < n; i++) {
    if (S[i] >= 65 && S[i] <= 90) {
      count++;
    }
  }
  return count;
}

int main(void) {
  int A[SIZE] = {10, 23, 11, 63, -55, 99, -20, 88};
  
  char S[7] = {'C', 'o', 'M', 'p', 'r', 'o', '2'};
  
  printf("Nummber of Odd Numbers: %d\n", CountOdd(A, SIZE));
    
  printf("Minimum value: %d\n", Minimum(A, SIZE));
  
  printf("Maximum value: %d\n", Maximum(A, SIZE));

  printf("Total Sum of the Array: %d\n", Sum(A, SIZE));
  
  printf("Number of Upper Case letters: %d\n", CountUpper(S, 7));
  return 0;
}
