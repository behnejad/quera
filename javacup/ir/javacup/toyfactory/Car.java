package ir.javacup.toyfactory;

public class Car extends Toy {
    public Car(double basePrice, ToySize size) {
        super(basePrice, size);
    }

    @Override
    public double getPrice() {
        switch (size) {
            case SMALL:
                return getBasePrice() * 2;
            case MEDIUM:
                return getBasePrice() * 2.5;
            case LARGE:
                return getBasePrice() * 3;
            default:
                return 0;
        }
    }
}
