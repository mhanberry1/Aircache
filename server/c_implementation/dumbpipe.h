void handle_client_connection(int client_socket){
	int num_headers = 3;
	char* protocol = "HTTP/1.1";
	char* status = "200 OK";
	char* headers[] = {
		"Date: Mon, 24 Aug 2020 03:11:00 PST",
		"Server: Aircache 1.0 (Linux64)",
		"Content-Type: text/html; charset=utf-8"
	};
	char* body = "This is a generic response. More implementation is necessary.";

	// Calculate the total size of all the headers
	int header_size = 0;
	for(int i = 0; i < num_headers; i++){
		int j = 0;
		while(++header_size && headers[i][j] != '\0' && ++j);
	}

	// Construct the message
	int message_size = strlen(protocol) + strlen(status) + header_size + num_headers + strlen(body) + 2;
	char message[message_size];
	strcpy(message, protocol); strcat(message, " ");
	strcat(message, status); strcat(message, "\n");
	for(int i = 0; i < num_headers; i++){
		strcat(message, headers[i]); strcat(message, "\n");
	}
	strcat(message, body);

	write(client_socket, message, message_size);

	//free((void*)(intptr_t)client_socket);
}
