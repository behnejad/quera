package ir.javacup.shop;

import java.util.function.Function;

import static ir.javacup.shop.ProductState.UNAVAILABLE;

public class OrderFunctionUtilImpl implements OrderFunctionUtil {
    @Override
    public Function<Order, Boolean> isBigOrder() {
        return order -> {
            long a = 0;
            for (Product i : order.getProducts()) {
                a += i.getPrice();
            }
            return a >= 10_000_000;
        };
    }

    @Override
    public Function<Order, Boolean> hasMultipleProducts() {
        return order -> order.getProducts().size() > 1;
    }

    @Override
    public Function<Order, Boolean> hasUnavailableProduct() {
        return order -> {
            for (Product i : order.getProducts()) {
                if (i.getState() == UNAVAILABLE) {
                    return true;
                }
            }
            return false;
        };
    }

    @Override
    public Function<Order, Boolean> isReadyToDeliver() {
        return order -> {
            for (Product i : order.getProducts()) {
                if (i.getState() == UNAVAILABLE) {
                    return false;
                }
            }
            return order.getState() == OrderState.READY_TO_SEND;
        };
    }

    @Override
    public Function<Order, Boolean> hasPerishableProduct() {
        return order -> {
            for (Product i : order.getProducts()) {
                if (i.getType() == ProductType.PERISHABLE) {
                    return true;
                }
            }
            return false;
        };
    }

    @Override
    public Function<Order, Boolean> hasExpensiveBreakableProduct() {
        return order -> {
            for (Product i : order.getProducts()) {
                if (i.getType() == ProductType.BREAKABLE && i.getPrice() >= 5_000_000) {
                    return true;
                }
            }
            return false;
        };
    }
}
