#include "shell.h"

/**
 * builtin_func - builtin functions.
 * @builtin_func: list of builtin functions.
 * Return: 0 if successfull.
 */
int (*builtin_func[])(char **args, char *input) = {
	&_cd,
	&_help,
	&_exit_shell,
	&_env,
};

/**
 * _execute - execute builtin process.
 * @args: list of arguments passed from parsing.
 * @input: input line for free.
 *
 * Description: execute builtin process.
 * Return: 1 if successfull.
 */
int _execute(char **args, char *input)
{
	char *builtin_cmd[] = {"cd", "help", "exit", "env"};

	int i;

	if (args[0] == NULL)
		return (1);

	if (_strcmp(args[0], "setenv") == 0)
		return (_setenv(args[1], args[2]));

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(args[0], builtin_cmd[i]) == 0)
			return ((*builtin_func[i])(args, input));
	}
	return (_launch(args));
}
