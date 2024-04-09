#include <stdio.h>
#include <string.h>

#define LEN1 26
#define LEN2 420
#define MAX  15

typedef char string[LEN1+1];
typedef char sentence[LEN2];
typedef string arrWords[MAX]; 

void getInput(sentence s);
void display(arrWords aWords, int nElem);

void Encrypt(string d, string s, string key);
void Decrypt(string d, string s, string key);
int Tokenize(arrWords aWords, sentence s);
void Merge(sentence s, arrWords aWords, int nWords);