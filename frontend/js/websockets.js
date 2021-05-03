import { $ } from './common.js'
import config from './config.js'

// Connect to the websocket server
function connect () {
	const socket = new WebSocket(config.serverAddress)

	socket.onopen = function(event) {
	   const label = $('#status');
	   label.innerHTML = 'Connection established';
	}
}

export default { connect }
