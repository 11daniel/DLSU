public class Main {
	public static void main(String[] args) {
		Food apple = new Food("Apple", 0.3, 13);
		Scrap trash1 = new Scrap("Trash", 0.5);
		Scrap trash2 = new Scrap("Big Trash", 5.3);
		Jewelry diamond = new Jewelry("Diamond", 0.04, 0.5);

		Inventory inventory = new Inventory();
		inventory.addItem(apple);
		inventory.addItem(trash1);
		inventory.addItem(trash1);
		inventory.addItem(trash2);
		inventory.addItem(diamond);

		System.out.println("Displaying items in inventory...");
		inventory.displayItemInformation();
		System.out.println("");

		boolean result = inventory.sellItem(2); // Attempt to sell the 2nd trash1 object
		System.out.println("Result of selling index 3 - 2nd trash1 object: " + result);
		System.out.println("");

		result = inventory.sellItem(0); // Attempt to sell the apple object
		System.out.println("Result of selling index 0 - apple object: " + result);
		System.out.println("");

		result = inventory.sellItem(2); // Attempt to sell the trash2 object
		System.out.println("Result of selling index 3 - apple object: " + result);
		System.out.println("");

		System.out.println("Displaying items in inventory...");
		inventory.displayItemInformation();
		System.out.println("");
	}
}