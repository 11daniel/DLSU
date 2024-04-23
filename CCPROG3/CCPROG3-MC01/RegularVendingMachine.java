import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class RegularVendingMachine
{
  private Map < Integer, Item > items;
  private Map < Integer, Integer > stock;
  private Map < Double, Integer > money;
  private double totalSales;
  private double initialSales;
  private double initialMoney;
  private double currentMoney;
  private boolean isMachineCreated;
/**
* creates RegularVendingMachine object
* <p>
* This constructor assigns variables and gives them their values.
*/
  public RegularVendingMachine ()
  {
	items = new HashMap <> ();
	stock = new HashMap <> ();
	money = new HashMap <> ();
	totalSales = 0;
	initialSales = 0;
	initialMoney = 0;
	currentMoney = 0;
	isMachineCreated = false;
  }
/**
* Creates a Regular Vending Machine based on the number of slots and capacity.
* <p>
* Creates a Regular Vending Machine based on the number of slots
* and capacity the user inputs. Then asks the user what items would the user
like
* to store, set the price of the item, and input how many calories each item
has.
*
* @param scanner user input
*/
  public void createRegularVendingMachine (Scanner scanner)
  {
	int slots;
	int capacity;
	do
	  {
		System.out.print ("Enter the number of slots (must be at least 8): ");
		slots = scanner.nextInt ();
	  }
	while (slots < 8);
	do
	  {
		System.out.print ("Enter the capacity per slot (must be at least 10):
");
		capacity = scanner.nextInt ();
	  }
	while (capacity < 10);
	for (int i = 1; i <= slots; i++)
	  {
		String itemName;
		double itemPrice;
		int itemCalories;
		System.out.println ("\n--- Slot " + i + " ---");
		System.out.print ("Enter the item name: ");
		itemName = scanner.next ();
		System.out.print ("Enter the item price: $");
		itemPrice = scanner.nextDouble ();
		System.out.print ("Enter the item calories: ");
		itemCalories = scanner.nextInt ();
		Item item = new Item (itemName, itemPrice, itemCalories);
		items.put (i, item);
		stock.put (i, capacity);
	  }
	isMachineCreated = true;
	System.out.println ("\nRegular Vending Machine created successfully!");
  }
/**
* Testing function of the vending machine
* <p>
* This method tests the functions of the vending machine. It checks if there
is
* a vending machine made and will act accordingly based on user input.
*
* @param scanner user input
*/
  public void testVendingMachine (Scanner scanner)
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	displayItems ();
	displayCalories ();
	System.out.print ("Enter the slot number of the item you want to purchase:
");
	int slotNumber = scanner.nextInt ();
	if (!items.containsKey (slotNumber))
	  {
		System.out.println ("Invalid slot number. Please try again.");
		return;
	  }
	Item item = items.get (slotNumber);
	if (stock.get (slotNumber) == 0)
	  {
		System.out.println ("This item is out of stock. Please choose another
item.");
		return;
	  }
	System.out.println ("You have selected: " + item.getName ());
	System.out.print ("Enter the amount to insert ($" + item.getPrice () + "):
$");
	double amountInserted = scanner.nextDouble ();
	if (amountInserted < item.getPrice ())
	  {
		System.out.println ("Insufficient amount. Please insert the correct
amount.");
		return;
	  }
	double change = amountInserted - item.getPrice ();
	stock.put (slotNumber, stock.get (slotNumber) - 1);
	totalSales += item.getPrice ();
	System.out.println ("Dispensing " + item.getName () + "...");
	System.out.println ("Change: $" + change);
	System.out.println ("\nRegular Vending Machine transaction completed!");
  }
/**
* Displays the items.
* <p>
* This method creates a screen where it shows the items
* on display for the customer to purchase from.
*/
  public void displayItems ()
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Available Items ---");
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		int itemStock = stock.get (slotNumber);
		System.out.println (slotNumber + ". " + item.getName () + " - $" +
							item.getPrice () + " (Stock: " + itemStock + ")");
	  }
  }
/*
* Restocks the items based on the user input.
* <p>
* This method takes in the slot number and restocks the item slot based on the
user's input.
*
* @param scanner user input
*/
  public void restockItems (Scanner scanner)
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Restocking Items ---");
	initialSales = totalSales;
	initialMoney = currentMoney;
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		displayItems ();
		System.out.print ("Enter the quantity to restock for slot " +
						  slotNumber + " (" + item.getName () + "): ");
		int quantity = scanner.nextInt ();
		stock.put (slotNumber, stock.get (slotNumber) + quantity);
	  }
	System.out.println ("\nItems restocked successfully!");
  }
/**
* Sets the price of an item.
* <p>
* This method sets the price of an item based on the user input.
*/
  public void setItemPrice (Scanner scanner)
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Setting Item Price ---");
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		displayItems ();
		System.out.print ("Enter the new price for slot " + slotNumber +
						  " (" + item.getName () + "): $");
		double newPrice = scanner.nextDouble ();
		item.setPrice (newPrice);
	  }
	System.out.println ("\nItem prices updated successfully!");
  }
/**
* Collects the money from the vending machine.
* <p>
* This method collects the money made from the sales of the vending machine.
*/
  public void collectMoney ()
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Collecting Money ---");
	if (totalSales == initialSales)
	  {
		System.out.
		  println ("No new sales since the last restocking. Nothing to
collect.");
		return;
	  }
	double collectedMoney = totalSales - initialSales;
	currentMoney += collectedMoney;
	totalSales = initialSales;
	System.out.println ("Collected money: $" + collectedMoney);
	System.out.println ("Total money in machine: $" + currentMoney);
  }
/*
* Replenishes the change of the vending machine.
* <p>
* This method allows the user the replenish the money
* stored in the vending machine in denomination quantities.
* @param scanner user input of change
*/
  public void replenishChange (Scanner scanner)
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Replenishing Change ---");
	System.out.print ("Enter the denomination of the change to replenish: $");
	double denomination = scanner.nextDouble ();
	System.out.print ("Enter the quantity of " + denomination + " dollar bills
to replenish: ");
	int quantity = scanner.nextInt ();
	money.put (denomination, money.getOrDefault (denomination, 0) + quantity);
	System.out.println ("Change replenished successfully!");
  }
/**
* Displays the calories of an item
* <p>
* This method displays the calories of the items in the vending machine.
*/
  public void displayCalories ()
  {
	System.out.println ("Calories per item:");
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		System.out.println ("Slot " + slotNumber + ": " + item.getName () +
							" - " + item.getCalories () + " calories");
	  }
  }
/*
* Prints a summary of transactions done by the vending machine.
* <p>
* This method prints a detailed transaction summary to help see how many sales
the vending machine made.
*/
  public void printTransactionSummary ()
  {
	if (!isMachineCreated)
	  {
		System.out.println ("Vending Machine is not created. Please create a
Regular Vending Machine first.");
		return;
	  }
	System.out.println ("\n--- Transaction Summary ---");
	System.out.println ("Total Sales: $" + totalSales);
	System.out.println ("Starting Inventory:");
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		int initialStock = stock.get (slotNumber);
		System.out.println (slotNumber + ". " + item.getName () +
							" - Stock: " + initialStock);
	  }
	System.out.println ("\nEnding Inventory:");
  for (Map.Entry < Integer, Item > entry:items.entrySet ())
	  {
		int slotNumber = entry.getKey ();
		Item item = entry.getValue ();
		int currentStock = stock.get (slotNumber);
		System.out.println (slotNumber + ". " + item.getName () +
							" - Stock: " + currentStock);
	  }
  }
}
