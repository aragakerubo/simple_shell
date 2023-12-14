#include "shell.h"

/**
 * sigint_handler - handles the signal ctrl + c.
 * @sig: signal.
 */
void sigint_handler(int sig)
{
	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
