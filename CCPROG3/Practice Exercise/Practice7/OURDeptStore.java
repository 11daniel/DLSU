/**
	This is a representation of the OUR department store.  OUR department store has a stock room
	to keep all its inventories, a list of shoppers it can assign to buyers requesting for a Personal Shopper,
	a Membership list, and the list of Personal Shopper Assignments.
 
	Whenever a buyer requests for a Personal Shopper, an available Shopper is identified and a new
	Assignment is added to the list.
 */

import java.util.*;

public class OURDeptStore {
	// TODO : Declare all attributes for OURDeptStore
	private StockRoom stockroom;
	private ArrayList<Shopper> shoppers;
	private ArrayList<Membership> members;
	private ArrayList<Assignment> assignments;
	
	
	// TODO : Write the constructor for OURDeptStore.
	//		  Do not forget to instantiate if necessary.
	/**
		creates a new OURDeptStore object.
	 */
	public OURDeptStore() {
		this.stockroom = new StockRoom();
		this.shoppers = new ArrayList<Shopper>();
		this.members = new ArrayList<Membership>();
		this.assignments = new ArrayList<Assignment>();
	}
	
	
	/**
		assigns an available shopper to the given buyer.  To complete this process, an Assignment
		is created.
	 
		@param buyer buyer requesting for a shopper
	 */
	public void assignShopper(Buyer buyer) {
		Shopper s = this.getShopper();
		Membership m = this.getMembership(buyer.getName());
		
		if(s != null) {
			Assignment a = new Assignment(buyer, s, m, this.stockroom);
			this.assignments.add(a);
			System.out.println("Found a shopper");
			System.out.println(a);
		} else {
			System.out.println("No shopper available now");
		}
	}
	
	// TODO : Write the code for getShopper().
	/**
		returns an available Shopper.  This method searches for a shopper who is available
		and returns a reference to this shopper.
	 
		@return available shopper; null if none found
	 */
	private Shopper getShopper() {
		Shopper temp = null;

		for(Shopper s : this.shoppers) {
			if(s.isAvailable()) {
				temp = s;
				break;
			}
		}

		return temp;
	}
	
	
	/**
		returns Membership of the given name.
	 
		@param name name of the buyer
		@return Membership object if found
	 */
	public Membership getMembership(String name) {
		Membership temp = null;

		for(Membership m : members) {
			if(m.getName().equals(name)) {
				temp = m;
				break;
			}
		}
		
		return temp;
	}
	
	/**
		adds a shopper to the list.  Shoppers have unique names.  If the name exists in the list,
		nothing happens.
	 
		@param name name of the Shopper
	 */
	public void addShopper(String name) {
		boolean result = false;

		for(Shopper s : shoppers) {
			if(s.getName().equals(name)) {
				result = true;
				break;
			}
		}

		if(!result) {
			this.shoppers.add(new Shopper(name));
		}
	}
	
	/**
		adds a member to the list.  Members have unique names.  If the name exists in the list,
		nothing happens.
	 
		@param name name of the member
	 */
	public void addMember(String name) {
		boolean result = false;

		for(Membership m : members) {
			if(m.getName().equals(name)) {
				result = true;
				break;
			}
		}
		
		if(!result) {
			this.members.add(new Membership(name));
		}
	}
	
	/**
		adds a product to the stores inventory.  Products have unique names.  If the name exists in the
		list, nothing happens.
	 
		@param name name of the product
		@param count quantity
		@param price price of the product
	 */
	public void addProduct(String name, int count, double price) {
		this.stockroom.addProduct(name, count, price);
	}
	
	/**
		lists all the shoppers
	 */
	public void listShoppers() {
		for(Shopper s : this.shoppers) {
			System.out.println(s);
		}
	}
	
	/**
		lists all the members
	 */
	public void listMembers() {
		for(Membership m : this.members) {
			System.out.println(m);
		}
	}
	
	/**
		lists all the products
	 */
	public void listProducts() {
		System.out.println(this.stockroom);
	}
}
