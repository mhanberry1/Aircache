/*
	A basic server to manage incoming connections
*/

#include <stdio.h>
#include <string.h> // strlen
#include <stdlib.h> // free
#include <sys/socket.h>
#include <arpa/inet.h> // inet_addr
#include <unistd.h> // write

#include "dumbpipe.h" // handle_client_connection

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	int bufsize = 1024;
	char* buffer = malloc(bufsize);

	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		perror("Could not create socket");
	}
	
	// Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	// Bind
	if(bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0)
	{
		puts("Bind failed");
		return 1;
	}
	puts("Bind done");

	// Listen
	listen(socket_desc, 3);

	// Accept an incoming connection
	while(1){
		puts("Waiting for incoming connections...");
		c = sizeof(struct sockaddr_in);
		new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &c);
		if(new_socket < 0)
		{
			perror("accept failed");
			close(new_socket);
			continue;
		}

		puts("Connection accepted");

		// Reply to the client
		/* TODO: reply to each client in a separate thread */
		recv(new_socket, buffer, bufsize, 0);
		handle_client_connection(new_socket);
		close(new_socket);
	}

	// Close the socket
	close(socket_desc);

	return 0;
}
