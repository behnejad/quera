public class CompleteNumber {
    public static boolean check(int i) {
        int res = 0;
        int sqrt = (int) Math.sqrt(i);
        for (int j = 1; j <= sqrt; ++j) {
            if (i % j == 0) {
                res += j;
                int k = i / j;
                if (k != 1 && k != i) {
                    res += k;
                }
            }
        }

        return i == res;
    }
    public static void main(String[] args) {
        for (int i = 2; i <= 100000; ++i) {
            if (check(i)) {
                System.out.println(i);
            }
        }
    }
}
