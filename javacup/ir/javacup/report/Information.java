package ir.javacup.report;

public class Information {

	private String city;
	private String date;
	private long amount;
	
	public Information(String city, String date, long amount) {
		this.city = city;
		this.date = date;
		this.amount = amount;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public long getAmount() {
		return amount;
	}

	public void setAmount(long amount) {
		this.amount = amount;
	}

}
