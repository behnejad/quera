package ir.javacup.shop;

public class WinterDiscountStrategy implements DiscountStrategy {
    @Override
    public long priceByDiscount(Clothing clothing) {
        if (clothing instanceof Jacket) {
            switch (clothing.getSeason()) {
                case FALL:
                    return ((clothing.getBasePrice() * 6 / 10) * 9 / 10);
                case SPRING:
                    return (clothing.getBasePrice() * 9 / 10);
                case WINTER:
                    return ((clothing.getBasePrice() / 2) * 9 / 10);
                case SUMMER:
                    return ((clothing.getBasePrice() * 3 / 4) * 9 / 10);
                default:
                    return 0;
            }
        }
        switch (clothing.getSeason()) {
            case FALL:
                return (clothing.getBasePrice() * 6 / 10);
            case SPRING:
                return (clothing.getBasePrice());
            case WINTER:
                return (clothing.getBasePrice() / 2);
            case SUMMER:
                return (clothing.getBasePrice() * 3 / 4);
            default:
                return 0;
        }
    }
}
