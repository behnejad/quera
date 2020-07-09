
import java.util.Arrays;
import java.util.List;
import java.util.function.Supplier;

public class Main {
	
	public static void main(String[] args) throws Exception {
		Supplier<?> f1 = () -> {print("F1"); return null;};
		Supplier<?> f2 = () -> {print("F2"); return null;};
		Supplier<?> f3 = () -> {print("F3"); return null;};
		Supplier<?> f4 = () -> {print("F4"); return null;};
		List<Supplier<?>> fs = Arrays.asList(f1, f2, f3, f4);
		
		Supplier<?> g1 = () -> {print("G1"); return null;};
		Supplier<?> g2 = () -> {print("G2"); return null;};
		List<Supplier<?>> gs = Arrays.asList(g1, g2);
		
		Supplier<?> h1 = () -> {print("H1"); return null;};
		List<Supplier<?>> hs = Arrays.asList(h1);
		
		ThreadSolution p = new ThreadSolution();
		p.solve(new Functions(fs, gs, hs));
	}

	private static void print(String label) {
		System.out.print(label + " by " + Thread.currentThread().toString() + " - ");
	}

}
