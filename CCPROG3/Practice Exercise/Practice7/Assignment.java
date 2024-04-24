/**
	This is a representation of a Personal Shopper Assignment.  This object is created whenever a buyer
	requests for a personal shopper and the a shopper is assigned to the buyer.
 
	This assignment keeps track of the Shopper and Buyer, access to the StockRoom so that the shopper
	will be able to get the products and update the inventory, a cart that contains all the products specified
	by the buyer, and whether the transaction is active or not.  An active transaction means that the buyer
	is still specifying products to buy.  An inactive transaction means the buyer paid for the products, thus
	this assignment has ended.
 */
import java.util.*;

public class Assignment {
	// TODO : Declare all attributes of Assignment
	private Shopper shopper;
	private Buyer buyer;
	private Membership member;
	private StockRoom access;
	private ArrayList<Product> cart;
	private boolean bActive;
	
	/**
		creates a Personal Shopper Assignment object.  The given Buyer is assigned to the Shopper, and
		the Shopper can access the StockRoom through this assignment.  If the buyer is a member, a
		reference to his membership is also provided.
	 
		@param buyer buyer requesting for personal shopper
		@param shopper shopper assigned
		@param member membership of the buyer, if any
		@param access stock room access for the shopper to use
	 */
	public Assignment(Buyer buyer, Shopper shopper, Membership member, StockRoom access) {
		this.shopper = shopper;
		shopper.assignedBuyer(this);

		this.buyer = buyer;
		buyer.availPSP(this);

		this.member = member;
		this.access = access;
		
		this.cart = new ArrayList<Product>();
		this.bActive = true;
	}
	
	/**
		instructs a buy operation for the product with the given name and quantity. If product does not
		exist, or if quantity in stock of the given product is 0, nothing happens.  Otherwise, the product
		is added to the cart.
	 
		@param name name of the product
		@param qty quantity to buy
	 */
	public void buy(String name, int qty) {
		System.out.println("\n" + this.buyer.getName() + " orders " + qty + " " + name);
		this.shopper.updateCartAndStock(name, qty);
	}
	
	/**
		adds the given product to the cart.
	 
		@param product product to be added to the cart
	 */
	public void addToCart(Product product) {
		this.cart.add(product);
	}
	
	/**
		lists the details of the products in the cart and the current total.
	 */
	public void list() {
		System.out.println("\n" + this.buyer.getName() + " Cart:");

		for(Product p : this.cart) {
			System.out.println(p);
		}
		
		System.out.println("Total = " + this.getTotal() + "\n");
	}
	
	/**
		returns the total amount of all the items in the cart.
	 
		@return total amount
	 */
	public double getTotal() {
		double dTotal = 0;

		for(Product p : this.cart) {
			dTotal += p.getPrice() * p.getCount();
		}

		return dTotal;
	}
	
	/**
		executes a pay operation.  This means that this transaction paid and will be closed.
		If the buyer is a member, the corresponding points will be added to his membership data.
		This transaction is closed and is not active anymore.
		The assignments of the shopper and buyer will also be removed.
	 */
	public void pay() {
		System.out.println(this.buyer.getName() + " paid " + this.getTotal());
		
		if(this.member != null)
			this.member.addToPoints(this.getTotal());
		else
			System.out.println(this.buyer.getName() + " is not a member");
		
		String buyerName = this.buyer.getName();
		this.shopper.closedTransaction();
		this.buyer.closedTransaction();

		bActive = false;
		
		System.out.println("CLOSED transaction: " + buyerName + "\n");
	}
	
	/**
		returns a reference to the StockRoom.
	 
		@return reference to the stockroom
	 */
	public StockRoom getStockRoomAccess() {
		return this.access;
	}
	
	/**
		returns the string representation of this object.
	 
		@return names of the Buyer, Membership data, if any, and Shopper and whether this
		assignment is active or not.
	 */
	@Override
	public String toString() {
		String text = "Shopper : " + this.shopper.getName() + "\n" + "Buyer : " + this.buyer.getName() + "\n";
		
		if(this.member != null)
			text += "\t" + this.member.getPoints() + " points\n";
		
		if(!this.bActive)
			text += "in";
		text += "active\n";
		
		return text;
	}
}
