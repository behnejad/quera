import java.util.Scanner;

public class special {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        boolean first = true;
//        String string = "Sir Daniel Michael Blake Day-Lewis (born 29 April 1957) is an English " +
//                "actor who holds both British and Irish citizenship. Born and raised in London, " +
//                "he excelled on stage at the National Youth Theatre, before being accepted at the Bristol Old Vic Theatre School, which he attended for three years.";
        for (String i : string.split(" ")) {
            if(first) {
                first = false;
                continue;
            }
            if (i.charAt(i.length() - 1) == '.' || i.charAt(i.length() - 1) == '?') {
                first = true;
            }
            if (i.length() >= 2 && Character.isUpperCase(i.charAt(0)) && Character.isAlphabetic(i.charAt(0))) {
                String res = i.replace("?", "")
                        .replace(".", "")
                        .replace(",", "")
                        .replace("!", "");
                System.out.println(res);
            }
        }
    }
}
