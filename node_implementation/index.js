import websocket from 'ws';

const {Server : WebSocketServer} = websocket;

let connection_map = {};

class AircacheServer {
	constructor(options){
		this.port = options.port || 8080;
	}

	start(){
		const server = new WebSocketServer({port : this.port});
		
		server.on('connection', connection => {
			connection.on('message', message => {
				let {block, } = JSON.parse(message);
				let message_is_valid = (
					recipient &&
					block &&
					Number.isInteger(block.index) && block.index >= 0 &&
					block.data
				);
				let response = JSON.stringify({
					aircache_status : message_is_valid ? 200 : 400,
					block_index : block.index
				});

				connection.send(response);
			});

		});

		console.log(`${new Date()}: server started on port ${this.port}`);
	}
}

export default AircacheServer;
