package ir.javacup.accounting;

public class Cost {

	private int price;
	private String name;

	public Cost(int price, String name) {
		this.price = price;
		this.name = name;
	}

	public int getAmount() {
		return price;
	}

	public String getName() {
		return name;
	}

	@Override
	public String toString() {
		return "[name= " + name + " ,price= " + price + "]";
	}

}
