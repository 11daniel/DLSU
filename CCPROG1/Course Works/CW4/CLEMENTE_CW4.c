#include <stdio.h>

int main() {
    int nEarthMonth, nEarthDay, nDaveDay;
    printf("Input Earth Month: ");
    scanf("%d", &nEarthMonth);
    printf("Input Earth Day: ");
    scanf("%d", &nEarthDay);

    if (nEarthMonth == 1) { /*January*/
        if (nEarthDay <= 15) {
            printf("January %d", nEarthDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 15;
            printf("February %d", nDaveDay);
        }
        else {
            nDaveDay = nEarthDay - 30;
            printf("March %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 2) { /*February*/
        if (nEarthDay <= 14) {
            nDaveDay = nEarthDay + 1;
            printf("March %d", nDaveDay);
        }
        else if (nEarthDay <= 28) {
            nDaveDay = nEarthDay - 14;
            printf("April %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 3) { /*March*/
        if (nEarthDay == 1) {
            printf("April 15");
        }
        else if (nEarthDay <= 16) {
            nDaveDay = nEarthDay - 1;
            printf("May %d", nDaveDay);
        }
        else if (nEarthDay <= 31) {
            nDaveDay = nEarthDay - 16;
            printf("June %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 4) { /*April*/
        if (nEarthDay <= 15) {
            printf("July %d", nEarthDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 15;
            printf("August %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 5) { /*May*/
        if (nEarthDay <= 15) {
            printf("September %d", nEarthDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 15;
            printf("October %d", nDaveDay);
        }
        else {
            nDaveDay = nEarthDay - 30;
            printf("November %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 6) { /*June*/
        if (nEarthDay <= 14) {
            nDaveDay = nEarthDay + 1;
            printf("November %d", nDaveDay);
        }
        else if (nEarthDay <= 29) {
            nDaveDay = nEarthDay - 14;
            printf("December %d", nDaveDay);
        }
        else if (nEarthDay == 30) {
            printf("January 1");
        }
    }
    else if (nEarthMonth == 7) { /*July*/
        if (nEarthDay <= 14) {
            nDaveDay = nEarthDay + 1;
            printf("January %d", nDaveDay);
        }
        else if (nEarthDay <= 29) {
            nDaveDay = nEarthDay - 14;
            printf("February %d", nDaveDay);
        }
        else if (nEarthDay <= 31) {
            nDaveDay = nEarthDay - 29;
            printf("March %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 8) { /*August*/
        if (nEarthDay <= 13) {
            nDaveDay = nEarthDay + 2;
            printf("March %d", nDaveDay);
        }
        else if (nEarthDay <= 28) {
            nDaveDay = nEarthDay - 13;
            printf("April %d", nDaveDay);
        }
        else if (nEarthDay <= 31) {
            nDaveDay = nEarthDay - 28;
            printf("May %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 9) { /*September*/
        if (nEarthDay <= 12) {
            nDaveDay = nEarthDay + 3;
            printf("May %d", nDaveDay);
        }
        else if (nEarthDay <= 27) {
            nDaveDay = nEarthDay - 12;
            printf("June %d", nDaveDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 27;
            printf("July %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 10) { /*October*/
        if (nEarthDay <= 12) {
            nDaveDay = nEarthDay + 3;
            printf("July %d", nDaveDay);
        }
        else if (nEarthDay <= 27) {
            nDaveDay = nEarthDay - 12;
            printf("August %d", nDaveDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 27;
            printf("September %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 11) { /*November*/
        if (nEarthDay <= 11) {
            nDaveDay = nEarthDay + 4;
            printf("September %d", nDaveDay);
        }
        else if (nEarthDay <= 26) {
            nDaveDay = nEarthDay - 11;
            printf("October %d", nDaveDay);
        }
        else if (nEarthDay <= 30) {
            nDaveDay = nEarthDay - 26;
            printf("November %d", nDaveDay);
        }
    }
    else if (nEarthMonth == 12) { /*December*/
        if (nEarthDay <= 11) {
            nDaveDay = nEarthDay + 4;
            printf("November %d", nDaveDay);
        }
        else if (nEarthDay <= 26) {
            nDaveDay = nEarthDay - 11;
            printf("December %d", nDaveDay);
        }
        else if (nEarthDay <= 31) {
            nDaveDay = nEarthDay - 26;
            printf("Special %d", nDaveDay);
        }
    }
    return 0;
}