public class ShoppingItem {
    private final int id;
    private String itemName;
    private double price;
    private int stock;

    public ShoppingItem(int id, String itemName, double price){
        this.id = id;
        this.itemName = itemName;
        this.price = price;
        this.stock = 0;
    }

    public double applyDeduction(double d){
        return this.price = this.price - (this.price * d);
    }

    public String toString(){
        return this.itemName + " (" + this.id + "): costs " + this.price + " and has " + this.stock + " stock.";
    }

    public int getId(){
        return this.id;
    }

    public String getItemName(){
        return this.itemName;
    }

    public double getPrice(){
        return this.price;
    }

    public int getStock(){
        return this.stock;
    }

    public void setStock(int stock){
        this.stock = stock;
    }

}