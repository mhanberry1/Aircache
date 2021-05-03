import { $ } from './common.js'
import websocket from './websockets.js'
import filereader from './filereader.js'

// Open websocket connection

websocket.connect()

// Apply event handlers

$('#fileInput').addEventListener('change', filereader.readFile)
