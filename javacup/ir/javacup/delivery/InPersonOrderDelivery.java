package ir.javacup.delivery;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;

public class InPersonOrderDelivery implements OrderDelivery {
    ArrayList<Order> a = new ArrayList<>();

    @Override
    public Order getCurrentOrder() {
        Order b = a.get(0);
        a.remove(0);
        return b;
    }

    @Override
    public void takeNewOrder(Order order) {
        for (Order i : a) {
            if (i.getWeight() == order.getWeight() && i.getPhoneNumber() == order.getPhoneNumber()) {
                return;
            }
        }
        a.add(order);
        a.sort(Comparator.comparingInt(o -> o.getName().charAt(1)));
    }

    @Override
    public Collection<Order> getOrders() {
        return a;
    }
}
