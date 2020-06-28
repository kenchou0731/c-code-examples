#include <termios.h>
#include <stdio.h>

static struct termios old, current;

/* Initialize new terminal I/O settings */
void initTermios(void)
{
	tcgetattr(0, &old);
	current = old;
	current.c_lflag &= ~ICANON; /* disable buffered I/O */
	current.c_lflag &= ~ECHO; /* disable echo mode */
	tcsetattr(0, TCSANOW, &current);
}

/* Restore old terminal I/O settings */
void resetTermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

char getch(void)
{
	char ch;
	initTermios();
	ch = getchar();
	resetTermios();
	return ch;
}

int main(void)
{
	char c;

	printf("Please type a letter:\n");
	c = getch();
	printf("You typed: %c\n", c);
	return 0;
}
