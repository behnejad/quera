var xhttp = new XMLHttpRequest();
function reqListener () {
	var t = JSON.parse(this.responseText);
	document.getElementById("likes").innerHTML = t.count;
}
var oReq = new XMLHttpRequest();
oReq.addEventListener("load", reqListener);
oReq.open("GET", "/count.json");
oReq.send();