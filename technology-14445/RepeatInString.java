public class RepeatInString {
    public int StringInString(String one, String two) {
        if (one == null || one.length() == 0 || two == null || two.length() == 0) {
            return 0;
        }
        int count = 0;
        int index = one.indexOf(two);
        while (index >= 0) {
            ++count;
            index = one.indexOf(two, index + 1);
        }

        return count;
    }
}