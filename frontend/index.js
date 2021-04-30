const serverAddress = 'ws://localhost:8080'
const socket = new WebSocket(serverAddress)

socket.onopen = function(event) {
   console.log("Connection established");
   // Display user friendly messages for the successful establishment of connection
   const label = document.getElementById("status");
   label.innerHTML = "Connection established";
}
