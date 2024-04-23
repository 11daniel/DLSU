public class VendingItem
{
  private String name;
  private double price;
/**
* Creates a VendingItem object that has a name and a price.
*/
  public VendingItem (String name, double price)
  {
	this.name = name;
	this.price = price;
  }
/**
* Gets the name of the item in the vending machine.
*/
  public String getName ()
  {
	return name;
  }
/**
* Gets the price of the item in the vending machine.
*/
  public double getPrice ()
  {
	return price;
  }
/**
* Sets the price of the item in the vending machine.
*/
  public void setPrice (double price)
  {
	this.price = price;
  }
}
