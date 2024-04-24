/**
	Membership object represents a member of the OUR Department Store.  It includes the 	name
	and the points accumulated by the member.
 
	Two Membership objects are considered equal if the names are the same.
 */
public class Membership {
	private String name;
	private int points;
	
	/**
		creates a new Membership object for the given name.
	 
		@param name name of the member
	 */
	public Membership(String name) {
		this.name = name;
		this.points = 0;
	}
	
	
	/**
		updates the points based on the amount provided.  The member earns 3 points for
		every 100-peso spent.
	 
		@param amountPaid amount paid for a transaction
	 */
	public void addToPoints(double amountPaid) {
		// TODO : Complete the statement.  This computes for the points
		//		  to be added to this Member.  3 points for every 100-peso.
		int nToAdd = ((int) amountPaid / 100) * 3;
		
		System.out.println("Current points : " + this.points);
		System.out.println("Add : " + nToAdd);

		this.points += nToAdd;
		
		System.out.println("Updated points : " + this.points);
	}
	
	/**
		returns the name of the member
	 
		@return name of the member
	 */
	public String getName() {
		return this.name;
	}
	
	/**
		returns the number of points
	 
		@return points earned
	 */
	public int getPoints() {
		return this.points;
	}
	
	
	/**
		returns string representaion indicating the name and points of this object
	 
		@return returns a string representaion with the name and points
	 */
	@Override
	public String toString() {
		return this.name + " (" + this.points + ")";
	}
}














