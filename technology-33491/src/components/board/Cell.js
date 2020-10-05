import React from 'react';
import { CELL_SIZE, CELL_MARGIN } from '../../constants';
import './Cell.css';

export class Cell extends React.PureComponent {
  render() {
    const { cell } = this.props;
    const classNames = ['cell'];
    if (!cell.visible) {
      classNames.push('unknown');
    } else if (Number.isInteger(cell.number)) {
      classNames.push('number');
      classNames.push(`number-${cell.number}`);
    } else if (cell.hasBomb) {
      classNames.push('bomb');
    }
    return (
      <div
        onClick={this.props.openRoom}
        className={classNames.join(' ')}
        style={{
          width: CELL_SIZE - CELL_MARGIN,
          height: CELL_SIZE - CELL_MARGIN,
          margin: CELL_MARGIN / 2
        }}>
        {cell.number}
      </div>
    );
  }
}
