

import java.util.List;
import java.util.function.Supplier;

public class Functions {

	List<Supplier<?>> fs;
	List<Supplier<?>> gs;
	List<Supplier<?>> hs;

	public Functions(List<Supplier<?>> fs, List<Supplier<?>> gs, List<Supplier<?>> hs) {
		this.fs = fs;
		this.gs = gs;
		this.hs = hs;
	}


}
