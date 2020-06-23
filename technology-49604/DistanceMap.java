public class DistanceMap {

    private static int[][] map = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0, 0},
            {1, 1, 1, 1, 1, 0},
    };

    private DistanceMap() {
    }

    public static int getCityCount() {
        return map.length;
    }

    public static int getDistance(int i, int j) {
        return map[i][j];
    }

    public static void setMap(int[][] map) {
        DistanceMap.map = map;
    }

}
