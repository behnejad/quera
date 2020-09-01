package ir.javacup.paint;


public class Shape {
	Color color;
	Pattern pattern;

	public Shape(Color c, Pattern p) {
		this.color = c;
		this.pattern = p;
	}
}

enum Color {
	BLUE("BLUE"),
	GREEN("GREEN"),
	RED("RED");
	String name;
	Color(String name) {
		this.name = name;
	}
	@Override
	public String toString() {
		return "color:" + name;
	}
}

enum Pattern {
	DOTTED("DOTTED"),
	STRIPED("STRIPED"),
	ZIGZAG("ZIGZAG");
	String name;
	Pattern(String name) {
		this.name = name;
	}
	@Override
	public String toString() {
		return "pattern:" + name;
	}
}
