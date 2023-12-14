#include "shell.h"

/**
 * alloc_error - allocation error
 * @buffer: buffer to check
 *
 * Description: allocation error
 * Return: -1 if error, 0 if successfull.
 */
int alloc_error(char *buffer)
{
	if (!buffer)
	{
		perror("shell: allocation error\n");
		return (-1);
	}
	else
		return (0);
}

/**
 * _getline - Read a line from stdin.
 *
 * @line: Pointer to the line.
 * @n: Size of the line.
 * @stream: Pointer to the stream.
 *
 * Description: Read a line from stdin.
 * Return: Number of characters read.
 */
ssize_t _getline(char **line, size_t *n,
		 __attribute__((unused)) FILE * stream)
{
	size_t bufsize = 1024, index = 0;
	int c, f = 0;
	char *buffer;

	if (*n == 0)
		bufsize = 1024;
	buffer = malloc(sizeof(char) * (bufsize));
	if (alloc_error(buffer) == -1)
		return (-1);
	*line = buffer;
	while (1)
	{
		fflush(stdout);
		c = _getc();
		if (c == EOF || c == '\n')
		{
			*(buffer + index) = '\0';
			if (c == EOF)
				return (-1);
			else
				return (index + 1);
		}
		else if (c == ' ')
		{
			if (f == 0)
			{
				f = 1;
				*(buffer + index) = c;
				index++;
			}
		}
		else
		{
			f = 0;
			*(buffer + index) = c;
			index++;
		}
		if (index >= bufsize)
			return (_getline_bufsize(bufsize, index, buffer));
	}
}

/**
 * _getline_bufsize - Read a line from stdin.
 * @bufsize: Size of the buffer.
 * @index: Index of the buffer.
 * @buffer: Pointer to the buffer.
 *
 * Description: Read a line from stdin.
 * Return: Number of characters read.
 */
ssize_t _getline_bufsize(size_t bufsize, size_t index, char *buffer)
{
	bufsize += 1024;
	buffer = _realloc(buffer, bufsize - 1024, bufsize);
	if (alloc_error(buffer) == -1)
		return (-1);
	return (index);
}
