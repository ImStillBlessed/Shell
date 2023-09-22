#include "main.h"

/**
 *_strncpy - fucntion append two strings to one
 *@dest: string will be copied to
 *@src: string will be copied from
 *@n:buffer
 *Return: always string of chars
 */


char *_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_start = dest;

	while (*src && n > 0)
	{
		*dest++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (dest_start);
}

/**
 *_isdigit - checks if char is num
 *@c: char
 *Return: not NULL for success
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 *isNumber - checks if string is number
 *@str: string to examened
 *Return: 0 for success
*/

int isNumber(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (!_isdigit(str[i]))
			return (0);
	}
	return (1);
}


/**
 *_strtok - tokenize string
 *@str: pointer to string to tokenized
 *@del: delimeters
 *Return: pointer to token
 */

char *_strtok(char *str, char *del)
{
	static char *next_token /*= NULL*/;
	char *token;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	token = next_token;
	next_token = _strpbrk(next_token, del);
	if (next_token != NULL)
	{
		*next_token = '\0';
		next_token++;
	}

	return (token);
}


/**
 *_strpbrk - function gets length of prefix substring.
 *@s: string s
 *@accept: another string
 *Return: returns smtg
 */

char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
			{
				return (s);
			}
			a++;
		}
		s++;
	}
	return ('\0');
}
