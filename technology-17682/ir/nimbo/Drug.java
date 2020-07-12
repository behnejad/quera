package ir.nimbo;

public abstract class Drug {

    protected int basePrice;
    protected String name;
    protected boolean type;
    private int inventory;

    public Drug(int price, String name) {
        this.basePrice = price;
        this.name = name;
    }

    public abstract int getPrice();

    public int getBasePrice() {
        return basePrice;
    }

    public String getName() {
        return name;
    }

    public int getInventory() {
        return inventory;
    }

    public void setInventory(int inventory) {
        this.inventory = inventory;
    }

    public void consume(int count) {
        this.inventory -= count;
    }
}
