package ir.javacup.delivery;

import java.util.*;

public class CallOrderDelivery implements OrderDelivery {
    ArrayDeque<Order> a = new ArrayDeque<>();

    @Override
    public Order getCurrentOrder() {
        return a.removeLast();
    }

    @Override
    public void takeNewOrder(Order order) {
        for (Order i : a) {
            if (i.getWeight() == order.getWeight() && i.getPhoneNumber() == order.getPhoneNumber()) {
                return;
            }
        }
        a.addFirst(order);
    }

    @Override
    public Collection<Order> getOrders() {
        return a;
    }
}
