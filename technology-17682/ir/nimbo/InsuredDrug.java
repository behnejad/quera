package ir.nimbo;

public class InsuredDrug extends Drug {
    public InsuredDrug(int price, String name) {
        super(price, name);
        this.basePrice = price;
        this.name = name;
        this.type = true;
    }

    @Override
    public int getPrice() {
        return (int) (this.getBasePrice() * 0.7);
    }
}
