var state = 1;
function toggle_btn_img() {
	if (state) {
		document.getElementById('avatar').setAttribute('style', 'display:block !important');
		document.getElementById('btn').innerHTML = "Hide!";
		state = 0;
	} else {
		document.getElementById('avatar').setAttribute('style', 'display:none !important');
		document.getElementById('btn').innerHTML = "Show!";
		state = 1;
	}
}