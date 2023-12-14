#include "shell.h"

/**
 * _strcspn - Find the position in the string until the delim is equal.
 * @s: string to compare.
 * @delim: delimiter.
 *
 * Description: Find the position in the string until the delim is equal.
 * Return: the position when delim is equal to the string.
 */
int _strcspn(char *s, const char *delim)
{
	int counter = 0, i;

	while (*s)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				return (counter);
		}
		counter++;
		s++;
	}
	return (counter);
}

/**
 * _strspn - Find the position in the string until the delim is different.
 * @s: string to compare.
 * @delim: delimiter.
 *
 * Description: Find the position in the string until the delim is different.
 * Return: the position when delim is different to the string.
 */
int _strspn(char *s, const char *delim)
{
	int i;

	for (i = 0; (s[i] == delim[i]) && (s[i] != '\0' && delim[i] != '\0'); i++)
	{
		;
	}
	return (i);
}

/**
 * _strtok_r - Tokenize a string in words separated by a delimiter.
 * @s: string to compare.
 * @delim: delimiter.
 * @save_str: array of strings to save.
 *
 * Description: Tokenize a string in words separated by a delimiter.
 * Return: pointer to the next token.
 */
char *_strtok_r(char *s, const char *delim, char **save_str)
{
	char *end;

	if (s == NULL)
		s = *save_str;

	if (*s == '\0')
	{
		*save_str = s;
		return (NULL);
	}

	s += _strspn(s, delim);

	if (*s == '\0')
	{
		*save_str = s;
		return (NULL);
	}
	end = s + _strcspn(s, delim);

	if (*end == '\0')
	{
		*save_str = end;
		return (s);
	}

	*end = '\0';
	*save_str = end + 1;
	return (s);
}
/**
 * _strtok - Tokenize a string in words separated by a delimiter.
 * @s: string to compare.
 * @delim: delimiter.
 *
 * Description: Tokenize a string in words separated by a delimiter.
 * Return: pointer to the next token.
 */

char *_strtok(char *s, const char *delim)
{
	static char *olds;

	return (_strtok_r(s, delim, &olds));
}
