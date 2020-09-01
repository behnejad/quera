package ir.javacup.salary;

import java.util.Locale;

public abstract class SalaryListCreator {

	protected Encoder encoder;
	
	public SalaryListCreator(Encoder encoder) {
		this.encoder = encoder;
	}

	public String create(Employee[] employees) {
		String rawStr = doCreate(employees);
		return encoder.encode(rawStr);
	}
	
	protected abstract String doCreate(Employee[] employees);
	
	protected static String addZeroPrefix(String str, int length) {
		String a = str;
		for (int i = 0; i < (length - str.length()); ++i) {
			a = "0" + a;
		}
		return a;
	}
	
	protected String getRecordSeparator() {
		return System.lineSeparator();
	}
	
	protected String getItemSeparator() {
		return " ";
	}
}
