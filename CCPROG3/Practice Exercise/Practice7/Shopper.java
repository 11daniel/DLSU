/**
	This is a representation of the Personal Shopper.  A Personal Shopper has a name.
	When a buyer is assigned, he will have a Personal Shopper Assignment.  Through the
	assignement, the Shopper can has access to the StockRoom and can search for products,
	and update products when products are sold.  The Shopper can also update the shopping
	cart by adding the products ordered by the buyer.
 
	When the buyer paid for the items in the current transaction, that transaction will be
	closed and the Assignment of this shopper will be removed.  This shopper will now be
	available to accept the next assignment.
 */

public class Shopper {
	private String name;
	private Assignment psp;

	/**
		creates a Shopper object with the given name.  No Personal Shopper Assignment
		will be given yet.
	 
		@param name name of this shopper object
	 */
	public Shopper(String name) {
		this.name = name;
		this.psp = null;
	}
	
	/**
		returns the name of this shopper
	 
		@return name of this shopper
	 */
	public String getName() {
		return this.name;
	}

	/**
		can be used to determine if this shopper has an Assignment.
	 
		@return true if this shopper has an Assignment, false otherwise
	 */
	public boolean isAvailable() {
		return this.psp == null;
	}
	
	/**
		assigns a buyer to this shopper through an Assignment object.  If the shopper has
		an existing assignment, nothing happens.
	 
		@param psp Personal Shopper Assignment to be assigned to this shopper
	 */
	public void assignedBuyer(Assignment psp) {
		if(isAvailable()) {
			this.psp = psp;
		}
	}
	
	/**
		returns a reference to the product in the StockRoom.  This is only possible if this
		shopper has an Assignment. The shopper can request StockRoom access through
		of his Assignment, and search the StockRoom.
	 
		If this shopper has no Assignment, nothing happens.
	 
		@param name name of the product
		@return the product if found; null if not found, or shopper has no Assignment
	 */
	private Product getProductFromStockRoom(String name) {
		Product product = null;

		if(!isAvailable()) {
			StockRoom access = this.psp.getStockRoomAccess();
			product = access.getProduct(name);
		}

		return product;
	}
	
	/**
		updates the shopping cart of the buyer.  This is only possible if the shopper has an
		Assignment.  The shopper creates a Product entry with the product name and quantity bought.
	 
		If the given quantity is more than the current quantity of the product in the StockRoom,
		the buyer will only be given what is available.
	 
		The Product will be updated accordingly.
	 
		@param name name of the product
		@param qty quantity to buy
	 */
	public void updateCartAndStock(String name, int qty) {
		if(!isAvailable()) {
			Product stock = this.getProductFromStockRoom(name);
			
			if(stock != null) {
				System.out.println();
				
				int nOnHand = stock.getCount();
				
				if(nOnHand > 0) {
					// can buy only what's available
					if(nOnHand < qty) {
						System.out.println("Only " + nOnHand + " " + name + " available");
						qty = nOnHand;
						
					}
					
					// update StockRoom product data
					stock.sold(qty);
					
					// create a Product to be added to the list
					Product shopped;
					shopped = new Product(name, qty, stock.getPrice());
					
					// add this to the shopping cart of the buyer
					this.psp.addToCart(shopped);
					System.out.println(qty + " " + name + " added to cart");
				}
			} else {
				System.out.println(name + " not available");
			}
		}
	}
	
	/**
		end of the current Personal Shopper Assignment, thus the current Assignment, if any, will
		be removed from this Shopper.
	 */
	public void closedTransaction() {
		this.psp = null;
	}

	/**
		returns the string representation of this Shopper object.
	 
		@return string representation with name and details of Personal Shopper Assignment
				if any.
	 */
	@Override
	public String toString() {
		String text = this.name;
		
		if(!isAvailable())
			text += "\n" + this.psp + "\n";
		else
			text += "\t(available)\n";
		
		return text;
	}
}
