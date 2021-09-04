#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

const char *myfifo = "/tmp/client_to_server_fifo";
const char *myfifo2 = "/tmp/server_to_client_fifo";

int main(void) {
	int client_to_server;
	int server_to_client;
	char buf[BUFSIZ];

	setbuf(stdout, NULL);

	/* Create the FIFO (named pipe) */
	mkfifo(myfifo, 0666);
	mkfifo(myfifo2, 0666);

	/* Open, read, and display the message from the FIFO */
	client_to_server = open(myfifo, O_RDONLY);
	server_to_client = open(myfifo2, O_WRONLY);

	printf("Server started\n");

	while (1) {
		read(client_to_server, buf, BUFSIZ);

		if (!strcmp("exit", buf)) {
			printf("Server exited.\n");
			break;
		} else if (!strcmp("", buf)) {
			printf("Received: %s\n", buf);
			printf("Sending back...\n");
			write(server_to_client, buf, BUFSIZ);
		}

		/* clean buf from any data */
		memset(buf, 0, sizeof(buf));
	}

	close(client_to_server);
	close(server_to_client);

	unlink(myfifo);
	unlink(myfifo2);
	return 0;
}
