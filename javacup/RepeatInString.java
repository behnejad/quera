public class RepeatInString {
	public int StringInString(String one, String two) {
		if (one == null || two == null || one.length() == 0 || two.length() == 0)
			return 0;
		int c = 0;
		for (int i = 0 ; i < one.length(); ++i) {
			int i1 = one.indexOf(two, i);
			if (i1 == i) {
				++c;
			}
		}
		return c;
	}

	public static void main(String[] args) {
		System.out.println(new RepeatInString().StringInString("11", "1"));
		System.out.println(new RepeatInString().StringInString("sasasas", "sas"));
	}
}