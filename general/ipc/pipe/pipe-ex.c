#include <stdio.h>
#include <unistd.h>
 
/* since pipes are unidirectional, we need two pipes.
 * one for data to flow from parent's stdout to child's
 * stdin and the other for child's stdout to flow to
 * parent's stdin
 */
#define PARENT_TO_CHILD 0
#define CHILD_TO_PARENT 1
 
int pipes[2][2];
 
/* always in a pipe[], pipe[0] is for read and pipe[1] is for write */
#define READ_FD  0
#define WRITE_FD 1
 
#define PARENT_READ_FD  ( pipes[CHILD_TO_PARENT][READ_FD] )
#define PARENT_WRITE_FD ( pipes[PARENT_TO_CHILD][WRITE_FD] )
#define CHILD_READ_FD   ( pipes[PARENT_TO_CHILD][READ_FD] )
#define CHILD_WRITE_FD  ( pipes[CHILD_TO_PARENT][WRITE_FD] )
 
int main(void) {
	pid_t pid;
	 
	/* Create pipes for parent to write and read */
	pipe(pipes[CHILD_TO_PARENT]);
	pipe(pipes[PARENT_TO_CHILD]);
	
	pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
	} else if (pid == 0) {
		char *argv[]={ "/usr/bin/bc", "-q", 0};
 
		dup2(CHILD_READ_FD, STDIN_FILENO);
		dup2(CHILD_WRITE_FD, STDOUT_FILENO);
 
		/* 
         * Close fds not required by child. Also, we don't
		 * want the exec'ed program to know these existed
         */
		close(CHILD_READ_FD);
		close(CHILD_WRITE_FD);
		close(PARENT_READ_FD);
		close(PARENT_WRITE_FD);
		  
		execv(argv[0], argv);
	} else {
		char buffer[100];
		int count;
 
		/* close fds not required by parent */	   
		close(CHILD_READ_FD);
		close(CHILD_WRITE_FD);
 
		/* Write to child’s stdin */
		write(PARENT_WRITE_FD, "2^32\n", 5);
  
        /* Read from child’s stdout */
		count = read(PARENT_READ_FD, buffer, sizeof(buffer) - 1);
		if (count >= 0) {
			buffer[count] = 0;
			printf("Result: %s\n", buffer);
		} else {
			printf("read error\n");
		}
	}
    return 0;
}