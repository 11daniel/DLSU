public abstract class Card{
	private String cardholderName;
	private int idNumber;
	private int earnedPoints;

	public Card(String cardholderName, int idNumber) {
		this.cardholderName = cardholderName;
		this.idNumber = idNumber;
		this.earnedPoints = 0;
	}

	public abstract void recordTransaction(double amountSpent);

	protected void incrementPoints(int points) {
		this.earnedPoints += points;
	}

	public boolean claimReward() {
		boolean result = false;
		if(this.earnedPoints >= 150) {
			result = true;
			this.earnedPoints -= 150;
		}
		return result;
	}

	protected abstract String claimRewardResponse();

	public void displayInformation() { 
		System.out.println("Cardholder: " + this.cardholderName);
		System.out.println("ID number: " + this.idNumber);
		System.out.println("Earned points: " + this.earnedPoints);
		System.out.println("Claim award: " + this.claimRewardResponse());
	}

	protected int getEarnedPoints() {
		return this.earnedPoints;
	}
}