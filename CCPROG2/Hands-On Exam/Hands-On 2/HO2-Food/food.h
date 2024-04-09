/* You are NOT allowed to modify the contents of this file */

#include <stdio.h>
#include <string.h>

#define MAX 15

typedef char string[31]; //Assume all strings are 1 word only

struct foodTag
{  string foodName,  //example: carrot
          category;  //example: vegetable [Do NOT assume that only protein and nuts are the other categories]
   float  calories;  //calories per gram
};
typedef struct foodTag foodType;

struct ingredientTag
{  string foodName; //example: carrot
   int    quantity; // amount in grams
};
typedef struct ingredientTag ingredientType;
typedef ingredientType arrIngredients[MAX];

struct menuItemTag
{  string         viandName;  //example: adobo
   arrIngredients aList;
   int            numIng;    //number of ingredients initialized in aList
   float          totalCal;  //to be initialized in Q3()
};
typedef struct menuItemTag itemType;

    
//Function prototypes 
float Q1(char * param_food, foodType foodList[], int nElem);

int Q2(char * param_category, foodType foodList[], int nElem,
       itemType viand);
	   
void Q3(itemType * viand, foodType foodList[], int nElem);

void Q4(itemType recommended[], int *pReco, char * param_restrict,
        char * param_category, itemType menu[], int nMenu,
        foodType foodList[], int nElem);
   