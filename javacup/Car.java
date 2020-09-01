
public class Car {
	
	int weight; 
	String color;
	String name;

	public Car() {
		weight = 500;
		color = "White";
		name = "Fride";
	}

	public Car(String name) {
		this.name = name;
		weight = 500;
		color = "White";
	}

	public Car(String name, String color) {
		this.color = color;
		this.name = name;
		weight = 500;
	}
}
