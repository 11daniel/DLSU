#include <stdio.h>

struct aTag {
  char ch;
  int i;
};

struct bTag {
  float f;
  double d;
};

struct cTag {
  struct aTag a;
  struct bTag b;
  int A[5];
};

typedef struct aTag aType;
typedef struct bTag bType;
typedef struct cTag cType;


aType a, A[5];
bType b, B[5];
cType c, C[5];

/*
aType *pa;
bType *pb;
cType *pc;
*/

int Minimum(cType c) {
  int i;
  int min = 0;

  for (i = 0; i < 5; i++) {
    //printf("%d\n", c.A[i]);
    if (c.A[min] > c.A[i]) {
      min = i;
    }
  }
  return c.A[min];
}

float fMinimum(bType B[], int n) {
  int i;
  int min = 0;

  for (i = 1; i < n; i++) {
    if (B[min].f > B[i].f) {
      min = i;
    }
  }
  return B[min].f;
}

double dMaximum(bType B[], int n) {
  int i;
  int max = 0;

  for (i = 0; i < n; i++) {
    if (B[max].d < B[i].d) {
      max = i;
    }
  }
  return B[max].d;
}

void SortFunc1(aType A[], int n) {
  int i;
  int j;
  int min;
  int temp;

  for (i = 0; i < n; i++) {
    min = i;

    for (j = i + 1; j < n; j++) {
      if (A[min].i > A[j].i) {
        min = j;
      }
    }

    if (i != min) {
      temp = A[i].i;
      A[i].i = A[min].i;
      A[min].i = temp;
    }
  }
}

void SortFunc2(bType B[], int n) {
  int i;
  int j;
  int max;
  int temp;

  for (i = 0; i < n; i++) {
    max = i;

    for (j = i + 1; j < n; j++) {
      if (B[max].d < B[j].d) {
        max = j;
      }
    }
    if (i != max) {
      temp = B[i].d;
      B[i].d = B[max].d;
      B[max].d = temp;
    }
  }
}

int main(void) {

  int i;

  for (i = 0; i < 5; i++) {
    printf("Enter inputs: ");
    scanf("%d", &c.A[i]);
    //printf("%d\n", c.A[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("Enter finputs: ");
    scanf("%f", &B[i].f);
    //printf("%f\n", B[i].d);
  }

  for (i = 0; i < 5; i++) {
    printf("Enter dinputs: ");
    scanf("%d", &B[i].d);
    //printf("%lf\n", B[i].d);
  }

  for (i = 0; i < 5; i++) {
    printf("Enter sort1 inputs: ");
    scanf("%d", &A[i].i);
     //printf("%d\n", A[i].i);
    // printf("%d\n", c.A[i]);
  }
  
  for (i = 0; i < 5; i++) {
    printf("Enter sort2 inputs: ");
    scanf("%lf", &B[i].d);
     //printf("%lf\n", B[i].d);
    // printf("%d\n", c.A[i]);
  }

  printf("Minimum: %d\n", Minimum(c));
  printf("fMinimum: %f\n", fMinimum(B, 5));
  printf("dMaximum: %d\n", dMaximum(B, 5));
  //printf("SortFunc1: \n");
  SortFunc1(A, 5);

  for (i = 0; i < 5; i++)
    printf("SortFunc1: %d\n", A[i].i);
  
  SortFunc2(B, 5);
  
  for (i = 0; i < 5; i++)
    printf("SortFunc2: %f\n", B[i].d);

  return 0;
}
