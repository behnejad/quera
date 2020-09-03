package ir.javacup.onlinetaxi;

public class BikeTripMethod implements TripMethod {
    @Override
    public int calcPrice(TripParam params) {
        int distance = DistanceMap.distance[params.getSource()][params.getDestination()] * 4000;
        if (params.isPeakTime() && params.isRainy()) {
            distance *= 1.5;
        } else if (params.isRainy()) {
            distance *= 0.8;
        } else if (params.isPeakTime()) {
            distance *= 2;
        }
        return distance;
    }
}
