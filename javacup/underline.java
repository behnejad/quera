import java.util.Arrays;
import java.util.Scanner;

public class underline {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
//        int n = 3;

        if (n == 0) {
            return;
        }

        char [][] map = new char[3*n + 1][6*n + 1];

        for (int row = 0; row < map.length; ++row) {
            Arrays.fill(map[row], '_');
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 3*n + 1; ++j) {
                map[j][6*i] = '|';
            }
        }

        for (int i = 0; i <= n; ++i) {
            map[0][6*i] = ' ';
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 5; ++k) {
                    map[3*i + 1][6*j + k + 1] = ' ';
                    map[3*i + 2][6*j + k + 1] = ' ';
                }
            }
        }


        map[0][0] = ' ';
        map[0][6 * n] = ' ';

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) {
                    for (int k = 0; k < 5; ++k) {
                        map[3 * i + 2][6 * j + k + 1] = 'x';
                    }
                }
            }
        }

        for (char[] i : map) {
            System.out.println(i);
        }
    }

    /*
     *  _____ _____ _____
     * |     |     |     |
     * |     |XXXXX|     |
     * |_____|_____|_____|
     * |     |     |     |
     * |XXXXX|     |XXXXX|
     * |_____|_____|_____|
     * |     |     |     |
     * |     |XXXXX|     |
     * |_____|_____|_____|
     *
     */
}
