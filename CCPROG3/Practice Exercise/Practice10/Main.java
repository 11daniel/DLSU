public class Main {
	public static void main(String[] args) {
		AdvantageCard advantageCard = new AdvantageCard("Mario", 1);

		advantageCard.recordTransaction(199.0);
		advantageCard.recordTransaction(800.0);
		advantageCard.recordTransaction(1000.0);

		advantageCard.displayInformation();

		System.out.println("\nClaiming reward: " + advantageCard.claimReward() + "\n");

		advantageCard.displayInformation();

		System.out.println("\nClaiming reward: " + advantageCard.claimReward() + "\n");

		PrestigeCard prestigeCard = new PrestigeCard("Jose", 2);

		prestigeCard.recordTransaction(199.0);
		prestigeCard.recordTransaction(800.0);
		prestigeCard.recordTransaction(1000.0);

		prestigeCard.displayInformation();

		System.out.println("\nClaiming reward: " + prestigeCard.claimReward() + "\n");

		prestigeCard.displayInformation();

		System.out.println("\nClaiming reward: " + prestigeCard.claimReward() + "\n");

		prestigeCard.displayInformation();

		System.out.println("\nClaiming reward: " + prestigeCard.claimReward() + "\n");
	}
}