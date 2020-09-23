package android.quera.com.mario;

public class Board {

    final int[][] buttonID = new int[6][6];
    int snakeX, snakeY;
    int prevX, prevY;

    public Board(){
        initializeButtonID();
        snakeX = 3;
        snakeY = 3;
    }

    public boolean changePos(int i) {
        prevX = snakeX;
        prevY = snakeY;
        /**
         * 0: up
         * 1: right
         * 2: down
         * 3: left
         */
        switch (i) {
            case 0:
                if (snakeY != 1) {
                    snakeY--;
                    return true;
                }
                break;
            case 1:
                if (snakeX != 6) {
                    snakeX++;
                    return true;
                }
                break;
            case 2:
                if (snakeY != 6) {
                    snakeY++;
                    return true;
                }
                break;
            case 3:
                if (snakeX != 1) {
                    snakeX--;
                    return true;
                }
                break;

        }
        return false;
    }

    public void initializeButtonID(){
        buttonID[0][0] = R.id.one_one;
        buttonID[0][1] = R.id.one_two;
        buttonID[0][2] = R.id.one_three;
        buttonID[0][3] = R.id.one_four;
        buttonID[0][4] = R.id.one_five;
        buttonID[0][5] = R.id.one_six;
        buttonID[1][0] = R.id.two_one;
        buttonID[1][1] = R.id.two_two;
        buttonID[1][2] = R.id.two_three;
        buttonID[1][3] = R.id.two_four;
        buttonID[1][4] = R.id.two_five;
        buttonID[1][5] = R.id.two_six;
        buttonID[2][0] = R.id.three_one;
        buttonID[2][1] = R.id.three_two;
        buttonID[2][2] = R.id.three_three;
        buttonID[2][3] = R.id.three_four;
        buttonID[2][4] = R.id.three_five;
        buttonID[2][5] = R.id.three_six;
        buttonID[3][0] = R.id.four_one;
        buttonID[3][1] = R.id.four_two;
        buttonID[3][2] = R.id.four_three;
        buttonID[3][3] = R.id.four_four;
        buttonID[3][4] = R.id.four_five;
        buttonID[3][5] = R.id.four_six;
        buttonID[4][0] = R.id.five_one;
        buttonID[4][1] = R.id.five_two;
        buttonID[4][2] = R.id.five_three;
        buttonID[4][3] = R.id.five_four;
        buttonID[4][4] = R.id.five_five;
        buttonID[4][5] = R.id.five_six;
        buttonID[5][0] = R.id.six_one;
        buttonID[5][1] = R.id.six_two;
        buttonID[5][2] = R.id.six_three;
        buttonID[5][3] = R.id.six_four;
        buttonID[5][4] = R.id.six_five;
        buttonID[5][5] = R.id.six_six;

    }

    public int getSnakePositionID(){
        return buttonID[snakeY -1][snakeX-1];
    }

    public int getSnakePrevPositionID(){
        return buttonID[prevY -1][prevX-1];
    }
}
