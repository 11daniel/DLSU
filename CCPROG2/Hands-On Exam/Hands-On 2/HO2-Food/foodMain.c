#include "CLEMENTE-FOOD.c"

/* Note that a different foodMain.c and or main() will be
   used in checking your answer in LASTNAME-FOOD.c.  Thus,
   the data used in the initialization are only samples.
   
   Any additional functions you may create and use should 
   only be defined in LASTNAME-FOOD.c and should only be
   called within the required functions.
*/

void
displayFoodList(foodType foodList[], int nElem)
{   int i;
    printf("\nFoodList:\n");
	for (i = 0; i < nElem; i++)
	  printf("%d. %32s %15s %.2fKcal/gram\n ", i+1,
	        foodList[i].foodName, foodList[i].category,
			foodList[i].calories );
	printf("\n");
}

void
displayMenuItem(itemType m[], int nMenu)
{
	int i, j;

	for (i = 0; i < nMenu; i++)
	{
		printf("Viand: %s, total calories = %.2f\n",
		       m[i].viandName, m[i].totalCal); //totalCal will be garbage if m[i] did not pass through Q3()
		printf("Ingredients:\n");
		for (j = 0; j < m[i].numIng; j++)
		   printf("  %d. %d grams %s\n", j+1, 
		         m[i].aList[j].quantity, m[i].aList[j].foodName);
		
		printf("\n");
	}
	printf("\n");
}

void initFoodList(foodType foodList[], int *pElem);

void initMenu(itemType menu[], int *pMenu);

int
main()
{  foodType foodList[MAX];
   int nElem;
   itemType menu[MAX], 
            recommended[MAX];
   int      nMenu, 
            nReco;         
    
   initFoodList(foodList, &nElem);
   initMenu(menu, &nMenu);
   /* You may call the display functions implemented above to
      assist you while you are debugging */
    
   //Testing Q1
   printf("cabbage = %.2f kcal per grams\n", 
         Q1("cabbage", foodList, nElem));
   printf("beef = %.2f kcal per grams\n", 
         Q1("beef", foodList, nElem));
   printf("\n");

   //Testing Q2
   printf("There are %d vegetable in %s\n",
           Q2("vegetable", foodList, nElem, menu[1]),
		   menu[1].viandName);
   printf("There are %d nuts in %s\n",
           Q2("nuts", foodList, nElem, menu[1]),
		   menu[1].viandName);
   printf("There are %d protein in %s\n",
           Q2("protein", foodList, nElem, menu[0]),
		   menu[0].viandName);
   printf("\n");

   //Testing Q3
   Q3(&menu[1], foodList, nElem);
   printf("%s has total of %.2f kcal\n", 
         menu[1].viandName, menu[1].totalCal);
   Q3(&menu[0], foodList, nElem);
   printf("%s has total of %.2f kcal\n", 
         menu[0].viandName, menu[0].totalCal);
   printf("\n");  
   
   //Testing Q4
   Q4(recommended, &nReco, "egg",
        "protein", menu, nMenu,
        foodList, nElem);
   printf("Recommended menu items if no egg and mostly protein\n");
   displayMenuItem(recommended, nReco);
   printf("\n");
 
   Q4(recommended, &nReco, "none",
        "protein", menu, nMenu,
        foodList, nElem);
   printf("Recommended menu items if no none and mostly protein\n");
   displayMenuItem(recommended, nReco);
   printf("\n");
 
   Q4(recommended, &nReco, "fish",
        "vegetable", menu, nMenu,
        foodList, nElem);
   printf("Recommended menu items if no fish and mostly vegetable\n");
   displayMenuItem(recommended, nReco);
   printf("\n");
    
   strcpy(foodList[4].category, "vegetable");
   Q4(recommended, &nReco, "nuts",
        "vegetable", menu, nMenu,
        foodList, nElem);
   printf("After tofu category changed to vegetable\n");
   printf("Recommended menu items if no nuts and mostly vegetable\n");
   displayMenuItem(recommended, nReco);
   printf("\n");
   return 0;
}


void
initFoodList(foodType foodList[], int *pElem)
{
	strcpy(foodList[0].foodName, "carrot");
	strcpy(foodList[0].category, "vegetable");
	foodList[0].calories = 0.41;
	
	strcpy(foodList[1].foodName, "egg");
	strcpy(foodList[1].category, "protein");
	foodList[1].calories = 0.97;
	
	strcpy(foodList[2].foodName, "pork");
	strcpy(foodList[2].category, "protein");
	foodList[2].calories = 1.96;
	
	strcpy(foodList[3].foodName, "cabbage");
	strcpy(foodList[3].category, "vegetable");
	foodList[3].calories = 0.25;
	
	strcpy(foodList[4].foodName, "tofu");
	strcpy(foodList[4].category, "protein");
	foodList[4].calories = 0.76;
	
	strcpy(foodList[5].foodName, "celery");
	strcpy(foodList[5].category, "vegetable");
	foodList[5].calories = 0.15;
	
	*pElem = 6;
}

void
initMenu(itemType menu[], int *pMenu)
{
	strcpy(menu[0].viandName, "adobo");
	menu[0].numIng = 3;
	strcpy(menu[0].aList[0].foodName, "pork");
	menu[0].aList[0].quantity = 200;
	strcpy(menu[0].aList[1].foodName, "chicken");
	menu[0].aList[1].quantity = 200;
	strcpy(menu[0].aList[2].foodName, "egg");
	menu[0].aList[2].quantity = 120;
	
	strcpy(menu[1].viandName, "lumpia");
	menu[1].numIng = 4;
	strcpy(menu[1].aList[0].foodName, "carrot");
	menu[1].aList[0].quantity = 100;
	strcpy(menu[1].aList[1].foodName, "tofu");
	menu[1].aList[1].quantity = 100;
	strcpy(menu[1].aList[2].foodName, "cabbage");
	menu[1].aList[2].quantity = 100;
	strcpy(menu[1].aList[3].foodName, "pork");
	menu[1].aList[3].quantity = 25;
	
	strcpy(menu[2].viandName, "tofuSisig");
	menu[2].numIng = 1;
	strcpy(menu[2].aList[0].foodName, "tofu");
	menu[2].aList[0].quantity = 300;

	strcpy(menu[3].viandName, "chopsuey");
	menu[3].numIng = 4;
	strcpy(menu[3].aList[0].foodName, "cabbage");
	menu[3].aList[0].quantity = 150;
	strcpy(menu[3].aList[1].foodName, "carrot");
	menu[3].aList[1].quantity = 150;
	strcpy(menu[3].aList[2].foodName, "celery");
	menu[3].aList[2].quantity = 100;
	strcpy(menu[3].aList[3].foodName, "pork");
	menu[3].aList[3].quantity = 50;
	
	*pMenu = 4;
}