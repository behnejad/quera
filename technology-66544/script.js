const statusDisplay = document.querySelector('.game--status');

let currentPlayer = 'X';
let gameState = ['', '', '', '', '', '', '', '', ''];
let gameActive = true;
const winConditions = [
  [0, 4, 8],
  [0, 1, 2],
  [6, 7, 8],
  [2, 5, 8],
  [0, 3, 6],
  [2, 4, 6],
  [3, 4, 5],
  [1, 4, 7]
];

const currentPlayerTurn = () => `It's ${currentPlayer}'s turn`;

statusDisplay.innerHTML = currentPlayerTurn();

function handleCellPlayed(clickedCell, clickedCellIndex) {
  gameState[clickedCellIndex] = currentPlayer;
  clickedCell.innerHTML = currentPlayer;
}

function handlePlayerChange() {
  currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
  statusDisplay.innerHTML = currentPlayerTurn();
}

function handleFinishGame() {
  let win = false;
  for (let condition of winConditions) {
    const first = gameState[condition[0]];
    const second = gameState[condition[1]];
    const third = gameState[condition[2]];
    if (first === '' || second === '' || third === '') continue
    else if (first === second && second === third) {
      win = true;
      break
    }
  }
  if (win) {
    statusDisplay.innerHTML = `Player ${currentPlayer} has won`;
    gameActive = false;
    return true;
  } 

  let draw = 0;
  for (let i of gameState) {
    if (i === '') draw += 1
  }
  if (draw === 0) {
    statusDisplay.innerHTML = `Game ended in a draw`;
    gameActive = false;
    return true;
  }
}

function handleCellClick(clickedCellEvent) {
  if (gameActive) {
    const clickedCell = clickedCellEvent.target;
    const clickedCellIndex = parseInt(
      clickedCell.getAttribute('data-cell-index')
    );
  
    if (gameState[clickedCellIndex] !== '') {
      return;
    }
  
    handleCellPlayed(clickedCell, clickedCellIndex);
    if (handleFinishGame()) {
  
    } else {
      handlePlayerChange();
    }
  }
}

function handleRestartGame() {
  currentPlayer = 'X';
  gameState = ['', '', '', '', '', '', '', '', ''];
  statusDisplay.innerHTML = currentPlayerTurn();
  document.querySelectorAll('.cell').forEach(cell => (cell.innerHTML = ''));
  gameActive = true;
}

document
  .querySelectorAll('.cell')
  .forEach(cell => cell.addEventListener('click', handleCellClick));
document
  .querySelector('.game--restart')
  .addEventListener('click', handleRestartGame);
