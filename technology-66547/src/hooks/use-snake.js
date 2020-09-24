import { useState, useEffect } from 'react';
import { INIT_STATE, NORTH, EAST, SOUTH, WEST } from '../initialState';

export default function useSnake() {
  const [state, setState] = useState(INIT_STATE);
  const moveSnake = (x, y) => {
    switch(state.moves[0]) {
      case EAST:
        return {
          x: x + EAST.x,
          y: y + EAST.y
        }
      case WEST:
        return {
          x: x + WEST.x,
          y: y + WEST.y
        }
      case NORTH:
        return {
          x: x + NORTH.x,
          y: y + NORTH.y
        }
      case SOUTH:
        return {
          x: x + SOUTH.x,
          y: y + SOUTH.y
        }
    }
  }
  useEffect(() => {
    const interval = setInterval(() => {
			setState((previous) => {
        return {
          ...previous,
          snake: [moveSnake(previous.snake[0].x, previous.snake[0].y)]
        }
      })
		}, 100);
		return () => clearInterval(interval);
  }, []);
  document.addEventListener('keypress', () => {
    console.log(1)
  });
  return state;
}
