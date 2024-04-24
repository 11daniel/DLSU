/**
	This is a representation of a Buyer object.  A buyer has a name.  When the buyer 	requests for a
	Personal Shopper, he is given an Assignment.  Afterwhich, the buyer can buy products, review the
	contents of his cart, and pay for these items.
 */

public class Buyer {
	private String name;
	private Assignment psp;
	
	/**
		a new Buyer object is created with the given name.  No assignment is given at this time.
		
		@param name name of the Buyer
	 */
	public Buyer(String name) {
		this.name = name;
		this.psp = null;
	}

	/**
		returns the name of this buyer
	 
		@return name of this buyer
	 */
	public String getName() {
		return name;
	}

	
	/**
		an Personal Shopper Assignment is assigned to the buyer.  With this, the buyer can
		start shopping.
	 
		@param psp Assignment assigned to this buyer
	 */
	public void availPSP(Assignment psp) {
		this.psp = psp;
	}
	
	/**
		buys the product with the given name and quantity. If this buyer has no Personal Shopper
		Assignment yet, nothing happens.
	 
		@param name name of the product
		@param qty number of this product the buyer wants to buy
	 */
	public void buy(String name, int qty) {
		if(this.psp != null) {
			this.psp.buy(name, qty);
		} else {
			System.out.println(this.name + " cannot shop, no shopper assigned");
		}
	}
	
	/**
		list of the products in the shopping cart. If this buyer has no Personal Shopper Assignment
		yet, nothing happens.
	 */
	public void review() {
		if(this.psp != null) {
			this.psp.list();
		}
	}

	/**
		pays for the products in the shopping cart. If this buyer has no Personal Shopper Assignment
		yet, nothing happens.
	 */
	public void pay() {
		if(this.psp != null) {
			this.psp.pay();
		}
	}
	
	/**
		end of the current Personal Shopper Assignment, thus the current Assignment, if any, will be
		removed from this Buyer.
	 */
	public void closedTransaction() {
		this.psp = null;
	}
	
	/**
		returns the string representation of the Buyer object.
	 
		@return string representation with name and details of Personal Shopper 	Assignment.
	 */
	@Override
	public String toString() {
		String text = name;
		
		if(this.psp != null)
			text += "\n" + this.psp + "\n";
		
		return text;
	}
}
