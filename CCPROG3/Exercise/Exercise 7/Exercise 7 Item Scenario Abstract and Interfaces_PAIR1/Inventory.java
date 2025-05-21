//Inventory Class

import java.util.ArrayList;

public class Inventory {
    private ArrayList<Item> itemList;

    public Inventory() {
        itemList = new ArrayList<>();
    }

    public void addItem(Item item) {
        itemList.add(item);
    }

    public boolean sellItem(int index) {
        if (index >= 0 && index < itemList.size()) {
            Item item = itemList.get(index);
            if (item.isSellable()) {
                double price = ((Sellable) item).computePrice();
                System.out.println("Item " + item.getName() + " sold for " + price + " money.");
                itemList.remove(index);
                return true;
            } else {
              //  System.out.println("Item " + item.getName() + " is not sellable.");
                return false;
            }
        } else {
            System.out.println("Invalid index.");
            return false;
        }
    }

    public void displayItemInformation() {
        if (itemList.isEmpty()) {
            System.out.println("Inventory is empty.");
        } else {
            for (int i = 0; i < itemList.size(); i++) {
                Item item = itemList.get(i);
                System.out.print((i + 1) + ". " + item.getName() + " (weight " + item.getWeight() + ")");
                if (item.isSellable()) {
                    System.out.println(" (sellable)");
                } else {
                    System.out.println();
                }
            }
        }
    }
}
