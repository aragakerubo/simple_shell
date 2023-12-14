#include "shell.h"

/**
 * alloc_error2 -  Allocation error
 * @buffer: buffer to check
 *
 * Description: Allocation error
 * Return: -1 on error.
 */
int alloc_error2(char *buffer)
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
 * alloc_error1 -  Allocation error
 * @dest_path: dest path
 * @buffer: buffer to check
 *
 * Description: Allocation error
 * Return: -1 on eror.
 */
int alloc_error1(char *buffer, char *dest_path)
{
	if (!buffer)
	{
		free(dest_path);
		perror("shell: allocation error\n");
		return (-1);
	}
	return (0);
}

/**
 * _check_path - Split the command line.
 * @args: command line.
 * @flag: flag to check if the command is found.
 *
 * Description: Split the command line.
 * Return: String with the file path.
 */
char **_check_path(char **args, int *flag)
{
	char *path, **tokens_path, *dest_path, *copy_line;
	int j, k;

	for (k = 0; *(args[0] + k) != '\0'; k++)
	{
		if (*(args[0] + k) == '/')
			return (args);
	}
	dest_path = malloc(sizeof(char) * 1024);
	if (alloc_error2(dest_path) == -1)
		return (NULL);
	path = _getenv("PATH");
	copy_line = malloc((_strlen(path) + 1) * sizeof(char *));
	if (alloc_error1(copy_line, dest_path) == -1)
		return (NULL);
	tokens_path = _split_path(path, copy_line);
	if (tokens_path == NULL)
	{
		free(copy_line);
		return (NULL);
	}
	for (j = 0; *(tokens_path + j) != NULL; j++)
	{
		_strcpy(dest_path, *(tokens_path + j));
		*dest_path != '\0' ? _strcat(dest_path, "/") : _strcat(dest_path, "./");
		_strcat(dest_path, args[0]);
		if (access(dest_path, X_OK) != -1)
		{
			args[0] = dest_path;
			*flag = 1;
			free(copy_line);
			free(tokens_path);
			return (args);
		}
	}
	free(dest_path);
	free(tokens_path);
	free(copy_line);
	perror("shell");
	return (NULL);
}
