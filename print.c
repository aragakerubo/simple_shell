#include "shell.h"

/**
 * _puts - prints a string
 * @str: string to print
 *
 * Description: prints a string
 * Return: void
 */
void _puts(char *str)
{
	int acc = 0;

	while (str[acc] != '\0')
	{
		_putchar(str[acc]);
		acc++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Description: writes the character c to stdout
 * Return: On success 1, on error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _atoi - Convert a string to an integer.
 * @s: String to convert.
 *
 * Description: Convert a string to an integer.
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int i = 0, flag = 0, num = 1;
	unsigned int output = 1, sum = 0;

	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && flag == 0)
		{
			if (s[i] == '-')
			{
				num *= -1;
			}
			else
			{
				num *= 1;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
		}
		else if (flag)
		{
			break;
		}

		i++;
	}

	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum += (s[i] - '0') * output;
		output *= 10;
		i--;
	}

	return (sum * num);
}
