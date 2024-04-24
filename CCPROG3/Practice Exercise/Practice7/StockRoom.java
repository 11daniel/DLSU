/**
	The StockRoom has a list of products it manages.  Products are identified by their unique names.
 */

import java.util.*;

public class StockRoom {
	// TODO : include attributes of StockRoom
	private ArrayList<Product> products;
	
	// TODO : Complete the code for the Constructor of StockRoom
	/**
		creates a StockRoom object.  By default, no products in the list when the object is created.
	 */
	public StockRoom() {
		this.products = new ArrayList<Product>();
	}
	
	// TODO : Complete the code to add products to the list.
	//        Add only products with UNIQUE names.
	/**
		adds the product with the given details to the list.  If the "same" product exists, this product will not be added to the list.
		
		@param name name of the product
		@param qty quantity of the product
		@param price unit price of the product
	 */
	public void addProduct(String name, int qty, double price) {
		boolean result = false;

		for(Product p : products) {
			if(p.getName().equals(name)) {
				result = true;
				break;
			}
		}

		if(!result) {
			this.products.add(new Product(name, qty, price));
		}
	}
	
	// TODO : Write the code to search for the product in the list
	//	      with the given name, return a reference to that product.
	/**
		returns a reference to the Product object.
	 
		@param name name of the product
		@return Product object with the given name; null if not in the list
	 */
	public Product getProduct(String name) {
		Product temp = null;

		for(Product p : this.products) {
			if(p.getName().equals(name)) {
				temp = p;
				break;
			}
		}

		return temp;
	}
	
	/**
		returns the available quantity of the Product with the gvien name
	 
		@param name name of the product
		@return quantity on hand; 0 if product is not in the list
	 */
	public int getStockCount(String name) {
		Product p = this.getProduct(name);
		
		if(p != null) {
			return p.getCount();
		}

		return 0;
	}
	
	/**
		updates the quantity of the given product.  The given qty is subtracted from the
		current count of the product.  If product is not found, nothing is updated.  If the
		given qty is more than the product's current count, no update will happen.
	 
		@param name name of the product
		@param qty quantity sold
	 */
	public void sold(String name, int qty) {
		Product p = this.getProduct(name);
		
		if(p != null) {
			p.sold(qty);
		}
	}
	
	/**
		returns a string representation of this StockRoom.  Displays the inventory.
	 
		@return string representation of the StockRoom
	 */
	@Override
	public String toString() {
		String text = "";

		for(Product p : this.products) {
			text += p + "\n";
		}
		
		return text;
	}
}
