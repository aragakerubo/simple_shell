#include "shell.h"

/**
 * _getenv - Get the environment variable.
 * @name: name of the variable
 *
 * Description: Get the environment variable.
 * Return: String with the value of the variable.
 */
char *_getenv(const char *name)
{
	size_t len;
	char **ep;

	len = _strlen((char *)name);

	if (environ == NULL || name[0] == '\0')
		return (NULL);

	len--;
	for (ep = environ; *ep != NULL; ep++)
	{
		if (!_strncmp(*ep, name, len) && (*ep)[len + 1] == '=')
			return (&(*ep)[len + 2]);
	}
	return (NULL);
}
