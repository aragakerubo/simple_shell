#include "shell.h"

/**
 * _launch - Launch a program and wait for it to terminate.
 * @args: Null terminated list of arguments.
 *
 * Description: Launch a program and wait for it to terminate.
 * Return: 1 if successfull, -1 if not.
 */
int _launch(char **args)
{
	int status, pid;
	int flag = 0;

	args = _check_path(args, &flag);

	if (args == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("shell");
		}
		if (flag == 1)
			free(args[0]);
		return (-1);
	}
	else if (pid < 0)
	{
		perror("shell");
		if (flag == 1)
			free(args[0]);
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (flag == 1)
		free(args[0]);
	return (1);
}
