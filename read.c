#include "shell.h"

/**
 * _read_line - read a line from stdin
 *
 * Description: read a line from stdin
 * Return: line from stdin
 */

char *_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t res;

	res = _getline(&line, &bufsize, STDIN_FILENO);
	if (res == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
