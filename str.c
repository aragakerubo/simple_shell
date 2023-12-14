/**
 * _strlen - Find the length of a string.
 * @s: string to find the length of.
 *
 * Description: Find the length of a string.
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * _strcat - Concatent two strings.
 * @dest: destination string.
 * @src: source string.
 *
 * Description: Concatent two strings.
 * Return: pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int size = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[size + i] = src[i];
	}
	dest[size + i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compare two strings.
 * @s1: first string
 * @s2: second string.
 *
 * Description: Compare two strings.
 * Return: negative number if s1 less s2,
 * 0 if s1 is equal to s2,
 * positive number if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strcpy - Copy a string.
 * @dest: destination string
 * @src: source string
 *
 * Description: Copy a string.
 * Return: pointer to the resulting string dest.
 */
char *_strcpy(char *dest, char *src)
{
	int j, i = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}

	for (j = 0; j <= i; j++)
	{
		*(dest + j) = *(src + j);
	}

	dest[j + 1] = '\0';
	return (dest);
}

/**
 * _strncmp - Compare two strings.
 * @s1: first string
 * @s2: second string.
 * @n: number of bytes to compare.
 *
 * Description: Compare two strings.
 * Return: negative number if s1 less s2,
 * 0 if s1 is equal to s2,
 * positive number if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	int n4;

	if (n >= 4)
	{

		n4 = n >> 2;
		do {
			c1 = (unsigned char)*s1++;
			c2 = (unsigned char)*s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char)*s1++;
			c2 = (unsigned char)*s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char)*s1++;
			c2 = (unsigned char)*s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			c1 = (unsigned char)*s1++;
			c2 = (unsigned char)*s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
		} while (--n4 > 0);
		n &= 3;

		while (n > 0)
		{
			c1 = (unsigned char)*s1++;
			c2 = (unsigned char)*s2++;
			if (c1 == '\0' || c1 != c2)
				return (c1 - c2);
			n--;
		}
		return (c1 - c2);
	}
}
