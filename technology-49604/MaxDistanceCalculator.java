import java.util.ArrayList;
import java.util.Collections;

public class MaxDistanceCalculator {

    public static void main(String[] args) {
        int max = -1;
        ArrayList<Integer> id = new ArrayList<>();
        for (int i = 0; i < DistanceMap.getCityCount(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (max < DistanceMap.getDistance(i, j)) {
                    max = DistanceMap.getDistance(i, j);
                }
            }
        }
        for (int i = 0; i < DistanceMap.getCityCount(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (max == DistanceMap.getDistance(i, j)) {
                    id.add(i);
                }
            }
        }
        int first = id.get(0);
        for (int i = 0; i < DistanceMap.getCityCount(); ++i) {
            if (DistanceMap.getDistance(first, i) == max) {
                System.out.println((first + 1) + "," + (i + 1));
                break;
            }
        }
    }
}
