//Scrap Class
public class Scrap extends Item {
    public Scrap(String name, double weight) {
        super(name, weight);
    }

    @Override
    public boolean isSellable() {
        return false;
    }
}
