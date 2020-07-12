package ir.nimbo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Pharmacy {
    private ArrayList<Drug> drugs = new ArrayList<>();
    private String name;
    private Location location;

    public Pharmacy(String name, Location location) {
        this.name = name;
        this.location = location;
    }

    public String getName() {
        return name;
    }

    public Location getLocation() {
        return location;
    }

    public Integer getDrugInventory(Drug drug) {
        int count = 0;
        for (Drug data : drugs) {
            if (data.getName().equals(drug.getName())) {
                count += data.getInventory();
            }
        }
        return (count == 0) ? null : count;
    }

    public int getDrugInventory(String drugName) {
        int count = 0;
        for (Drug i : drugs) {
            if (i.getName().equals(drugName)) {
                count += i.getInventory();
            }
        }
        return count;
    }

    public int getDrugCount() {
        Set<String> i = new HashSet<>();
        for (Drug d : drugs) {
            i.add(d.getName());
        }
        return i.size();
    }

    public int consume(String name, int count) {
        int cost = 0;
        ArrayList<Drug> removeIndex = new ArrayList<>();
        for (int i = 0; i < drugs.size(); ++i) {
            Drug drug = drugs.get(i);
            if (drug.getName().equals(name)) {
                if (drug.getInventory() == count) {
                    removeIndex.add(drug);
                    cost += drug.getPrice() * count;
                    break;
                } else if (drug.getInventory() > count) {
                    drug.consume(count);
                    cost += drug.getPrice() * count;
                    break;
                } else {
                    cost += drug.getPrice() * drug.getInventory();
                    removeIndex.add(drug);
                    count -= drug.getInventory();
                }
            }
        }
        for (Drug r : removeIndex) {
            drugs.remove(r);
        }
        return cost;
    }

    public void addDrug(Drug drug, int inventory) {
        drug.setInventory(inventory);
        drugs.add(drug);
    }

    public void removeDrug(Drug drug) {
        drugs.remove(drug);
    }

    public void updateMe() {
        drugs.removeIf(drug -> drug.getInventory() == 0);
    }

    public ArrayList<Drug> getDrugsList() {
        return drugs;
    }
}
