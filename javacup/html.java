import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class html {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String html = scanner.nextLine();
//        String html = "<tr>\n" +
//                "<td class=\"t\">Sum</td>\n" +
//                "<td>4,220 of 8,090</td>\n" +
//                "<td class=\"c\">47%</td>\n" +
//                "<td class=\"b\">240 of 546</td>\n" +
//                "<td class=\"c\">56%</td>\n" +
//                "<td class=\"c\">555</td>\n" +
//                "<td class=\"c\">993</td>\n" +
//                "<td class=\"c\">1,155</td>\n" +
//                "<td class=\"c\">2,188</td>\n" +
//                "<td class=\"c\">418</td>\n" +
//                "<td class=\"c\">720</td>\n" +
//                "<td class=\"c\">35</td>\n" +
//                "<td class=\"c\">85</td>\n" +
//                "</tr>";
        int index = html.indexOf("Sum</td>");
        if (index < 0) {
            return;
        }
        int lastIndex = html.indexOf("</tr>", index);


        Pattern pattern = Pattern.compile("<td.*>(.*)</td>", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(html.substring(index, lastIndex));
        while (matcher.find()) {
            if (matcher.group(1).contains("%")) {
                System.out.print(matcher.group(1));
                System.out.print(" ");
            }
        }


    }

}
