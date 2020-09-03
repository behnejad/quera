package ir.javacup.bike;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class BikeStore {

	private BikeProvider provider;
	private Clock clock;
	private long expireTime;

	private HashMap<Bike, BikeFeature> repo = new HashMap<>();

	class BikeFeature {
		long barrow_time;
		boolean need_repair;
		boolean has_return = true;

		public BikeFeature(long barrow_time, boolean need_repair) {
			this.barrow_time = barrow_time;
			this.need_repair = need_repair;
		}

		public boolean has_end(long current) {
			return current > (barrow_time + expireTime);
		}
	}

	public BikeStore(BikeProvider provider, Clock clock, long expireTime) {
		this.provider = provider;
		this.clock = clock;
		this.expireTime = expireTime;
	}

	public Bike borrow() {
		long current_time = clock.getCurrentTime();
		for (Map.Entry<Bike, BikeFeature> b : repo.entrySet()) {
			BikeFeature value = b.getValue();
			if (value.has_return) {
				if (value.need_repair) {
					provider.repair(b.getKey());
					value.need_repair = false;
					repo.put(b.getKey(), value);
				} else {
					value.has_return = false;
					value.barrow_time = current_time;
					repo.put(b.getKey(), value);
					return b.getKey();
				}
			}
		}

		for (Map.Entry<Bike, BikeFeature> b : repo.entrySet()) {
			BikeFeature value = b.getValue();
			if (!value.has_return) {
				if (value.has_end(current_time)) {
					value.barrow_time = current_time;
					repo.put(b.getKey(), value);
					return b.getKey();
				}
			}
		}

		Bike provide = provider.provide();
		BikeFeature bikeFeature = new BikeFeature(current_time, false);
		bikeFeature.has_return = false;
		repo.put(provide, bikeFeature);
		return provide;
	}

	public void restore(Bike bike, boolean needsRepair) {
		if (!repo.containsKey(bike)) {
			throw new RuntimeException();
		}

		BikeFeature bikeFeature = repo.get(bike);
		bikeFeature.has_return = true;
		bikeFeature.need_repair = needsRepair;
		repo.put(bike, bikeFeature);
	}

	public int borrowedCount() {
		int c = 0;
		for (Map.Entry<Bike, BikeFeature> b : repo.entrySet()) {
			if (!b.getValue().has_return) {
				++c;
			}
		}
		return c;
	}
}
