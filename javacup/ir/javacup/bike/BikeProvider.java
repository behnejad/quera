package ir.javacup.bike;

public interface BikeProvider {
	Bike provide();
	void repair(Bike bike);
}
