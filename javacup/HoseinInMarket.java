import java.util.Scanner;

public class HoseinInMarket {
    public static void main(String[] args) {
        Scanner i = new Scanner(System.in);
        int n = i.nextInt();
        int last = 0;
        while (n != 0) {
            last += i.nextInt();
            for (int j = 0; j < last; ++j) {
                System.out.print("*");
            }
            System.out.println();

            --n;
        }
    }
}
