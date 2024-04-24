public class OURDriver
{
	private OURDeptStore store;
	
	public OURDriver() {
		store = new OURDeptStore();
	}
	
	/**
		adds product to the store's inventory
	 */
	public void setupStockRoom() {
		store.addProduct("apple", 8, 25);
		store.addProduct("banana", 20, 19);
		store.addProduct("kiwi", 50, 12.5);
		store.addProduct("orange", 45, 17);
		store.addProduct("watermelon", 10, 103);
		store.addProduct("mango", 35, 22.25);
		
		System.out.println("(1) Stock Room inventory: ");
		store.listProducts();
	}
	
	/**
		adds shoppers
	 */
	public void setupShoppers() {
		store.addShopper("Aimee");
		store.addShopper("Mely");
		
		System.out.println("(2) Shoppers: ");
		store.listShoppers();
	}
	
	/**
		add members to the store's membership program
	 */
	public void addMembers() {
		store.addMember("Zoe");
		store.addMember("Yasmine");
		store.addMember("Xian");
		
		System.out.println("(3) Members: ");
		store.listMembers();
	}
	
	/**
		returns a reference to the store
	 
		@return reference to the store created
	 */
	public OURDeptStore getStore() {
		return store;
	}
	
	public static void main(String[] args) {
		OURDriver app = new OURDriver();
		
		System.out.println("\nSetting up...");
		app.setupStockRoom();
		app.setupShoppers();
		app.addMembers();
		
		System.out.println("\n\nOUR is now open\n");
		
		/* OUR Department Store open for business */
		OURDeptStore dept = app.getStore();
		
		System.out.println("Zoe shops with a Personal Shopper");
		Buyer zoe = new Buyer("Zoe");
		dept.assignShopper(zoe);
		zoe.buy("apple", 5);
		zoe.buy("banana", 8);
		zoe.review();
		zoe.pay();
		
		System.out.println();
		System.out.println("Vannie shops with a Personal Shopper");
		Buyer vannie = new Buyer("Vannie");
		dept.assignShopper(vannie);
		vannie.buy("apple", 5);
		vannie.buy("kiwi", 8);
		vannie.buy("watermelon", 10);
		vannie.buy("pineapple", 1);
		
		System.out.println();
		System.out.println("Manny shops with a Personal Shopper");
		Buyer manny = new Buyer("Manny");
		dept.assignShopper(manny);

		System.out.println();
		System.out.println("Lannie shops with a Personal Shopper");
		Buyer lannie = new Buyer("Lannie");
		dept.assignShopper(lannie);
		
		lannie.buy("grapes", 5);

		vannie.review();
		vannie.pay();

		System.out.println();
		System.out.println("Zoe shops again with a Personal Shopper");
		zoe = new Buyer("Zoe");
		dept.assignShopper(zoe);
		zoe.buy("mango", 3);
		zoe.buy("orange", 18);
		zoe.review();
		zoe.pay();
	}
}
