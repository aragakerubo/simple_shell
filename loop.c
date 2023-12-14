#include "shell.h"

/**
 * _loop - loop for shell.
 *
 * Description: loop for shell.
 * Return: void.
 */
void _loop(void)
{
	char *input;
	char **args;
	int status;
	int inter = 1, len;

	if (isatty(STDIN_FILENO) != 1)
		inter = 0;

	signal(SIGINT, sigint_handler);

	do {
		if (inter != 0)
		{
			len = _strlen("$ ");
			write(STDOUT_FILENO, "$ ", len);
		}

		input = _read_line();
		if (input == NULL)
			return;

		args = _split_line(input);
		if (args == NULL)
		{
			free(input);
			return;
		}
		status = _execute(args, input);

		free(input);
		free(args);

	} while (status == 1);
}
