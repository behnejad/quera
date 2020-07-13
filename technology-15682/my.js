var move = 1;
function moveUp(element) {
  var elStyle = window.getComputedStyle(element);
  var topValue = elStyle.getPropertyValue("top").replace("px", "");
  element.style.top = (Number(topValue) - move) + "px";
}

function moveRight(element) {
  var elStyle = window.getComputedStyle(element);
  var leftValue = elStyle.getPropertyValue("left").replace("px", "");
  element.style.left = (Number(leftValue) + move) + "px";
}

function moveLeft(element) {
  var elStyle = window.getComputedStyle(element);
  var leftValue = elStyle.getPropertyValue("left").replace("px", "");
  element.style.left = (Number(leftValue) - move) + "px";
}

function moveDown(element) {
  var elStyle = window.getComputedStyle(element);
  var topValue = elStyle.getPropertyValue("top").replace("px", "");
  element.style.top = (Number(topValue) + move) + "px";
}

document.onkeydown = function(e) {
    if (e.repeat == false) {
        if (e.shiftKey == true) {
            move = 10;
        } else {
            move = 1;
        }
        var w = document.getElementById("square");
        switch(e.which) {
            case 37: // left
                moveLeft(w);
            break;
            case 38: // up
                moveUp(w);
            break;
            case 39: // right
                moveRight(w);
            break;
            case 40: // down
                moveDown(w);
            break;
            default: return;
        }
    }
    e.preventDefault();
};