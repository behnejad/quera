package ir.javacup.accounting;

public class Health extends Cost {
	
	private int priority;

	public Health(int cost, int priority, String name) {
		super(cost, name);
		this.priority = priority;
	}

	public int getPriority() {
		return priority;
	}

	
}
