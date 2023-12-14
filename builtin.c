#include "shell.h"

/**
 * _cd - change the directory.
 * @args: list of arguments passed from parsing.
 * @input: input line for free.
 *
 * Description: Change the directory to the path passed in args[1].
 * Return: 1 if successfull.
 */
int _cd(char **args, __attribute__((unused)) char *input)
{

	if (args[1] == NULL)
	{
		if (chdir(_getenv("HOME")) != 0)
		{
			perror("shell");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("shell");
		}
	}
	return (1);
}

/**
 * _help - display the help about a command.
 * @args: list of arguments passed from parsing.
 * @input: input line for free.
 *
 * Description: Display the help about a command.
 * Return: 1 if successfull.
 */
int _help(__attribute__((unused)) char **args,
	  __attribute__((unused)) char *input)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * _exit_shell - exit the shell.
 * @args: list of arguments passed from parsing.
 * @input: input line for free.
 *
 * Description: Exit the shell.
 * Return: 0 if successfull.
 */
int _exit_shell(__attribute__((unused)) char **args, char *input)
{
	int var;

	if (args[1] == NULL)
		return (0);

	var = _atoi(args[1]);

	if (var < 0)
	{
		perror("shell");
		return (1);
	}
	else if (var == 0)
	{
		return (0);
	}
	else if (var >= 256)
	{
		free(input);
		free(args);
		exit(var - 256);
	}
	else
	{
		free(input);
		free(args);
		exit(var);
	}
}

/**
 * _env - Display the environ in the shell.
 * @args: list of arguments passed from parsing.
 * @input: input line for free.
 *
 * Description: Display the environ in the shell.
 * Return: 1 if successfull.
 */
int _env(__attribute__((unused)) char **args,
	 __attribute__((unused)) char *input)
{
	int i = 0;

	while (environ[i] != 0)
	{

		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	return (1);
}

/**
 * _setenv - Set an enrinment variable.
 * @name: name of the variable
 * @value: value in the variable.
 *
 * Description: Set an enrinment variable.
 * Return: 1 if successfull.
 */
int _setenv(char *name, char *value)
{
	char *tmp, new_variable[1024];
	char **ep = environ;
	char **ev;
	int counter = 0, i;

	if (value == NULL)
	{
		perror("shell");
	}
	tmp = _getenv(name);
	if (tmp != NULL)
	{
		_strcpy(tmp, value);
	}
	else
	{
		while (ep[counter] != NULL)
		{
			counter++;
		}
		counter += 2;
		ev = malloc(counter * sizeof(char *));
		for (i = 0; ep[i] != NULL; i++)
		{
			ev[i] = ep[i];
		}
		_strcat(new_variable, name);
		_strcat(new_variable, "=");
		_strcat(new_variable, value);
		ev[i] = new_variable;
		ev[++i] = NULL;
		environ = ev;
		free(ep);
	}

	return (1);
}
