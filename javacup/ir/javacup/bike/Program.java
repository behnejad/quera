package ir.javacup.bike;

import java.util.UUID;

public class Program {
	
	public static void main(String[] args) {
		BikeProvider dummyProvider = new BikeProvider() {
			@Override
			public void repair(Bike bike) {
				// repair implementation
			}
			@Override
			public Bike provide() {
				return new Bike(UUID.randomUUID().toString(), "bike");
			}
		};
		Clock dummyClock = new Clock() {
			long time = 100;
			@Override
			public long getCurrentTime() {
				return time;
			}
		};
		
		BikeStore bikeStore = new BikeStore(dummyProvider, dummyClock, 1000);
		
		Bike bike1 = bikeStore.borrow();
		Bike bike2 = bikeStore.borrow();
		System.out.println(bikeStore.borrowedCount());
		System.out.println(bike1.equals(bike2));
		
		bikeStore.restore(bike1, false);
		System.out.println(bikeStore.borrowedCount());
		Bike bike3 = bikeStore.borrow();
		System.out.println(bike1.equals(bike3));
		
		bikeStore.restore(bike2, true); // needs repair
		Bike bike4 = bikeStore.borrow();
		System.out.println(bike4.equals(bike2));
		Bike bike5 = bikeStore.borrow();
		System.out.println(bike5.equals(bike2));
		System.out.println(bikeStore.borrowedCount());
	}
	
}
