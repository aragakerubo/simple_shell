#include "shell.h"

/**
 * _split_path - Split the path in tokens.
 * @line: line to split.
 * @copy_line: copy of the line.
 *
 * Description: Split the path in tokens.
 * Return: Array of tokens.
 */
char **_split_path(char *line, char *copy_line)
{
	int bufsize = 1024, position = 0;
	char **tokens;
	char *token;
	char *delim = ":\r\n\a";

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("shell: allocation error\n");
		return (NULL);
	}
	_strcpy(copy_line, line);
	if (*copy_line == *delim)
	{
		*copy_line = '\0';
		tokens[position] = copy_line;
		position++;
	}
	token = _strtok(copy_line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 1024;
			tokens = _realloc(tokens, bufsize - 1024, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
