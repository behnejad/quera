import java.util.Scanner;

public class Parallelogram {
	static boolean flag;
	static Scanner s = new Scanner(System.in);
	static int breadth, height;
	static {
		breadth = s.nextInt();
		height = s.nextInt();

		if (breadth <= 0 || height <= 0) {
			System.out.println("invalid");
		} else {
			System.out.println("valid");
			System.out.println(breadth * height);
		}
	}

	public static void main(String[] args) { //don't change main body
		if (flag) {
			int area = breadth * height;
			System.out.print(area);
		}
	}
}
