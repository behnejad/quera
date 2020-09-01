package ir.javacup.contest.zoo;

public class CageCopier {

	public void copy(Cage c1, Cage c2) {
		if (c1 != null && c2 != null) {
			c2.setName(c1.getName());
			c2.setId(c1.getId());
			if (c1.getBirds() == null) {
				c2.setBirds(null);
			} else {
				c2.setBirds(new Bird[2]);
				if (c1.getBirds()[0] != null) {
					c2.getBirds()[0] = new Bird();
					c2.getBirds()[0].setColor(c1.getBirds()[0].getColor());
					c2.getBirds()[0].setName(c1.getBirds()[0].getName());
				}
				if (c1.getBirds()[1] != null) {
					c2.getBirds()[1] = new Bird();
					c2.getBirds()[1].setColor(c1.getBirds()[1].getColor());
					c2.getBirds()[1].setName(c1.getBirds()[1].getName());
				}
			}
		}
	}
}
