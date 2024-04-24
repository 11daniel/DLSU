/**
	A Product object represents an item sold by the OUR Department Store.  Each product
	has a unique name, available quantity(in stock), and price.
 */

public class Product
{
	private String name;
	private int count;
	private double price;
	
	/**
		creates a Product object with the given name, count and price
	 
		@param name name of the product
		@param count quantity
		@param price unit price of the product / price of one order of this product
	 */
	public Product(String name, int count, double price) {
		this.name = name;
		this.count = count;
		this.price = price;
	}
	
	/**
		returns the name of this product.
	 
		@return name of the product
	 */
	public String getName() {
		return this.name;
	}

	/**
		returns the availabe quantity of this product.
	 
		@return quantity of the product
	 */
	public int getCount() {
		return this.count;
	}

	/**
		returns the price of this product.
	 
		@return price of the product
	 */
	public double getPrice() {
		return this.price;
	}
	
	/**
		updates the count in stock of the product based on the given quantity.  The given
		quantity is reduced from the count of this product.  Update will only happen if the given
		quantity is less than or equal to the count of this product; no update otherwise.
	 
		@param qty quantity sold.
	 */
	public void sold(int qty) {
		if(qty <= this.count) {
			System.out.println("On Hand : " + qty + " " + this.name);
			this.count -= qty;
			System.out.println("Sold : " + qty + " " + this.name);
		}
	}
	
	/**
		returns the string representation of this object.
	 
		@return a string with product's name, current count and price
	 */
	@Override
	public String toString() {
		return this.name + "\n\tOn hand: " + this.count + "\n\tPrice: " + this.price;
	}
}
