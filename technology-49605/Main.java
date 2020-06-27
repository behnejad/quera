import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        String text1 = "Hello (spam) Java";
        String text2 = "$#a@5 spam)--(*^";
        String id1 = "@first-user1999";
        String id2 = "190482184";

        SpamDetector detector = new SpamDetector();
        Message[] messages = {new Message(text1, id2), new Message(text2, id1)};
        SpamType[] results = detector.detectSpams(messages);
        System.out.println(Arrays.toString(results));
    }

}
