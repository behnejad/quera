package ir.javacup.tictactoe;

public class Player {
	
	private IBoard board;
	private PlayerMark mark;

	public Player(IBoard board, PlayerMark mark) {
		this.board = board;
		this.mark = mark;
	}

	public boolean isWinner() {
		String mark = (this.mark == PlayerMark.X) ? "X" : "O";
		String[][] state = board.getState();
		for (int i = 0; i < 3; ++i) {
			if (state[i][0].equals(mark) && state[i][1].equals(mark) && state[i][2].equals(mark)) {
				return true;
			}
			if (state[0][i].equals(mark) && state[1][i].equals(mark) && state[2][i].equals(mark)) {
				return true;
			}
		}
		if (state[0][0].equals(mark) && state[1][1].equals(mark) && state[2][2].equals(mark)) {
			return true;
		}
		if (state[2][0].equals(mark) && state[1][1].equals(mark) && state[0][2].equals(mark)) {
			return true;
		}
		return false;
	}

	public BoardCell move() {
		String[][] state = board.getState();
		String mark = (this.mark == PlayerMark.X) ? "X" : "O";
		boolean is_full = true;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (state[i][j].equals("-")) {
					is_full = false;
				}
			}
		}

		if (is_full) {
			return null;
		}

		for (int i = 0; i < 3; ++i) {
			if (state[i][0].equals(mark) && state[i][1].equals(mark) && state[i][2].equals("-")) {
				return new BoardCell(i, 2);
			}
			if (state[i][0].equals(mark) && state[i][2].equals(mark) && state[i][1].equals("-")) {
				return new BoardCell(i, 1);
			}
			if (state[i][1].equals(mark) && state[i][2].equals(mark) && state[i][0].equals("-")) {
				return new BoardCell(i, 0);
			}
			if (state[0][i].equals(mark) && state[1][i].equals(mark) && state[2][i].equals("-")) {
				return new BoardCell(2, i);
			}
			if (state[0][i].equals(mark) && state[2][i].equals(mark) && state[1][i].equals("-")) {
				return new BoardCell(1, i);
			}
			if (state[1][i].equals(mark) && state[2][i].equals(mark) && state[0][i].equals("-")) {
				return new BoardCell(0, i);
			}
		}
		if (state[0][0].equals(mark) && state[1][1].equals(mark) && state[2][2].equals("-")) {
			return new BoardCell(2, 2);
		}
		if (state[1][1].equals(mark) && state[2][2].equals(mark) && state[0][0].equals("-")) {
			return new BoardCell(0, 0);
		}
		if (state[0][0].equals(mark) && state[2][2].equals(mark) && state[1][1].equals("-")) {
			return new BoardCell(1, 1);
		}
		if (state[2][0].equals(mark) && state[1][1].equals(mark) && state[0][2].equals("-")) {
			return new BoardCell(0, 2);
		}
		if (state[2][0].equals(mark) && state[0][2].equals(mark) && state[1][1].equals("-")) {
			return new BoardCell(1, 1);
		}
		if (state[0][2].equals(mark) && state[1][1].equals(mark) && state[2][0].equals("-")) {
			return new BoardCell(2, 0);
		}

		mark = (this.mark == PlayerMark.X) ? "O" : "X";
		for (int i = 0; i < 3; ++i) {
			if (state[i][0].equals(mark) && state[i][1].equals(mark) && state[i][2].equals("-")) {
				return new BoardCell(i, 2);
			}
			if (state[i][0].equals(mark) && state[i][2].equals(mark) && state[i][1].equals("-")) {
				return new BoardCell(i, 1);
			}
			if (state[i][1].equals(mark) && state[i][2].equals(mark) && state[i][0].equals("-")) {
				return new BoardCell(i, 0);
			}
			if (state[0][i].equals(mark) && state[1][i].equals(mark) && state[2][i].equals("-")) {
				return new BoardCell(2, i);
			}
			if (state[0][i].equals(mark) && state[2][i].equals(mark) && state[1][i].equals("-")) {
				return new BoardCell(1, i);
			}
			if (state[1][i].equals(mark) && state[2][i].equals(mark) && state[0][i].equals("-")) {
				return new BoardCell(0, i);
			}
		}
		if (state[0][0].equals(mark) && state[1][1].equals(mark) && state[2][2].equals("-")) {
			return new BoardCell(2, 2);
		}
		if (state[1][1].equals(mark) && state[2][2].equals(mark) && state[0][0].equals("-")) {
			return new BoardCell(0, 0);
		}
		if (state[0][0].equals(mark) && state[2][2].equals(mark) && state[1][1].equals("-")) {
			return new BoardCell(1, 1);
		}
		if (state[2][0].equals(mark) && state[1][1].equals(mark) && state[0][2].equals("-")) {
			return new BoardCell(0, 2);
		}
		if (state[2][0].equals(mark) && state[0][2].equals(mark) && state[1][1].equals("-")) {
			return new BoardCell(1, 1);
		}
		if (state[0][2].equals(mark) && state[1][1].equals(mark) && state[2][0].equals("-")) {
			return new BoardCell(2, 0);
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (state[i][j].equals("-")) {
					return new BoardCell(i, j);
				}
			}
		}

		return null;
	}

}
