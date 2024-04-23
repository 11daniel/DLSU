public class Slot
{
  private Item item;
  private int quantity;
/**
* Creates a Slot object based on the number of items input by the user
*
* @param item uses item function
* @param quantity number that dictates how many items are there
*/
  public Slot (Item item, int quantity)
  {
	this.item = item;
	this.quantity = quantity;
  }
/**
* Returns an item.
* <p>
* This method would return the item.
*/
  public Item getItem ()
  {
	return item;
  }
/**
* Returns quantity of an item
* <p>
* This method would return a quantity of a specific item.
*/
  public int getQuantity ()
  {
	return quantity;
  }
/**
* Sets the quantity of an item.
* @param quantity a number
*/
  public void setQuantity (int quantity)
  {
	this.quantity = quantity;
  }
/**
* Checks if there is an item and dispenses the item.
* <p>
* This method checks if there is an item and subtracts the quantity of that
item.
* If there is no item, then it prints "Out of stock" of the certain item.
*/
  public boolean hasItem ()
  {
	return quantity > 0;
  }
/**
* Checks if there is an item and dispenses the item.
* <p>
* This method checks if there is an item and subtracts the quantity of that
item.
* If there is no item, then it prints "Out of stock" of the certain item.
*/
  public void dispenseItem ()
  {
	if (hasItem ())
	  {
		quantity--;
		System.out.println ("Item dispensed: " + item.getName ());
	  }
	else
	  {
		System.out.println ("Out of stock: " + item.getName ());
	  }
  }
}
