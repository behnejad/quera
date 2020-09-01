package ir.javacup.delivery;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Stack;

public class SMSOrderDelivery implements OrderDelivery {
    Stack<Order> a = new Stack<>();

    @Override
    public Order getCurrentOrder() {
        return a.pop();
    }

    @Override
    public void takeNewOrder(Order order) {
        for (Order i : a) {
            if (i.getWeight() == order.getWeight() && i.getPhoneNumber() == order.getPhoneNumber()) {
                a.remove(i);
                break;
            }
        }
        a.push(order);
    }

    @Override
    public Collection<Order> getOrders() {
        return a;
    }
}
