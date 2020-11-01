import java.util.Scanner;

public class KeyBoard {
    private static final String numberMap = ")!@#$%^&*(";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] items = scanner.nextLine().split(" ");
        boolean caps = false;
        boolean shift = false;

        for (String i : items) {
            if (i.equals("CAPSLOCK")) {
                caps = !caps;
                continue;
            } else if (i.equals("shift_down")) {
                shift = true;
                continue;
            } else if (i.equals("shift_up")) {
                shift = false;
                continue;
            } else if (Character.isDigit(i.charAt(0))) {
                if (shift) {
                    System.out.print(numberMap.charAt(Integer.parseInt(i)));
                } else {
                    System.out.print(i);
                }
            } else if (!Character.isAlphabetic(i.charAt(0))) {
                if (shift) {
                    if (i.equals(",")) {
                        System.out.print("<");
                    } else if (i.equals(".")) {
                        System.out.print(">");
                    } else if (i.equals("/")) {
                        System.out.print("?");
                    } else if (i.equals(";")) {
                        System.out.print(":");
                    } else if (i.equals("'")) {
                        System.out.print("\"");
                    }
                } else {
                    System.out.print(i);
                }
            } else {
                if ((!caps && !shift) || (caps && shift)) {
                    System.out.print(i);
                } else {
                    System.out.print(i.toUpperCase());
                }
            }
            System.out.print(" ");
        }
    }
}
