package ir.javacup.accounting;

import java.util.ArrayList;

public class Accounting {
    ArrayList<Cost> a = new ArrayList<>();

    public void addCost(Cost cost) {
        a.add(cost);
    }

    public Cost getCost() {
		Cost last = null;
		int priority = 0;

		for (Cost cost : a) {
			if (cost instanceof Health) {
				if (((Health) cost).getPriority() > priority) {
				    priority = ((Health) cost).getPriority();
					last = cost;
				}
			}
		}

		if (last != null) {
			a.remove(last);
			return last;
		}

		for (Cost cost : a) {
			if (cost instanceof Grocery) {
				a.remove(cost);
				return cost;
			}
		}

        for (Cost cost : a) {
            if (cost instanceof HomeAppliance) {
                last = cost;
            }
        }
        if (last != null)
            a.remove(last);
        return last;
    }

    public static void main(String[] args) {
        Accounting acc = new Accounting();
        acc.addCost(new Grocery(50000, "meat"));
        acc.addCost(new Health(100000, 1, "CalMagZink capsule"));
        acc.addCost(new HomeAppliance(4000000, "TV"));
        acc.addCost(new Health(60000, 4, "yearly check up"));
        acc.addCost(new Grocery(4000, "pancake powder"));
        acc.addCost(new HomeAppliance(600000, "pot"));

        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
        System.out.println(acc.getCost());
    }

}
