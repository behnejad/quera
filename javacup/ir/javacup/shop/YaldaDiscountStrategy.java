package ir.javacup.shop;

public class YaldaDiscountStrategy implements DiscountStrategy {
    @Override
    public long priceByDiscount(Clothing clothing) {
        if (clothing instanceof Jacket) {
            return clothing.getBasePrice() * 9 / 10;
        } else if (clothing instanceof Socks) {
            return clothing.getBasePrice() * 8 / 10;
        } else {
            return clothing.getBasePrice() * 3 / 4;
        }
    }
}
