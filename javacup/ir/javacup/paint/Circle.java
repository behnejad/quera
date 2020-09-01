package ir.javacup.paint;

public class Circle extends Shape {
	Double radius;

	public Circle(Color c, Pattern p, double r) {
		super(c, p);
		this.radius = r;
	}

	public boolean equals(Circle obj) {
		if (obj == null) {
			return false;
		} else {
			return obj.radius.equals(radius) && obj.pattern.equals(pattern) && obj.color.equals(color);
		}
	}

	@Override
	public String toString() {
		return "Circle[" + color + ", " + pattern + ", radius:" + radius.intValue() + "]";
	}

	public static void main(String[] args) {
		System.out.println(new Circle(Color.BLUE, Pattern.DOTTED, 10));
	}
}
