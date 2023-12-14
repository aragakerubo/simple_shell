#include "shell.h"

/**
 * _split_line - Split line in tokens.
 * @line: line to split.
 *
 * Description: Split line in tokens.
 * Return: Array of tokens.
 */
char **_split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		return (NULL);
	}

	token = _strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, bufsize - 64, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
