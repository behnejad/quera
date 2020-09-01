package ir.javacup.toyfactory;

enum ToySize {
    SMALL, MEDIUM, LARGE
}

public class Toy {
    private double basePrice;
    protected ToySize size;

    public Toy(double basePrice, ToySize size) {
        this.basePrice = basePrice;
        this.size = size;
    }

    public double getBasePrice() {
        return basePrice;
    }

    public double getPrice() {
        switch (size) {
            case SMALL:
                return basePrice;
            case MEDIUM:
                return basePrice * 1.5;
            case LARGE:
                return basePrice * 2;
            default:
                return 0;
        }
    }

    public double getPrice(double discount) {
        return getPrice() * (100 - discount) / 100;
    }
}
