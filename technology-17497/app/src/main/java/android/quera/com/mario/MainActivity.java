package android.quera.com.mario;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final Board board = new Board();
        findViewById(board.getSnakePositionID()).setBackgroundResource( R.color.snake_color);
        TextView up = (TextView) findViewById(R.id.up);
        TextView right = (TextView) findViewById(R.id.right);
        TextView down = (TextView) findViewById(R.id.down);
        TextView left = (TextView) findViewById(R.id.left);

        up.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (board.changePos(0)){
                    findViewById(board.getSnakePositionID()).setBackgroundResource( R.color.snake_color);
                    findViewById(board.getSnakePrevPositionID()).setBackgroundResource(R.color.default_background);
                    Log.d("num", "meow");
                }

            }
        });

        right.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (board.changePos(1)){
                    findViewById(board.getSnakePositionID()).setBackgroundResource( R.color.snake_color);
                    findViewById(board.getSnakePrevPositionID()).setBackgroundResource(R.color.default_background);
                }

            }
        });

        down.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (board.changePos(2)){
                    findViewById(board.getSnakePositionID()).setBackgroundResource( R.color.snake_color);
                    findViewById(board.getSnakePrevPositionID()).setBackgroundResource(R.color.default_background);
                }

            }
        });

        left.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (board.changePos(3)){
                    findViewById(board.getSnakePositionID()).setBackgroundResource( R.color.snake_color);
                    findViewById(board.getSnakePrevPositionID()).setBackgroundResource(R.color.default_background);
                }

            }
        });
    }
}
