package ir.javacup.onlinetaxi;

public class VIPTripMethod implements TripMethod {
    @Override
    public int calcPrice(TripParam params) {
        int distance = DistanceMap.distance[params.getSource()][params.getDestination()] * 10000;
        if (params.isPeakTime() && params.isRainy()) {
            distance *= 3;
        } else if (params.isRainy()) {
            distance *= 2;
        } else if (params.isPeakTime()) {
            distance *= 2;
        }
        return distance;
    }
}
