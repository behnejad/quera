import React from 'react';
import { Cell } from './Cell';
import { CELL_MARGIN, CELL_SIZE } from '../../constants';
import './Board.css';

export class Board extends React.PureComponent {
  render() {
    const { n, board, type, layer, className } = this.props;

    const style = {
      width: n * CELL_SIZE,
      height: n * CELL_SIZE,
      padding: CELL_MARGIN / 2
    };
    if (type === 'mini') {
      style.transform = `scale(${(CELL_SIZE - CELL_MARGIN) / (CELL_SIZE * n)})`;
      style.marginLeft = (-(n - 1) / 2) * CELL_SIZE - CELL_MARGIN / 2;
      style.marginTop = (-(n - 1) / 2) * CELL_SIZE - CELL_MARGIN / 2;
    }

    return (
      <div className={`board ${className || ''}`} style={style}>
        {type === 'mini' ? <div className={'layerMask'}>{layer}</div> : <></>}
        {board.map((cell, index) => (
          <Cell
            openRoom={() => {
              this.props.handleRoomClick &&
                this.props.handleRoomClick(layer, index);
            }}
            key={index}
            cell={cell}
          />
        ))}
      </div>
    );
  }
}
