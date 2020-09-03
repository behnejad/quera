import java.util.ArrayList;
import java.util.Arrays;

public class Ranker {

	class Pair {
		int index;
		double a;

		public Pair(int index, double a) {
			this.index = index;
			this.a = a;
		}
	}

	public int[] rank(String word, String[] documents) {
		ArrayList<Pair> a = new ArrayList<>();
		for (int i = 0; i < documents.length; ++i) {
			double sum = 0;
			double count = 0;
			String[] words = documents[i].split("\\.|\\?|!|,|\\s");
			for (String s : words) {
				if (s.length() == 0) {
					continue;
				}
				if (s.toLowerCase().equals(word.toLowerCase())) {
					++sum;
				}
				++count;
			}
			sum /= count;
			a.add(new Pair(i, sum));
		}

		a.sort((o1, o2) -> Double.compare(o2.a, o1.a));
		int[] r = new int[documents.length];
		for (int i = 0; i < documents.length; ++i) {
			r[i] = a.get(i).index;
		}
		return r;
	}

	public static void main(String args[]) {
		String[] documents = new String[6];
		documents[0] = "hola hi hello salam? hello."; 			// 1/5
		documents[1] = "hola hola hello,hello 	hi! hi."; 		// 0/6
		documents[2] = "salam salam hi! hola ...................  hello hello."; 	// 2/6
		documents[3] = "salam hi hola salam salam hi.";  		// 3/6
		documents[4] = "salam hi. hi! hi salam hi hola."; 		// 2/7
		documents[5] = "salam hi. hi! hi hi hi hola."; 			// 1/7
		int[] indexes = new Ranker().rank("salam", documents);
		System.out.println(Arrays.toString(indexes));
		// expected indexes: [3, 2, 4, 0, 5, 1]
	}

}
