package ir.javacup.shop;

public abstract class Clothing {

	private String name;
	private Season season;
	private long basePrice;
	DiscountStrategy discountStrategy;
	
	public Clothing(String name, Season season, long basePrice) {
		this.name = name;
		this.season = season;
		this.basePrice = basePrice;
	}

	public long getPrice() {
		if (discountStrategy == null) {
			return basePrice;
		}
		return discountStrategy.priceByDiscount(this);
	}
	
	public void setDiscountStrategy(DiscountStrategy discountStrategy) {
		this.discountStrategy = discountStrategy;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Season getSeason() {
		return season;
	}

	public void setSeason(Season season) {
		this.season = season;
	}

	public long getBasePrice() {
		return basePrice;
	}

	public void setBasePrice(long basePrice) {
		this.basePrice = basePrice;
	}
	

}
