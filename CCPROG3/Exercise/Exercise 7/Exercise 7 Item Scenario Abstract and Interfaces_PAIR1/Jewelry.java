//Jewelry class
public class Jewelry extends Item implements Sellable {
    private double carats;

    public Jewelry(String name, double weight, double carats) {
        super(name, weight);
        this.carats = carats;
    }

    public double getCarats() {
        return carats;
    }

    @Override
    public boolean isSellable() {
        return true;
    }

    @Override
    public double computePrice() {
        return carats * 100;
    }
}
