/*************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts learned. 
I have constructed the functions and their respective algorithms and corresponding code by myself. 
The program was run, tested, and debugged by my own efforts. 
I further certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.

Julie Antonette C. Matibag, 12207650
Daniel Gavrie Y. Clemente, 12206202
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef char string[50];

// USER DIRECTIVE 
#define MAX_USERS 100
#define MAX_NAME 21 
#define MAX_PASSWORD 11 
#define MAX_EMAIL 31

//TRANSACTION DIRECTIVE
#define MAX_TRANSACTION_ITEMS 5

//CART DIRECTIVE
#define MAX_CART_ITEMS 10

//ITEM DIRECTIVE
#define MAX_SELLER_ITEM 20
#define MAX_ITEM_NAME 21 
#define MAX_CATEGORY_NAME 16 
#define MAX_DESCRIPTION 31

/*
Description: This structure is for the User records.
@param: int userID - a unique integer input by the user 
@param: char name[MAX_NAME] - string with a length of 21
@param: char password[MAX_PASSWORD] - character array of size 11 containing the user's password
@param: double contactNumber - a double precision floating point number representing the user's contact number
@param: char email[MAX_EMAIL] - a character array of size 31 containing the user's email address.
*/
struct User {
    int userID;
    char name[MAX_NAME];
    char password[MAX_PASSWORD];
    double contactNumber;
	char email[MAX_EMAIL];
};

/*
Description: This structure is for the Item
@param: int productID - an integer representing the ID of the product/item
@param: int sellerID - an integer representing the ID of the user who is selling the item
@param: char itemName - a character array of size 21 containing the name of the item
@param: char category - a character array of size 16 containing the category of the item
@param: char description - a character array of size 31 containing a description of the item
@param: int quantity - an integer representing the number of items available for sale
@param: double unitPrice -  a double precision floating point number representing the price per unit of the item.
*/
struct Item {
    int productID;
    int sellerID; //userID
    char itemName[MAX_ITEM_NAME];
    char category[MAX_CATEGORY_NAME];
    char description[MAX_DESCRIPTION];
    int quantity;
	double unitPrice;
};

/*
Description: This structure is for the Transaction
@param: int year - an integer representing the year in which the transaction occurred
@param: int month - an integer representing the month in which the transaction occurred
@param: int day - an integer representing the day on which the transaction occurred
@param: int buyerID -  an integer representing the ID of the user who made the purchase (Buyer)
@param: int sellerID - an integer representing the ID of the user who sold the item(s) (seller)
@param: struct Item cart[MAX_TRANSACTION_ITEMS] - an array of MAX_TRANSACTION_ITEMS instances of the Item struct representing the items that were bought in the transaction.
@param: double amount -  a double precision floating point number representing the total amount of money exchanged in the transaction.
*/
struct Transaction{
	int year;
	int month;
	int day;
	int buyerID;
	int sellerID;
	struct Item cart[MAX_TRANSACTION_ITEMS];
	double amount;
};



// START OF USER REGISTRATION PART

/* checkUserID checks if the user ID is already taken.
@param: int userID - integer that inputs userID
@param: int nUsers - an integer representing the number of users data in the system 
@param: struct User users[] - an array that represents the list of userIDs in data
@return 1 if userID already exists
@return 0 if userID does not exists yet 
*/
int checkUserID(struct User users[],int userID, int* nUsers)
{
	int i;
    for (i = 0; i < *nUsers; i++) 
	{
        if (users[i].userID == userID) 
		{
            return 1;  		// userID exists
        }
    }
    return 0; 			 // userID does not exist
}

/*
Description: registerUser creates a new user account
@param: int nUsers - an integer that represent the pointer var which refers to the number of users data in the system 
@param: struct User users[] - an array that represents the data of each users
@param: userID - a struct which a unique integer is input by the user 
*/
void registerUser(int* nUsers, struct User users[])
{
	int userID;
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char password[MAX_PASSWORD];
    double contactNumber;
    
    printf("Enter user ID: ");
    scanf("%d", &userID);
    
    if(checkUserID(users, userID, nUsers)==1) 	//Checks if userID exists
    {
    	printf("user ID already in use!\n");
	}
	else
	{
	    printf("Enter Name (maximum of 20 characters only): ");
	    scanf("%s", name);
			
	    printf("Enter Email Address (maximum of 30 characters only): ");
	    scanf("%s", email);
	    
	    printf("Enter Password (maximum of 10 characters only): ");
	    scanf("%s", password);
	    
	    printf("Enter Contact Number: ");
	    scanf("%lf", &contactNumber);
	    
	    // creates new user
	    struct User newUser;
	    newUser.userID = userID;
	    strcpy(newUser.name, name);
	    strcpy(newUser.email, email);
	    strcpy(newUser.password, password);
	    newUser.contactNumber = contactNumber;

		// adds new user to the array of users
	    users[*nUsers] = newUser;
	    (*nUsers)++;
	    
	//font color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    
	    printf("User registered successfully!\n");
	    
	    Sleep(1000);
			printf(" .");
			Sleep(1000);
			printf(" .\n");
	
			system("cls");
	}
}



/* 
Description: isLogValid - validates the user and password upon logging in (checks if the the input matches any saved data from the system)
@param: struct User users[] - an array for the user data
@param: int userID - a struct which a unique integer is input by the user 
@param: char *password - character array of size 11 containing the user's password || takes input for the password
@param: int *nUsers - an integer that represents the number of users data in the system 
@return 1 - returns if the input is a valid data (correct userID and password)
@return 0 - returns if the input is invalid data (incorrect userID or password || does not any of the data in the system)
*/
int isLogValid(struct User users[],int *userID, char *password, int* nUsers)
{
	int i;
	
    for (i = 0; i < *nUsers; i++)
	{
        if (users[i].userID == *userID && strcmp(users[i].password, password) == 0)
		{
            return 1;  // valid 
        }
    }
    return 0;  // invalid 
}

/* 
Description: userLogIn function displays if the input userID and password matches a registered user in the system.
@param: struct User users[] - a struct array of user details
@param: int  *nUsers - an integer that represents the number of users in the system
@return 1 - returns if the userLogIn info is valid
@return 0 - returns if the  userLogIn info is invalid
*/
int userLogIn(int* nUsers, int* userID, struct User users[])
{
	char password[MAX_PASSWORD];
	int memloc;
	
	//Login 
		printf("LOG IN\n");
		printf("Enter userID: ");
	    scanf("%d", userID);
	
	    printf("Enter Password: ");
	    scanf("%s", password);
		
	// validation
	    if (isLogValid(users, userID, password, nUsers)==1)
		{
	        printf("Log In Succssful!\n");
	        memloc=1;
	    } 
		else
		{
	        printf("Incorrect user name or password. Try again!\n");
	        memloc=0;
	    }
	    
	    return memloc;
}

/* 
Description: AdminLogin displays userLogIn screen for the admin || checks if input password is correct.
@return 1 - returns if the admin userLogIn is successful
@return 0 - returns if the admin userLogIn is unsuccessful
*/
int adminLog()
{
	int memloc;
	char password[MAX_PASSWORD];
	
	//Login Screen
		printf("ADMIN MENU\n");
	    printf("Enter Password: ");
	    scanf("%s", password);
		
	// validation
	    if (strcmp(password,"H3LLo?")==0)
		{
	        printf("Log In Successful!\n");
	        memloc=1;
	    } 
		else
		{
	        printf("Unauthorized access!\n");
	        memloc=0;
	    }
	return memloc;
}

// START OF SELLER MENU

/*
Description: checkProductID checks if the product ID already exists
@param: int productID - integer that represents the input  ID of the product 
@param: int *nItems - an integer that represents the number of items data in the system 
@param: struct Item items[] - struct array that represents the list of productIDs
@return 1 - returns if input already exists
@return 0 - return if input does not exist yet
*/
int checkProductID(struct Item items[], int productID, int* nItems)
{
	int i;
    for (i = 0; i < *nItems; i++)
	{
        if (items[i].productID==productID)
		{
            return 1; // productID exists
        }
    }
    return  0; // productID exists
}

/*
Description: addNewItem - adds a new item in the list of items
@param: struct Item items[] - struct array that represent the item data
@param: int* sellerID - an integer that represent the userID of the user
@param: int* nItems - an integer that represents the number of items in the system
*/
void addNewItem(struct Item items[], int* sellerID, int* nItems)
{
	int productID;
	char itemName[MAX_ITEM_NAME];
    char category[MAX_CATEGORY_NAME];
    double unitPrice;
    int quantity;
    char description[MAX_DESCRIPTION];

	int nSellerItems = 0;
    int i;
    
   // Seller item counter
    for (i = 0; i < *nItems; i++)
	{
        if (items[i].sellerID==*sellerID)
		{
            nSellerItems++;
        }
    }
    
    // Checks if seller has already reached the maximum number of items
    if (nSellerItems >= 20) {
        printf("You cannot add anymore products for sale! Reached limit!\n");
    }
    
    // Get information for new item
    
    printf("Enter product ID: ");
    scanf("%d", &productID);

	//checks if productID already exists.  true == back to sell menu.
	if(checkProductID(items,productID,nItems)==1)
	    {
	    	printf("Product ID already exists.\n");
		}
	
	//ask for the item details
	else
	{
		printf("Enter item name: ");
	    scanf(" %[^\n]s", itemName);
	    
	    printf("Enter category (all uppercase characters only) : ");
	    scanf(" %[^\n]s", category);
	    
	    printf("Enter unit price: ");
	    scanf("%lf", &unitPrice);
	    
	    printf("Enter quantity: ");
	    scanf("%d", &quantity);
	    
	    printf("Enter description: ");
	    scanf(" %[^\n]s", description);
	
		// Creating of new item
	    struct Item newItem;
	    newItem.productID = productID;
	    newItem.sellerID = *sellerID;
	    strcpy(newItem.itemName, itemName);
	    strcpy(newItem.category, category);
	    newItem.unitPrice = unitPrice;
	    newItem.quantity = quantity;
	    strcpy(newItem.description, description);

		// Adds new item to array of items
	    items[*nItems] = newItem;
	    (*nItems)++;
	
	    printf("ITEM HAS BEEN ADDED SUCCESFULLY!\n");
	}

}

/* 
Description: editStock - edits stock
@param: int* items[] - integer that represents array of item details
@param: nItems - number of items in the system
@param: sellerID - userID of current program user editing his/her stock
*/
void editStock(struct Item items[], int* sellerID, int* nItems)
{
	int i;
	int productID;

	// Shows list of seller's products
	printf("%-11s| %-20s | %-15s | %-10s | %-8s | %-30s\n", "Product ID", "Item Name" , "Category" , "Unit Price", "Quantity", "Description");
	for (i = 0; i < *nItems; i++)
	{
		if (items[i].sellerID == *sellerID) 
		{
			printf("%-11d| %-20s | %-15s | %-10.2f | %-8d | %-30s \n", items[i].productID, items[i].itemName, items[i].category, items[i].unitPrice, items[i].quantity,items[i].description);
		}
	}
	// Get product ID for editing
	printf("Enter product ID to edit: ");
	scanf("%d", &productID);
	
	// Search for productID in system
	int index = -1;
	for (i = 0; i < *nItems; i++)
	{
	    if ((items[i].productID==productID) && (items[i].sellerID==*sellerID))
		{
	        index = i;
	    }
	}
	
	// If productID is invalid, returns to sell menu
	if (index == -1)
	{
	    printf("Invalid product ID.\n");
	}
	
		// submenu
		int option1 = 0;
		while (option1 != 6 && index > -1)
		{
		    printf("\nPick what to edit:\n");
		    printf("[1] Replenish\n");
		    printf("[2] Change Price\n");
		    printf("[3] Change Item Name\n");
		    printf("[4] Change Category\n");
		    printf("[5] Change Description\n");
		    printf("[6] Finish Editing\n");
		    printf("Enter choice: ");
		    scanf("%d", &option1);
		

		    switch (option1)
			{
		        case 1: {
		            int replenish;
		            printf("Input quantity that to be added to the stock this item: ");
		            scanf("%d", &replenish);
		            items[index].quantity += replenish;
		            printf("Stock successfully updated.\n");
		            break;
		        }
		        case 2: {
		            float newPrice;
		            printf("Enter new unit price: ");
		            scanf("%f", &newPrice);
		            items[index].unitPrice = newPrice;
		            printf("Price successfully changed.\n");
		            break;
		        }
		        case 3: {
		            printf("Enter new item name: ");
		            char newName[MAX_ITEM_NAME];
		            scanf("%s", newName);
		            strcpy(items[index].itemName, newName);
		            printf("Item name successfully changed.\n");
		            break;
		        }
		        case 4: {
		            printf("Enter new category (all uppercase characters only):  ");
		            char newCategory[MAX_CATEGORY_NAME];
		            scanf("%s", newCategory);
		            strcpy(items[index].category, newCategory);
		            printf("Category successfully changed.\n");
		            break;
		        }
		        case 5: {
		            printf("Enter new description: ");
		            char newDescription[MAX_DESCRIPTION];
		            scanf("%[^\n]s", newDescription);
		            strcpy(items[index].description, newDescription);
		            printf("Description successfully changed.\n");
		            break;
		        }
		        case 6:
		            printf("Returning to Sell Menu. PLease wait...\n");
		            break;
		        default:
		            printf("Error: Invalid option.\n");
		            break;
		    }
		}

}

/*
Description :ShowMyProducts - sorts items by productID in ascending order
@param items[] 
@param nItems 
@param sellerID 
*/
void ShowMyProducts(struct Item items[], int *sellerID, int* nItems) //seller 
{
	int i,j;
	struct Item tempItem[MAX_SELLER_ITEM];
	int SellerItems=0;
	struct Item ctr[MAX_SELLER_ITEM];
	
	// seller item ctr
	for(i=0;i<*nItems;i++)
	{
		if(items[i].sellerID==*sellerID)
		{
			tempItem[SellerItems]=items[i];		// Copy the items[] to tempItem[]
			SellerItems+=1;
		}
	}
	
	// Sorts the temporary array
	if(SellerItems > 1) {
	    for (i = 0; i < SellerItems - 1; i++) 
		{
	        for (j = i + 1; j < SellerItems; j++) 
			{
	            if (tempItem[i].productID > tempItem[j].productID) 
				{
	                ctr[1] = tempItem[i];
	                tempItem[i] = tempItem[j];
	                tempItem[j] = ctr[1];
	            }
	        }
		}
	}
	
    // Table format for seller's product
	printf("%-11s| %-20s | %-15s | %-10s | %-8s \n", "Product ID", "Item Name" , "Category" , "Unit Price", "Quantity");
    for (i = 0; i < SellerItems; i++) 
	{
			printf("%-11d| %-20s | %-15s | %-10.2f | %-8d \n", tempItem[i].productID, tempItem[i].itemName, tempItem[i].category, tempItem[i].unitPrice, tempItem[i].quantity);
    }
    
    printf("\n\n");
}


/*
Description: ShowMyLowStockProducts displays items of sellerID with quantity below 5.
@param: items[]
@param: nItems
@param: sellerID
*/
void ShowMyLowStockProducts(struct Item items[], int *sellerID, int* nItems)
{
	int showProduct=0;
	int i;

	//check if seller has items with quantity below 5
	for(i=0; i< *nItems; i++)
	{
		//seller items qty < 5
		if((items[i].sellerID == *sellerID) && (items[i].quantity < 5)) {
		// Display all the item details per item
			do{	
			printf("Product ID: %d\n", items[i].productID);
            printf("Item Name: %s\n", items[i].itemName);
            printf("Category: %s\n", items[i].category);
            printf("Unit Price: %.2f\n", items[i].unitPrice);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Description: %s \n\n", items[i].description);
            showProduct++;
		
			// Ask user to press N to show  next and X to exit
			if(showProduct % 1 ==0)
			{
				printf("           [N] Show Next Product    |     [X] Exit Viewing  \n");
				char option;
				scanf(" %c", &option);
				
				system("cls");
				
				switch(option)
				{
					case 'N':
					case 'n':
						break;
						
					case 'X':
					case 'x':
						return;	// Returns to Seller Menu
						
					default: printf("Invalid option! Try again.\n");
					break;
				}
				showProduct--;

			}
			
			// empty 
			else if (showProduct==0){
				printf("No more products to show.\n");
			}

			}
			while(showProduct!=0); 
		}
	}
	
	// seller item has not qty below 5
	if(showProduct == 0)
		printf("No Low Stock Products.\n");
}


//START OF BUYER MENU

/* 
Description: ViewALLProduct sorts sellerID in ascending order
@param: items[]
@param: users[]
@param: nItems
@param: nUsers
*/
void ViewAllProducts(struct Item items[], struct User users[], int* nItems, int* nUsers)
{
    int i, j;
    struct User ctr[MAX_USERS];
    int sellerItemsAvail;
    struct Item selleritems[MAX_SELLER_ITEM];
    int sellerItemCount;

    // sorts sellerID
		struct User tempUsers[MAX_USERS];
		for (i = 0; i < *nUsers; i++)
		{
		    tempUsers[i] = users[i];
		}
		for (i = 0; i < *nUsers - 1; i++)
		{
		    int min = i;
		    for (j = i+1; j < *nUsers; j++)
		    {
		        if (tempUsers[min].userID > tempUsers[j].userID)
		        {
		            min = j;
		        }
		    }
		    if (min != i)    
		    {
		        ctr[1] = tempUsers[i];
		        tempUsers[i] = tempUsers[min];
		        tempUsers[min] = ctr[1];
		    }
		}
		
		// Display all products by sp seller
		for (i = 0; i < *nUsers; i++)
		{
		
		    sellerItemsAvail = 0;
		    sellerItemCount = 0;
		
		    // find all items  by sp seller
		    for (j = 0; j < *nItems; j++)
		    {
		        if (items[j].sellerID == tempUsers[i].userID)
		        {
		            sellerItemsAvail = 1;
		            selleritems[sellerItemCount] = items[j];
		            sellerItemCount++;
		        }
		    }
		
		    // display all items by sp seller
		    if (sellerItemsAvail==1)
		    {
		        printf("Seller ID: %d\n", tempUsers[i].userID);
		        printf("%-11s| %-20s | %-15s | %-10s | %-8s \n", "Product ID", "Item Name" , "Category" , "Unit Price", "Quantity");
		
		        for (j = 0; j < sellerItemCount; j++)
		        {
		            printf("%-11d| %-20s | %-15s | %-10.2f | %-8d \n", selleritems[j].productID, selleritems[j].itemName, selleritems[j].category, selleritems[j].unitPrice, selleritems[j].quantity);
		        }
		
		        printf("\n");
		
		        char option;                
		        if(j==sellerItemCount)
		        {
		            printf("Press [N] to show Next or [X] to Exit Viewing: ");
		            scanf(" %c", &option);
		            
		            system("cls");
		            
		            // Next
		            switch(option)
		            {
		                case 'N':
		                case 'n':
		                    break;
		                case 'x':
		                case 'X':
		                    return; 	//exits
		                default:
		                    printf("Invalid input. Please try again.\n");
		                    break;
		            }
		        }
		    }
		}
}


/* 
description: ShowAllProductsSpSeller displays all products
@param items[]
@param users[]
@param nItems
@param nUsers
*/
void ShowAllProductsSpSeller(struct Item items[], struct User users[], int* nItems, int* nUsers)
{
	int ID;
	printf("Enter Seller's ID:\n");
	scanf("%d", &ID);
	
	int i;
// searches seller's products and creates a new temporary array
    struct Item tempItem[MAX_SELLER_ITEM];
    struct Item ctr[MAX_SELLER_ITEM];
    int SellerItems = 0;
    for (i = 0; i <  *nItems; i++)
	{
        if (items[i].sellerID==ID)
		{
            tempItem[SellerItems] = items[i];
            SellerItems++;
        }
    }
    
    int j;
    // Sorts the temporary array by productID
    for (i = 0; i < SellerItems - 1; i++)
	{
        for (j = i + 1; j < SellerItems; j++)
		{
            if (tempItem[i].productID > tempItem[j].productID)
			{
                ctr[1] = tempItem[i];
                tempItem[i] = tempItem[j];
                tempItem[j] = ctr[1];
            }
        }
    }
    
    // shows sellers products
    printf("\nSeller ID: %d\n", ID);
	printf("%-11s| %-20s | %-15s | %-10s | %-8s \n", "Product ID", "Item Name" , "Category" , "Unit Price", "Quantity");
	for(i=0; i < SellerItems; i++)
	{
		printf("%-11d| %-20s | %-15s | %-10.2f | %-8d \n", tempItem[i].productID, tempItem[i].itemName, tempItem[i].category, tempItem[i].unitPrice, tempItem[i].quantity);
	}
	printf("\n");
}

/*
Description: ShowAllProductByCategory displays all products of input category.
@param items[]
@param users[]
@param nItems
@param nUsers
*/
void ShowAllProductsByCategory(struct Item items[], struct User users[], int* nItems, int* nUsers)
{
	char category[MAX_CATEGORY_NAME];
	printf("Enter Category (Use all uppercase charcters):\n");
	scanf("%s", category);
	
	int i;
  	int showProduct=0;
	
	for(i=0; i< *nItems; i++)
	{
		if(strcmp(items[i].category, category)==0)
		{
			do{
			printf("Product ID: %d\n", items[i].productID);
            printf("Item Name: %s\n", items[i].itemName);
            printf("Category: %s\n", items[i].category);
            printf("Unit Price: %.2f\n", items[i].unitPrice);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Description: %s \n\n", items[i].description);
            showProduct++;
		
			if(showProduct % 1 == 0)
			{
				printf("           [N] Show Next Product    |     [X] Exit Viewing  \n");
				char option;
				scanf(" %c", &option);
				
				system("cls");
				
				switch(option)
				{
					case 'N':
					case 'n':
						break;
						
					case 'X':
					case 'x':
						return;
						
					default: printf("Invalid option! Try again.\n");
					break;
				}showProduct--;

			}
			else if (showProduct==0)
			{
			printf("No Item under that Category.\n");
			}

		}while(showProduct!=0); 
	}
 }
}

/*
Description: ShowAllProductsByName displays all products of input name (codeWord).
@param: items[] 
@param: users[]
@param: nItems
@param: nUsers
*/
void ShowAllProductsByName(struct Item items[], struct User users[], int* nItems, int* nUsers)
{
	char codeWord[MAX_ITEM_NAME];
	printf("Enter Code Word:\n");
	scanf("%s", codeWord);
	
	int i;
  	int showProduct=0;
	
	for(i=0; i< *nItems; i++)
	{
		if(strstr(items[i].itemName, codeWord))
		{
			do{
			printf("Product ID: %d\n", items[i].productID);
            printf("Item Name: %s\n", items[i].itemName);
            printf("Category: %s\n", items[i].category);
            printf("Unit Price: %.2f\n", items[i].unitPrice);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Description: %s\n\n", items[i].description);
            showProduct++;
		
			if(showProduct % 1 ==0)
			{
				printf("           [N] Show Next Product    |     [X] Exit Viewing  \n");
				char option;
				scanf(" %c", &option);
				
				system("cls");
				
				switch(option)
				{
					case 'N':
					case 'n':
						break;
						
					case 'X':
					case 'x':
						return;
						
					default: printf("Invalid option! Try again.\n");
					break;
				}showProduct--;

			}
			else if (showProduct==0)
			{
			printf("No item under that name.\n");
			}

		}while(showProduct!=0); 
	}
 }
}

/* 
Description: AddToCart - asks buyer if they want to add an item to the cart. Asks for productID
*/
void AddToCart(struct Item items[], struct Item cart[], int* nItems, int* sellerID, int* cartItems)
{
    int productID;
    int quantity;
    char option;
    int i;

    do
    {
        printf("Add item to cart? (Y/N): ");	// Y for yes || N for no
        scanf(" %c", &option);

        if (option == 'Y' || option == 'y')
        {
            if (*cartItems < MAX_CART_ITEMS)
            {
                printf("\nEnter the product ID to add to cart: ");
                scanf("%d", &productID);

                // Search for productID
                int index = -1;
                for (i = 0; i < *nItems; i++)
                {
                    if (items[i].productID == productID)
                    {
                        index = i;
                        i=*nItems;
                    }
                }

                // product ID invalid
                if (index == -1)
                {
                    printf("Error: Product ID Not Found!\n");
                }
                else if (items[index].sellerID != *sellerID)
                {
                    printf("Add %s to cart?\n", items[index].itemName);
                    printf("Input the quantity to buy: ");
                    scanf("%d", &quantity);

                    if (quantity <= 0)
                    {
                        printf("Error: Invalid quantity!\n");
                    }
                    else if (quantity <= items[index].quantity)
                    {
                        cart[*cartItems] = items[index];
                        cart[*cartItems].quantity = quantity;
                        (*cartItems)++;
                        printf("\nITEM ADDED SUCCESSFULLY.\n");
                    }
                    else
                    {
                        printf("Not enough stock available.\n");
                    }
                }
                else
                {
                    printf("Error: You cannot buy your own products!\n");
                }
            }
            else
            {
                printf("Your cart is FULL. Please proceed to Edit Cart or Check Out.\n");
            }
        }
    } while (option == 'y' || option == 'Y');
}

/*
description: EditCart allows editing of cart given the following choices: Remove all items from seller, remove specific item, and editing of quantity in cart.

*/
void EditCart(struct Item cart[], int* cartItems, int* sellerID)
{
    int i;
    // Display the items in cart
    printf("MY CART:\n");
    printf("%-11s| %-10s | %-20s | %-15s | %-10s | %-8s \n", "Product ID", "Seller ID", "Item Name", "Category", "Unit Price", "Quantity");
    for (i = 0; i < *cartItems; i++)
    {
        printf("%-11d| %-10d | %-20s | %-15s | %-10.2f | %-8d \n", cart[i].productID, cart[i].sellerID, cart[i].itemName, cart[i].category, cart[i].unitPrice, cart[i].quantity);
    }
    
    // submenu
	int option = 0;
	while (option != 4)
	{
    printf("\nWhat would you like to do?\n");
    printf("[1] Remove All Items From Seller\n");
    printf("[2] Remove Specific Item\n");
    printf("[3] Edit Quantity\n");
    printf("[4] Finish Editing\n");
    printf("Enter choice: ");
    scanf("%d", &option);
    

    switch (option)
    {
        case 1:
        {
            int ID;
            struct Item tempcart[MAX_CART_ITEMS];
            printf("Enter the Seller ID of products you wish to remove:");
            scanf("%d", &ID);
            
            int count = 0;
            for(i=0; i < *cartItems; i++)
            {
                if(cart[i].sellerID!=ID)
                {
                    tempcart[count]=cart[i]; //create a new cart array without products from the input seller ID
                    count++;
                }
            }
            *cartItems = count;
            
            for(i=0;i<count;i++)
            {
                cart[i] = tempcart[i];

            }
            printf("Items from seller successfully removed.\n");
            break;
        }
        case 2:
        {
            int index, i;
            int ID;
            index=-1;
            printf("Enter the Product ID of product you wish to remove:");
            scanf("%d", &ID);
            
            for(i=0;i<*cartItems;i++)
            {
                if(cart[i].productID==ID)
                {
                    index=i;
                }
            }
            // Remove product from cart
            if (index >= 0)
            {
                for (i = index; i < *cartItems - 1; i++)
                {
                    cart[i] = cart[i+1];
                }
                (*cartItems)--;
                printf("Item has been successfully removed.\n");
            }
            else
            {
                printf("Error: Product not found in cart!");
            }
            break;
        }
		case 3:
		{
		    int ID;
		    int quantity;
		    int i;
		    
		    printf("Enter the  Product ID of product you want to edit quantity:");
		    scanf("%d", &ID);
		    
		    int index = -1;
		    for (i = 0; i < *cartItems; i++)
		    {
		        if (cart[i].productID==ID)
		        {
		            index = i;
		        }
		    }
		    
		    printf("Enter new quantity:");
		    scanf("%d", &quantity);
		    if(quantity <= cart[index].quantity)
		    {
		        cart[index].quantity=quantity;
		        printf("Quantity successfully changed.\n");
		    }else
		    {
		        printf("Not enough stock available.\n");
		    }
		    break;
		}
	case 4:
		{
		printf("Returning to Buy Menu. Please wait...\n"); break;
		}
	default:
		printf("Error: Invalid option.\n");
		break;
	}	
	}
}



void validateCart(int*cartItems, struct Item cart[],struct Item items[],int* nItems)
{
	int i,j;
	for(i=0; i< *cartItems; i++)
	{
		int cartProductID = cart[i].productID;
    	int cartSellerID = cart[i].sellerID;
    	for(j=0; j< *nItems;j++)
    	{
    		if(items[j].productID == cartProductID && items[j].sellerID == cartSellerID)
    		{
    			if(cart[i].quantity > items[j].quantity || cart[i].unitPrice != items[j].unitPrice) 
    			{
    				printf("ITEM %d from SELLER %d has been changed:\n", cartProductID, cartSellerID);
			        printf("Old quantity: %d\n", cart[i].quantity);
			        printf("New quantity: %d\n", items[j].quantity);
			        printf("Old price: %f\n", cart[i].unitPrice);
			        printf("New price: %f\n", items[j].unitPrice);
			        printf("You can still go to back to Edit your Cart.\n");
			        cart[i].quantity = items[j].quantity;
			        cart[i].unitPrice = items[j].unitPrice;
				}
				else
					printf("No changes in item %s in your cart. Proceeding to checkout.....\n", cart[i].itemName);
			}
		}
	}
	
	if(*cartItems<=0)
	{
		printf("No Items in Cart, Exit Check Out!\n");
	}
}

/*
Description: checkOutMenu -  asks buyer if they want to check out given
*/
void checkOutMenu(struct Transaction trans[], struct Item items[], struct Item cart[], int* userID, int* cartItems, int* nItems, int* nTrans, int* cartTrans)
{    

	validateCart(cartItems, cart,items,nItems);
	int option;
    printf("\nCHECK OUT MENU:\n");
    printf("[1] All\n");
    printf("[2] By a Specific Seller\n");
    printf("[3] Specific item\n");
    printf("[4] Exit Check Out\n");
    printf("Enter your choice: ");
    scanf("%d", &option);


	system("cls");
	
    switch (option) {
        case 1:
			{
			    int j, k;
				float transactionTotalAmount = 0; 
				
				do {
				    printf("Enter the date (MM/DD/YYYY): ");
				    scanf("%2d/%2d/%4d", &trans[*nTrans].month, &trans[*nTrans].day, &trans[*nTrans].year);
				    printf("\n\n\n                                 CHECKOUT                                 \n");
				    printf("+------+------------+----------------------+------------+----------------+\n");
				    
				    int currentSellerID = -1;
				    transactionTotalAmount = 0;
				    
				    for (j = 0; j < *cartItems; j++)
				    {
				        int sellerID = cart[j].sellerID;
				        if (sellerID != currentSellerID)
				        {
				            printf("Transaction with seller %d:\n", sellerID);
				            printf("%-10s %-10s %-30s %-10s %-10s\n", "Quantity", "ProductID", "Item Name", "Unit Price", "Total Price\n");
				            currentSellerID = sellerID;
				            transactionTotalAmount = 0;
				        }
				        
				        int quantity = cart[j].quantity;
				        int productID = cart[j].productID;
				        float unitPrice = cart[j].unitPrice;
				        float total = quantity * unitPrice;
				        printf("%-10d %-10d %-30s %-10.2f %-10.2f\n", quantity, productID, cart[j].itemName, unitPrice, total);
				        transactionTotalAmount += total;
				        
				        for (k = 0; k < *nItems; k++)
				        {
				            if (items[k].productID == productID)
				            {
				                items[k].quantity -= quantity;
				            }
				        }
				        
				        trans[*nTrans].buyerID = *userID;
				        trans[*nTrans].sellerID = sellerID;
				        trans[*nTrans].cart[*cartTrans] = cart[j];
				        (*cartTrans)++;
				        
				        if (j == *cartItems - 1 || cart[j+1].sellerID != sellerID)
				        {
				            printf("\n\n\n\n\n+------+------------+----------------------+------------+----------------+\n");
				            printf("Total Amount Due: %f (payable to seller %d)\n\n\n\n", transactionTotalAmount, sellerID);
				            
				            trans[*nTrans].amount = transactionTotalAmount;
				            (*nTrans)++;
				        }
				    }
				    
				    // empty cart
				    *cartItems = 0;
				    
				} while (*cartItems!=0);
			}break;
		case 2:
				{
				    int i, k;
				    int ID;
				    
				    printf("Enter the date (MM/DD/YYYY): ");
				    scanf("%2d/%2d/%4d", &trans[*nTrans].month, &trans[*nTrans].day, &trans[*nTrans].year);
				    
				    printf("\nEnter the Seller ID of you want to purchase from: ");
				    scanf("%d", &ID);
			
				    printf("\n\n                                 CHECKOUT                                 \n");
				    printf("+------+------------+----------------------+------------+----------------+\n");
				    printf("Transaction with seller %d:\n", ID);
				    printf("%-10s %-10s %-30s %-10s %-10s\n", "Quantity", "ProductID", "Item Name", "Unit Price", "Total Price\n");
			
				    int sellerIndex = -1;
				    float transactionTotalAmount = 0;
			
				    for (i = 0; i < *cartItems; i++)
				    {
				        if (cart[i].sellerID == ID)
				        {
				            sellerIndex = i;
			
				            int quantity = cart[i].quantity;
				            int productID = cart[i].productID;
				            float unitPrice = cart[i].unitPrice;
				            float total = quantity * unitPrice;
				            printf("%-10d %-10d %-30s %-10.2f %-10.2f\n", quantity, productID, cart[i].itemName, unitPrice, total);
				            transactionTotalAmount += total;
			
				            for (k = 0; k < *nItems; k++)
				            {
				                if (items[k].sellerID == ID)
				                {
				                    items[k].quantity -= quantity;
				                }
				            }
			
				            trans[*nTrans].buyerID = *userID;
				            trans[*nTrans].sellerID = ID;
				            trans[*nTrans].cart[*cartTrans] = cart[i];
			
				            // remove item from cart
				            for (k = i; k < *cartItems - 1; k++)
				            {
				                cart[k] = cart[k + 1];
				            }
				            (*cartItems)--;
				            i--;
				            (*cartTrans)++;
				        }
				    }
			
				    if (sellerIndex == -1)
				    {
				        printf("You have not added any items from seller %d to your cart.\n", ID);
				    }
				    else
				    {
				        printf("\n\n\n\n\n+------+------------+----------------------+------------+----------------+\n");
				        printf("Total Amount Due: %f (payable to seller %d)\n\n\n\n", transactionTotalAmount, ID);
				    }
				    printf("\n\n\nSUCCESSFUL PURCHASE!\n");
				    (*nTrans)++;
				}
			    break;
        case 3:
				{
				    int i,j,k;
				    char name[MAX_ITEM_NAME];
				
					printf("Enter the date (MM/DD/YYYY): ");
				    scanf("%2d/%2d/%4d", &trans[*nTrans].month, &trans[*nTrans].day, &trans[*nTrans].year);
				    
				    printf("\nEnter Item Name of product you want to purchase:");
				    scanf(" %[^\n]", name); 
				    
				    int index = -1;
				    for (i = 0; i < *cartItems; i++)
				    {
				        if (strcmp(cart[i].itemName,name)==0)
				        {
				            index = i;
				        }
				    }
				    
				    if (index == -1) // check if item is not found
				    {
				        printf("Item not found in your cart.\n");
				        return; // exit the case
				    }
				    
				    printf("\n\n                                      CHECKOUT                                           \n");
				    printf("+-----------------+-----------------+----------------------+------------+----------------+\n");
				    printf("Transaction with seller %d:\n", cart[index].sellerID);
				    printf("%-10s %-10s %-30s %-10s %-10s\n", "Quantity", "ProductID", "Item Name", "Unit Price", "Total Price");
				    int quantity=cart[index].quantity;
				    int productID=cart[index].productID;
				    float unitPrice=cart[index].unitPrice;
				    float total=quantity*unitPrice;
				    printf("%-10d %-10d %-30s %-10f %-10f\n", quantity, productID, cart[index].itemName, unitPrice, total);
				    printf("\n\n\n\n\n+-----------------+-----------------+----------------------+------------+----------------+\n");
				    printf("Total Amount Due: %f (payable to seller %d)\n\n\n\n", total, cart[index].sellerID);
				    printf("\n\n\nSUCCESSFUL PURCHASE!\n");
				    
				    trans[*nTrans].amount = total;
				    trans[*nTrans].buyerID = *userID;
				    trans[*nTrans].sellerID = cart[index].sellerID;
				    trans[*nTrans].cart[*cartTrans] = cart[index];
				    (*cartTrans)++;
				    (*nTrans)++;
				
				    
				    for(j=0;j<*nItems;j++)
				    {
				        if (items[j].productID == productID && items[j].sellerID == cart[index].sellerID) 
				        {
				            items[j].quantity -= quantity;
				        }
				    }
				    
				    for (k = index; k < *cartItems - 1; k++)
				    {
				        cart[k] = cart[k + 1];
				        (*cartItems)--;
				    }
				}
				break;

        case 4:
        	break;
        default:
            printf("Invalid option.\n"); break;
    }
}


//ADMIN


void showAllUsers(struct User users[], int* nUsers)
{
    int i, j;
    struct User temp;
    for (i = 0; i < *nUsers-1; i++) {
        for (j = 0; j < *nUsers-i-1; j++)
		{
            if (users[j].userID > users[j+1].userID)
			{
                temp = users[j];
                users[j] = users[j+1];
                users[j+1] = temp;
            }
        }
    }

    printf("%-10s%-12s%-20s%-30s%-15s\n", "USERID", "PASSWORD", "NAME", "EMAIL ADDRESS", "PHONE NUMBER");
    for (i = 0; i < *nUsers; i++)
	{
        printf("%-10d%-12s%-20s%-30s%-15lf\n", users[i].userID, users[i].password, users[i].name, users[i].email, users[i].contactNumber);
	}
}


void showAllSellers(struct User users[], int* nUsers, struct Item items[], int *nItems)
{
	int i,j;
    printf("%-10s%-20s%-30s%-20s%-20s\n", "USERID", "NAME", "EMAIL ADDRESS", "PHONE NUMBER", "ITEMS");

    for (i = 0; i < *nUsers; i++)
	{
        int nSellerItems = 0; 

        for (j = 0; j < *nItems; j++)
		{
            if (items[j].sellerID == users[i].userID)
			{
                nSellerItems++;
            }
        }

        if (nSellerItems > 0) {
            printf("%-10d%-20s%-30s%-20lf%-20d\n", users[i].userID, users[i].name, users[i].email, users[i].contactNumber, nSellerItems);
        }
    }
}


int checkDate(struct Transaction trans[], int* nTrans, int startMonth, int startDay, int startYear, int endMonth, int endDay, int endYear)
{
	int i;
	int nFound=0;

	for(i = 0; i < *nTrans; i++)
	{
		if (trans[i].year < startYear || trans[i].year > endYear)
		{
			nFound=0;
		}
		else if (trans[i].year == startYear && trans[i].month < startMonth)
		{
			nFound=0;
		}
		else if (trans[i].year == startYear && trans[i].month == startMonth && trans[i].day < startDay)
		{
			nFound=0;
		}
		else if (trans[i].year == endYear && trans[i].month > endMonth)
		{
			nFound=0;
		}
		else if (trans[i].year == endYear && trans[i].month == endMonth && trans[i].day > endDay)
		{
			nFound=0;
		}
		else
		{
			nFound=1;
		}
	}
	return nFound;
}


void ShowTotalSalesinGivenDuration(struct Transaction trans[], int* nTrans)
{
	float totalSales = 0;
	int i;
	
	int startMonth, endMonth, startDay, endDay, startYear, endYear;

	printf("Enter Start Date (MM/DD/YY):");
	scanf("%2d/%2d/%4d",&startMonth,&startDay,&startYear);
	
	printf("\nEnter End Date (MM/DD/YYYY):");
	scanf("%2d/%2d/%4d",&endMonth,&endDay,&endYear);
	
	for(i=0;i<*nTrans;i++)
	{
		if(checkDate(trans, nTrans, startMonth, startDay, startYear, endMonth,endDay, endYear)==1)
		{
			totalSales += trans[i].amount;
		}
	}

	printf("\nThe Total Sales from %2d/%2d/%4d to %2d/%2d/%4d is %f\n", startMonth,startDay,startYear,endMonth,endDay,endYear,totalSales);

}


void showSellerSales(struct Transaction trans[], struct User users[], int* nTrans, int* nUsers)
{
    int i, j;
    int sellerID;
	int startMonth, endMonth, startDay, endDay, startYear, endYear;
    char name[MAX_NAME];
    int specificSellerIDs[MAX_USERS] = {0}; 
    int nSpecificSellers = 0;

    printf("Enter Start Date (MM/DD/YY):");
    scanf("%2d/%2d/%4d",&startMonth,&startDay,&startYear);

    printf("\nEnter End Date (MM/DD/YYYY):");
    scanf("%2d/%2d/%4d",&endMonth,&endDay,&endYear);


    for(j = 0; j < *nTrans; j++)
    {
        if(checkDate(trans, nTrans, startMonth, startDay, startYear, endMonth,endDay, endYear)==1)
        {
            int found = 0;
            for(i = 0; i < nSpecificSellers; i++)
            {
                if(specificSellerIDs[i] == trans[j].sellerID)
                {
                    found = 1;
                }
            }
            if(!found)
            {
                specificSellerIDs[nSpecificSellers] = trans[j].sellerID;
                nSpecificSellers++;
            }
        }
    }

    printf("+-----------+----------------------+--------------+\n");
    printf("| Seller ID |     Seller Name      | Total Sales  |\n");
    printf("+-----------+----------------------+--------------+\n");

    for(i = 0; i < nSpecificSellers; i++)
    {
        sellerID = specificSellerIDs[i];
        float totalSellerSales = 0;
        for(j = 0; j < *nTrans; j++)
        {
            if(trans[j].sellerID == sellerID && checkDate(trans, nTrans, startMonth, startDay, startYear, endMonth,endDay, endYear)==1)
            {
                totalSellerSales += trans[j].amount;
            }
        }
        for(j = 0; j < *nUsers; j++)
        {
            if(users[j].userID == sellerID)
            {
                strcpy(name, users[j].name);
            }
        }
        printf("| %-9d | %-20s | %-12.2f |\n", sellerID, name, totalSellerSales);
    }

    printf("+-----------+----------------------+--------------+\n");
}


void showShopaholics(struct Transaction trans[], struct User users[], int* nTrans, int* nUsers)
{
    int i, j;
    int startMonth, endMonth, startDay, endDay, startYear, endYear;
    int specificBuyerIDs[MAX_USERS] = {0}; 
    int nSpecificBuyers = 0;

    printf("Enter Start Date (MM/DD/YY):");
    scanf("%2d/%2d/%4d",&startMonth,&startDay,&startYear);

    printf("\nEnter End Date (MM/DD/YYYY):");
    scanf("%2d/%2d/%4d",&endMonth,&endDay,&endYear);

    for(j = 0; j < *nTrans; j++)
    {
        if(checkDate(trans, nTrans, startMonth, startDay, startYear, endMonth, endDay, endYear)==1)
        {
            int found = 0;
            for(i = 0; i < nSpecificBuyers; i++)
            {
                if(specificBuyerIDs[i] == trans[j].buyerID)
                {
                    found = 1;
                }
            }
            if(!found)
            {
                specificBuyerIDs[nSpecificBuyers] = trans[j].buyerID;
                nSpecificBuyers++;
            }
        }
    }

    printf("+----------+----------------------+--------------+\n");
    printf("| Buyer ID |      Buyer Name      | Total Amount |\n");
    printf("+----------+----------------------+--------------+\n");

    for(i = 0; i < nSpecificBuyers; i++)
    {
        int buyerID = specificBuyerIDs[i];
        float totalBuyerAmount = 0;
        for(j = 0; j < *nTrans; j++)
        {
            if(trans[j].buyerID == buyerID && checkDate(trans, nTrans, startMonth, startDay, startYear, endMonth, endDay, endYear)==1)
            {
                totalBuyerAmount += trans[j].amount;
            }
        }
        for(j = 0; j < *nUsers; j++)
        {
            if(users[j].userID == buyerID)
            {
                printf("| %-8d | %-20s | %-12.2f |\n", buyerID, users[j].name, totalBuyerAmount);
                break;
            }
        }
    }

    printf("+----------+----------------------+--------------+\n");
}

//////////////////////////////////////////////////////////////////
void saveUserData(struct User users[],int nUsers)
{
	FILE *fp;
	int i;
	
	fp = fopen("users.txt","wt");
		// When dealing with files, remember:
		// fopen(<fileName>,"type");
		// For text files, "type" can be:
		// "rt" = Read the text file. File must exist!
		// "wt" (NEW) = Write text file, except it will overwrite the file if it exists, create it if it doesn't exist
		
	if (fp != NULL) // File generated successfully!
	{
		
		fprintf (fp,"%d\n", nUsers);
		
		for (i = 0;i < nUsers;i++)
		{
			fprintf(fp, "\n");
			fprintf (fp,"%d\n",users[i].userID);
			fprintf (fp,"%s\n",users[i].name);
			fprintf (fp,"%s\n",users[i].email);
			fprintf (fp,"%s\n",users[i].password);
			fprintf (fp,"%lf\n",users[i].contactNumber);
		}
		
		fclose (fp); 
	}
	else // If you have no space in the disk to generate the file!
		printf ("No space in the disk to generate the file!\n");
}


void loadUserData(struct User users[],int* nUsers)
{
	FILE *fp;
	int i;
	string newline; // Temporary line
	
	fp = fopen("users.txt","rt"); // See above, in saveUserList
	
	if (fp != NULL) // users.txt exists
	{
		
		
		fgets(newline,sizeof(newline),fp);
		
		*nUsers = atoi(newline); 
		
		for (i = 0;i < *nUsers;i++)
		{
			// get space between each user
			fgets(newline,sizeof(newline),fp);
			
			// 1st line contains the user ID
			fgets(newline,sizeof(newline),fp);
			users[i].userID = atoi(newline); // userID is an integer
			
			// 2nd line contains the name
			fgets(newline,sizeof(newline),fp);
			// You'll need to remove the \n, because these are strings
			newline[strlen(newline)-1] = '\0';
			strcpy(users[i].name,newline);
			
			// 3rd line contains the email
			fgets(newline,sizeof(newline),fp);
			// You'll need to remove the \n, because these are strings
			newline[strlen(newline)-1] = '\0';
			strcpy(users[i].email,newline);
			
			// 4th line contains the password
			fgets(newline,sizeof(newline),fp);
			// You'll need to remove the \n, because these are strings
			newline[strlen(newline)-1] = '\0';
			strcpy(users[i].password,newline);
			
			//5th line contains number
			fgets(newline,sizeof(newline),fp);
			users[i].contactNumber = atof(newline); 
		}
	}
	else	
		*nUsers = 0;
}


void saveItemData(struct Item items[],int nItems)
{
	FILE *pf;
	int i;
	
	pf = fopen("items.txt","wt");
		
	if (pf != NULL) // File generated successfully!
	{
		//output the number of items
		fprintf (pf,"%d\n", nItems);
		
		//output the details of each item in the array
		for (i = 0;i < nItems;i++)
		{
			fprintf(pf, "\n");
			fprintf (pf,"%d ",items[i].productID);
			fprintf (pf,"%d\n",items[i].sellerID);
			fprintf (pf,"%s\n",items[i].itemName);
			fprintf (pf,"%s\n",items[i].category);
			fprintf (pf,"%s\n",items[i].description);
			fprintf (pf,"%d ",items[i].quantity);
			fprintf (pf,"%.2lf\n",items[i].unitPrice);
		}
		
		fclose (pf); 
	}
	else // If you have no space in the disk to generate the file!
		printf ("No space in the disk to generate the file!\n");
}


void loadItemData(struct Item items[],int* nItems)
{
	FILE *pf;
	int i;
	string newline; // string variable that stores the data from the file.
	
	pf = fopen("items.txt","rt"); 
	
	if (pf != NULL) // users.txt exists
	{	
		// get the number of items
		fgets(newline,sizeof(newline),pf);
		
		*nItems = atoi(newline); 
		
		for (i = 0;i < *nItems; i++)
		{
			// get space between each user
			fgets(newline,sizeof(newline),pf);
			
			// product ID
			fscanf(pf,"%s",newline);
			items[i].productID = atoi(newline); 

			// seller ID
			fgets(newline,sizeof(newline),pf);
			items[i].sellerID = atoi(newline); 

			// item name
			fgets(newline,sizeof(newline),pf);
			newline[strlen(newline)-1] = '\0';	
			strcpy(items[i].itemName,newline);

			// category
			fgets(newline,sizeof(newline),pf);
			newline[strlen(newline)-1] = '\0';
			strcpy(items[i].category,newline);

			// description
			fgets(newline, sizeof(newline), pf);
			newline[strlen(newline)-1] = '\0';
			strcpy(items[i].description, newline);

			// quantity
			fscanf(pf,"%s",newline);
			items[i].quantity = atoi(newline); 

			// unit price
			fgets(newline,sizeof(newline),pf);
			items[i].unitPrice = atof(newline); 
		}
		

	}
	else	
		*nItems = 0;
}


void saveCartData(struct Item cart[],int cartItems, int* sellerID)
{
	FILE *a;
	int i;
	char filename[20];
	itoa(*sellerID,filename,10);
	strcat(filename, ".txt");
	a = fopen(filename,"wt");
		
	if (a != NULL) // File generated successfully!
	{
		fprintf (a,"%d\n", cartItems);
		for (i = 0;i < cartItems;i++)
		{
			fprintf (a,"%d\n",cart[i].productID);
			fprintf (a,"%d\n",cart[i].sellerID);
			fprintf (a,"%s\n",cart[i].itemName);
			fprintf (a,"%s\n",cart[i].category);
			fprintf (a,"%s\n",cart[i].description);
			fprintf (a,"%lf\n",cart[i].unitPrice);
			fprintf (a,"%d\n",cart[i].quantity);

		}
		
		fclose (a); 
	}
	else 
		printf ("no space in the disk to generate the file!\n");
}

void loadCartData(struct Item cart[],int* cartItems, int*sellerID)
{
	FILE *b;
	int i;
	char filename[20];
	string newline; // Temporary line
	
	itoa(*sellerID, filename, 10); //converts ID to a string value
	strcat(filename, ".txt");
	b = fopen(filename,"rt");
	
	if (b != NULL) // userID.txt exists
	{
		fgets(newline,sizeof(newline),b);
		
		/* No need to remove the \n because atoi will eliminate that for us*/
		*cartItems = atoi(newline); // We obtained newline for nUsers in line #140
		
		for (i = 0;i < *cartItems; i++)
		{
			// 1st line contains the product ID
			fgets(newline,sizeof(newline),b);
			cart[i].productID = atoi(newline); // product is an integer
			
			// 2nd line contains the seller ID
			fgets(newline,sizeof(newline),b);
			cart[i].sellerID = atoi(newline); // sellerID is an integer
			
			// 3rd line contains the name
			fgets(newline,sizeof(newline),b);
			newline[strlen(newline)-1] = '\0';
			strcpy(cart[i].itemName,newline);

			// 4th line contains the category
			fgets(newline,sizeof(newline),b);
			newline[strlen(newline)-1] = '\0';
			strcpy(cart[i].category,newline);
			
			// 5th line contains the description
			fgets(newline,sizeof(newline),b);
			newline[strlen(newline)-1] = '\0';
			strcpy(cart[i].description,newline);
			
			//6th line contains unitPrice
			fgets(newline,sizeof(newline),b);
			cart[i].unitPrice = atof(newline); 
			
			//7th line contains quantity
			fgets(newline,sizeof(newline),b);
			cart[i].quantity = atoi(newline); 
		}
	}
	else	
		*cartItems = 0;
}


void saveTransactionData(struct Transaction trans[], int nTrans, int cartTrans)
{
	FILE* c;
	int i, j;

	c = fopen("Transactions.txt", "wt");

	if (c != NULL) // File generated successfully!
	{
		fprintf(c, "%d\n", nTrans);
		for (i = 0; i < nTrans; i++)
		{
			fprintf(c, "%02d/%02d/%4d\n", trans[i].month, trans[i].day, trans[i].year);
			fprintf(c, "%d\n", trans[i].buyerID);
			fprintf(c, "%d\n", trans[i].sellerID);
			fprintf(c, "%lf\n", trans[i].amount);
			fprintf(c, "%d\n", cartTrans);
			for (j = 0; j < cartTrans; j++) {
				fprintf(c, "%d\n", trans[i].cart[j].productID);
				fprintf(c, "%s\n", trans[i].cart[j].itemName);
				fprintf(c, "%s\n", trans[i].cart[j].category);
				fprintf(c, "%s\n", trans[i].cart[j].description);
				fprintf(c, "%lf\n", trans[i].cart[j].unitPrice);
				fprintf(c, "%d\n", trans[i].cart[j].quantity);
			}
		}

		fclose(c); // Do NOT forget to close the file always
	}
	else // If you have no space in the disk to generate the file!
		printf("no space in the disk to generate the file!\n");
}


void loadTransactionData(struct Transaction trans[], int* nTrans, int* sellerID, int* cartTrans)
{
    FILE* d;
    int i, j;

    d = fopen("Transactions.txt", "rt");

    if (d != NULL) // File opened successfully!
    {
		fscanf(d, "%d\n", nTrans);
		for (i = 0; i < *nTrans; i++)
		{
			fscanf(d, "%02d/%02d/%4d\n", &trans[i].month, &trans[i].day, &trans[i].year);
			fscanf(d, "%d\n", &trans[i].buyerID);
			fscanf(d, "%d\n", &trans[i].sellerID);
			fscanf(d, "%lf\n", &trans[i].amount);
			fscanf(d, "%d\n", cartTrans);
			for (j = 0; j < *cartTrans; j++) {
				fscanf(d, "%d\n", &trans[i].cart[j].productID);
				fscanf(d, "%s\n", trans[i].cart[j].itemName);
				fscanf(d, "%s\n", trans[i].cart[j].category);
				fscanf(d, "%[^\n]s\n", trans[i].cart[j].description);
				fscanf(d, "%lf\n", &trans[i].cart[j].unitPrice);
				fscanf(d, "%d\n", &trans[i].cart[j].quantity);
			}
		}
        fclose(d); // Do NOT forget to close the file always
    }
    else // If the file cannot be opened!
        *nTrans=0;
}



int main()
{	

	//Declaring Structured Arrays:
	struct User users[MAX_USERS];
	//Array of Users
	struct Item items[200]; //max users * max item per user
	//Array of Items
	struct Item cart[MAX_CART_ITEMS];
	//Array of Items in Cart
	struct Transaction trans[200];
	//Array of Transacations

	
	//Declaring Variables:
	int userID;
	//Number of Current Users in App
	int nUsers = 0;
	//Number of Current Items in App
	int nItems = 0;
	//Number of Current Items in Cart
	int cartItems = 0;
	//Number of Current Transactions
	int nTrans = 0;
	//Number of Current Cart Items in Transaction
	int cartTrans = 0;
	
	
	
	
	//Declaring Other Variables:
	int option, option2, option3, option4, option5;
	
	loadUserData(users,&nUsers);
	loadItemData(items,&nItems);
	loadCartData(cart,&cartItems, &userID);
	loadTransactionData(trans, &nTrans, &userID, &cartTrans);

	
	do
	{
		printf("\n\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
		printf("\t\t\t\t MOSCHINO");
		printf("\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
		printf("\t\t\t\t MAIN MENU:");
        printf("\n\t\tRegister as a User \t   [1]");
        printf("\n\t\tUser Menu \t\t   [2]");
        printf("\n\t\tAdmin Menu \t\t   [3]");
        printf("\n\t\tExit \t\t\t   [4]");
		printf("\n");
        printf("\n\t\tSelect an option:\t    ");
		scanf("%d", &option);	
		
		system("cls");
		
		switch(option){
			case 1:
				registerUser(&nUsers, users); break;
			
			case 2:
				if(userLogIn(&nUsers, &userID, users)==1)
				{
					do{
						printf("\n\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
						printf("\t\t\t\t MOSCHINO");
						printf("\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
						printf("\t\t\t\t USER MENU:");
						printf("\n");
						printf("                              SELL MENU            [1]                                  \n");
						printf("                              BUY MENU             [2]                                  \n");
						printf("                              BACK TO MAIN MENU    [3]                                  \n");
						printf("\n");
						printf("                               Select an Option:");
						scanf("%d", &option2);	
						
						system("cls");
						
						switch(option2){
							case 1:
								do{
									printf("\n\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
									printf("\t\t\t\t SELLER MENU");
									printf("\n\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
									printf("\n");
									printf("\n");
									printf(" [1] Add New Item\n");
									printf(" [2] Edit Stock\n");
									printf(" [3] Show My Products\n");
									printf(" [4] Show My Low Stock Products\n");
									printf(" [5] Exit Seller Menu\n");
									printf("\n");
									printf("Select an Option:");
									scanf("%d", &option3);
									
									system("cls");
									
									switch(option3){
										case 1:
											addNewItem(items,&userID,&nItems); saveItemData(items,nItems); break;//add new item func break;
										case 2:
											 editStock(items, &userID,&nItems); saveItemData(items,nItems); break; //edit stock func break;
										case 3:
											ShowMyProducts(items, &userID, &nItems); break;//show products func break;
										case 4:
											ShowMyLowStockProducts(items, &userID, &nItems); break;//show low products func break;
										case 5:
											break;
										default:
		           							printf("Error: Invalid choice.\n");
		            						break;
							saveItemData(items,nItems);
									}
							}while(option3!=5); break;
							
							case 2:
							loadCartData(cart,&cartItems,&userID);

								do{
									printf("                               o---o---o---o---o---o---o---o---o---o---o---o---o");
									printf("\n");
									printf("                                                   BUYER MENU                   ");
									printf("\n");
									printf("                               o---o---o---o---o---o---o---o---o---o---o---o---o");
									printf("\n");
									printf("\n");
									printf("                                    [1] View all Products\n");
									printf("                                    [2] Show all Products by a Specific Seller\n");
									printf("                                    [3] Search Products by Category\n");
									printf("                                    [4] Search Products by Name\n");
									printf("                                    [5] Add to Cart\n");
									printf("                                    [6] Edit Cart\n");
									printf("                                    [7] Check Out Menu\n");
									printf("                                    [8] Exit Buy Menu\n");
									printf("\n");
									printf("                                    Select an Option:");
									scanf("%d", &option4);
									
									system("cls");
									
									switch(option4){
										case 1:
											ViewAllProducts(items, users, &nItems, &nUsers); break;
										case 2:
											ShowAllProductsSpSeller(items, users, &nItems, &nUsers); break;
										case 3:
											ShowAllProductsByCategory(items, users, &nItems, &nUsers); break;
										case 4:
											ShowAllProductsByName(items, users, &nItems, &nUsers); break;// Search Products by Name break;
										case 5:
											AddToCart(items, cart, &nItems, &userID, &cartItems); saveCartData(cart,cartItems, &userID); break;// add to cart func break;
										case 6:
											EditCart(cart, &cartItems, &userID); saveCartData(cart,cartItems, &userID); break;//edit cart func break;
										case 7:
											loadCartData(cart,&cartItems, &userID);
											loadTransactionData(trans, &nTrans, &userID, &cartTrans);
											checkOutMenu(trans,items, cart, &userID, &cartItems, &nItems, &nTrans, &cartTrans);
											saveCartData(cart,cartItems, &userID);
											saveTransactionData(trans, nTrans, cartTrans);

											break;   //checkout func break;
										case 8:
											break;
										default:
								            printf("Error: Invalid choice.\n");
								            break;
									}
							}while(option4!=8); break;							
							case 3:
								break;
							}
				}while(option2!=3); 
				break;
				}break;
				
			
			case 3:
			{
				if(adminLog()==1)
				{
					do{
						loadUserData(users,&nUsers);
						loadItemData(items,&nItems);
						loadCartData(cart,&cartItems, &userID);
						loadTransactionData(trans,&nTrans, &userID, &cartTrans);
									printf("o---o---o---o---o---o---o---o---o---o---o---o---o");
									printf("\n");
									printf("                  ADMIN MENU                   ");
									printf("\n");
									printf("o---o---o---o---o---o---o---o---o---o---o---o---o");
									printf("\n");
									printf("\n");
									printf("           [1] Show All Users\n");
									printf("           [2] Show All Sellers\n");
									printf("           [3] Show Total Sales in Given Duration\n");
									printf("           [4] Show Sellers Sales\n");
									printf("           [5] Show Shopaholics\n");
									printf("           [6] Back to Main Menu\n");
									printf("\n");
									printf("Select an Option:");
									scanf("%d", &option5);
									
									system("cls");
									
									switch(option5){
										case 1:
											showAllUsers(users, &nUsers); break;
										case 2:
											showAllSellers(users, &nUsers, items, &nItems); break;//show all sellers func break;
										case 3:
											loadTransactionData(trans, &nTrans, &userID, &cartTrans);
											ShowTotalSalesinGivenDuration(trans, &nTrans); 
											break;//show total sales func break;
										case 4:
											loadTransactionData(trans, &nTrans, &userID, &cartTrans);
											showSellerSales(trans,users,&nTrans, &nUsers); 
											break;//show seller sales func break;
										case 5:
											loadTransactionData(trans, &nTrans, &userID, &cartTrans);
											showShopaholics(trans,users,&nTrans, &nUsers);
											break;//show shopaholics func break;
										case 6:
											break;
										default:
		           							printf("Error: Invalid choice.\n");
		            						break;
									}
							}while(option5!=6); break;
				}
			}
			break;
			
			case 4:
						printf("\n\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
						printf("\t\t\t\t MOSCHINO");
						printf("\n\t\to--o--o--o--o--o--o--o--o--o--o--o--o--o\n");
						printf("\n");
						printf("\t\t\t all rights reserved Moschino");
				break;
			default:
	                printf("Error: Invalid choice.\n");
	        }
	}while (option!=4);
	
	saveUserData(users ,nUsers);
	saveItemData(items,nItems);
	saveTransactionData(trans, nTrans, cartTrans);

	
	return 0;
}
