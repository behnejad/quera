import React from 'react';
import './App.css';
import { Layers } from './menu/Layers';
import { Board } from './board/Board';
import { State } from './menu/State';

function changeArrayIndex(arr, index, newItem) {
  return [...arr.slice(0, index), newItem, ...arr.slice(index + 1)];
}
class App extends React.Component {
  constructor(props) {
    super(props);
    const n = this.props.n;
    this.state = {
      n,
      board: JSON.parse(JSON.stringify(this.props.board)),
      currentLayer: 0,
      turn: 1 // turn is 1 or 2
    };
    console.log(this.state);
  }

  setCurrentLayer = i => {
    this.setState({ currentLayer: i });
  };

  isIndexInBoard = index => index >= 0 && index < this.state.n * this.state.n;
  isLayerInBoard = layer => layer >= 0 && layer < this.state.n;

  getAdjoiningIndexes = baseIndex => {
    const n = this.state.n;
    const adjoiningRows = [baseIndex - n, baseIndex, baseIndex + n].filter(
      this.isIndexInBoard
    );
    const adjoiningIndexes = adjoiningRows.flatMap(rowIndex => {
      if (rowIndex % n === 0) return [rowIndex, rowIndex + 1];
      else if (rowIndex % n === n - 1) return [rowIndex - 1, rowIndex];
      else return [rowIndex - 1, rowIndex, rowIndex + 1];
    });
    return adjoiningIndexes;
  };

  getBoardWithRoomOpened = (layer, index, board) => {
    const openingitem = board[layer][index];
    if (openingitem.visible) return board;

    const adjoiningIndexesInLayer = this.getAdjoiningIndexes(index);
    const adjoiningItems = [layer - 1, layer, layer + 1]
      .filter(this.isLayerInBoard)
      .flatMap(adjLayer => {
        return board[adjLayer].reduce(
          (adjItems, item, i) =>
            adjoiningIndexesInLayer.includes(i) && item !== openingitem
              ? [...adjItems, { ...item, layer: adjLayer, index: i }]
              : adjItems,
          []
        );
      })
      .filter(item => !item.visible);

    const newItem = { ...openingitem, visible: true };

    if (!openingitem.hasBomb) {
      let bombsNum = adjoiningItems.reduce(
        (bombsNum, aI) => (aI.hasBomb ? bombsNum + 1 : bombsNum),
        0
      );
      newItem.number = bombsNum;
    } else {
      newItem.owner = this.state.turn;
    }

    let newBoard = changeArrayIndex(
      board,
      layer,
      changeArrayIndex(board[layer], index, newItem)
    );

    if (newItem.number === 0) {
      adjoiningItems.forEach(item => {
        newBoard = this.getBoardWithRoomOpened(
          item.layer,
          item.index,
          newBoard
        );
      });
    }

    return newBoard;
  };

  handleRoomClick = (layer, index) => {
    const newBoard = this.getBoardWithRoomOpened(
      layer,
      index,
      this.state.board
    );
    this.setState({
      turn: this.state.turn === 1 ? 2 : 1,
      board: newBoard
    });
  };

  render() {
    return (
      <div className="game-container">
        <div className="game">
          <h1>MinRoob</h1>
          <State person={this.state.turn} turn />
          <Layers
            n={this.state.n}
            board={this.state.board}
            currentLayer={this.state.currentLayer}
            setCurrentLayer={index => {
              this.setCurrentLayer(index);
            }}
          />
          <Board
            n={this.state.n}
            board={this.state.board[this.state.currentLayer]}
            handleRoomClick={this.handleRoomClick}
            layer={this.state.currentLayer}
            type={'main'}
          />
        </div>
      </div>
    );
  }
}

export default App;
