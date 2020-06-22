public class Cube {
	public int[][][] coloring(int[][][] cube) {
		for (int i = 0; i < cube.length; ++i) {
			for (int j = 0; j < cube[i].length; ++j) {
				for (int k = 0; k < cube[i][j].length; ++k) {
					cube[i][j][k] = 0;
				}
			}
		}

		for (int j = 0; j < cube[0].length; ++j) {
			for (int k = 0; k < cube[0][j].length; ++k) {
				cube[0][j][k] = 1;
				cube[cube.length - 1][j][k] = 1;
			}
		}
		for (int j = 0; j < cube.length; ++j) {
			for (int k = 0; k < cube[j].length; ++k) {
				cube[j][k][0] = 1;
				cube[j][k][cube[j][k].length - 1] = 1;
			}
		}
		for (int j = 0; j < cube.length; ++j) {
			for (int k = 0; k < cube[j][0].length; ++k) {
				cube[j][0][k] = 1;
				cube[j][cube[j].length - 1][k] = 1;
			}
		}

		return cube;
	}
}
