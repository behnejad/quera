package ir.javacup.onlinetaxi;

public class EconomicTripMethod implements TripMethod {
    @Override
    public int calcPrice(TripParam params) {
        int distance = DistanceMap.distance[params.getSource()][params.getDestination()] * 5000;
        if (params.isPeakTime() && params.isRainy()) {
            distance *= 1.4;
        } else if (params.isRainy()) {
            distance *= 1.2;
        } else if (params.isPeakTime()) {
            distance *= 1.2;
        }
        return distance;
    }
}
