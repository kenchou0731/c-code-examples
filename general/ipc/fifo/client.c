#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char *myfifo = "/tmp/client_to_server_fifo";
const char *myfifo2 = "/tmp/server_to_client_fifo";

int main(void) {
	int client_to_server;
	int server_to_client;
	char str[BUFSIZ];

	printf("Input message to serwer: ");
	scanf("%s", str);

	/* write str to the FIFO */
	client_to_server = open(myfifo, O_WRONLY);
	server_to_client = open(myfifo2, O_RDONLY);

	write(client_to_server, str, sizeof(str));
	perror("Write:");

	read(server_to_client, str, sizeof(str));
	perror("Read:");

	printf("Received from the server: %s\n", str);

   close(client_to_server);
   close(server_to_client);
	return 0;
}
