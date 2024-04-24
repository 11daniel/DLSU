//Food Class

public class Food extends Item implements Sellable {
    private int nutritionValue;

    public Food(String name, double weight, int nutritionValue) {
        super(name, weight);
        this.nutritionValue = nutritionValue;
    }

    public int getNutritionValue() {
        return nutritionValue;
    }

    @Override
    public boolean isSellable() {
        return true;
    }

    @Override
    public double computePrice() {
        return nutritionValue * 10;
    }
}
