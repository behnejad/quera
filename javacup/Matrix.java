public class Matrix {
	private int row;
	private int column;
	private int[][] elements;

	public Matrix(int row, int column) {
		this.row = row;
		this.column = column;
		elements = new int[row][column];
	}
	
	public Matrix(int length){
		this(length, length);
	}
	
	public Matrix(int[][] elements){
		this.elements = elements;
		this.row = elements.length;
		this.column = elements[0].length;
	}
	
	public int getRow() {
		return row;
	}

	public int getColumn() {
		return column;
	}

	public int[][] getElements() {
		return elements;
	}

	public boolean add(Matrix newMatrix) {
		if (newMatrix.row == this.row && newMatrix.column == this.column) {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < column; ++j) {
					elements[i][j] += newMatrix.elements[i][j];
				}
			}
			return true;
		} else {
			return false;
		}
	}
	
	public void setElement(int i, int j, int value){
		elements[i][j] = value;
	}

	public boolean isSquareMatrix() {
		return row == column;
	}

	public void toLowerTriangular() {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				if (j > i) {
					elements[i][j] = 0;
				}
			}
		}
	}

	public void toUpperTriangular() {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				if (i > j) {
					elements[i][j] = 0;
				}
			}
		}
	}
}
