package ir.javacup.paint;


public class Square extends Shape {

	Integer length;

	public Square(Color c, Pattern p, int length) {
		super(c, p);
		this.length = length; // autoboxing

	}

	public boolean equals(Square obj) {
		if (obj == null) {
			return false;
		} else {
			return obj.length.equals(length) && obj.pattern.equals(pattern) && obj.color.equals(color);
		}
	}

	@Override
	public String toString() {
		return "Square[" + color + ", " + pattern + ", length:" + length + "]";
	}
}
