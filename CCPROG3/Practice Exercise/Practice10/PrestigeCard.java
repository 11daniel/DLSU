public class PrestigeCard extends Card {
	public PrestigeCard(String cardholderName, int idNumber) {
		super(cardholderName, idNumber);
	}

	public void recordTransaction(double amountSpent) {
		int points = (((int) amountSpent) / 90) * 15;
		super.incrementPoints(points);
	}

	protected String claimRewardResponse() {
		String response;
		int currPoints = super.getEarnedPoints();

		if(currPoints >= 150) {
			response = "Please claim reward";
		} else {
			int remainingPoints = 150 - currPoints;
			int toSpend = 0;
			while(remainingPoints > 0) {
				toSpend += 90;
				remainingPoints -= 15;
			}
			response = "You need to spend at least " + toSpend + " more pesos to earn an award";
		}
		return response;
	}
}