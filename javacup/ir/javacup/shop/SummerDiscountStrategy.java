package ir.javacup.shop;

public class SummerDiscountStrategy implements DiscountStrategy {
    @Override
    public long priceByDiscount(Clothing clothing) {
        switch (clothing.getSeason()) {
            case FALL:
                return clothing.getBasePrice();
            case SPRING:
                return (clothing.getBasePrice() * 6 / 10);
            case WINTER:
                return (clothing.getBasePrice() * 7 / 10);
            case SUMMER:
                return (clothing.getBasePrice() / 2);
            default:
                return 0;
        }
    }
}
