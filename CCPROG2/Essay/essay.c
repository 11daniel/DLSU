#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char filename[40];
    char c;

    //counting variables
    int letters = 0;
    int upperLetters = 0;
    int lowerLetters = 0;
    int lines = 0;
    int upperVowels = 0;
    int lowerVowels = 0;
    int upperCons = 0;
    int lowerCons = 0;


    FILE *fp;

    strcpy(filename, "essay.txt");

    if ((fp = fopen("essay.txt", "r")) == NULL) {
        fprintf(stderr, "ERROR: %s does not exist.\n", filename);
        exit(1);
    }

    while(fscanf(fp,"%c", &c) == 1) {

        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
            letters++;
        }
        if(c >= 65 && c <= 90) {
            upperLetters++;
        }

        if (c >= 97 && c <= 122 ) {
            lowerLetters++;
        }

        if (c == 65 || c == 69 || c == 73 || c == 79 || c == 85) {
            upperVowels++;
        }

        if (c == 97 || c == 101 || c == 105 || c == 111 || c == 117) {
            lowerVowels++;
        }

        if ((c != 65 || c != 69 || c != 73 || c != 79 || c != 85) && (c >= 65 && c <= 90)) {
            upperCons++;
        }

        if ((c != 97 || c != 101 || c != 105 || c != 111 || c != 117) && (c >= 97 && c <= 122)) {
            lowerCons++;
        }

        else if (c == '\n') {
            lines++;
        }

    }

    fprintf(stdout, "letters: %d\n", letters);
    fprintf(stdout, "upperLetters: %d\n", upperLetters);
    fprintf(stdout, "lowerLetters: %d\n", lowerLetters);
    fprintf(stdout, "lines: %d\n", lines);
    fprintf(stdout, "upperVowels: %d\n", upperVowels);
    fprintf(stdout, "lowerVowels: %d\n", lowerVowels);
    fprintf(stdout, "upperCons: %d\n", upperCons);
    fprintf(stdout, "lowerCons: %d\n", lowerCons);

    fclose(fp);


    return 0;
}