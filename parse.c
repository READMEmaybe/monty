#include "monty.h"
/**
 * _strlen - Returns the length of a string.
 * @str: The string to be checked.
 * Return: The length of str.
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;

	return (i);
}
/**
 * *_strcpy - Copies string.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while (*src)
		*d++ = *src++;

	*d = '\0';

	return (dest);
}
/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @str: The string to search in.
 * @c: The character to locate.
 *
 * Return: Returns a pointer to the first occurrence of the character c
 *			in the string str, or NULL if the character is not found.
 */

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}

	return (NULL);
}
/**
 * _strtok - Breaks a string into a sequence of
 * zero or more nonempty tokens
 * @str: The string to tokenize
 * @delim: The string of the delimiter characters
 *
 * Return: A pointer to the next token,
 * or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *ptr;
	char *token;

	if (str)
		ptr = str;

	else if (!ptr || !delim || !*delim)
		return (NULL);

	while (*ptr && _strchr(delim, *ptr))
		ptr++;

	if (!*ptr)
		return (NULL);

	token = ptr;
	while (*ptr && !_strchr(delim, *ptr))
		ptr++;

	if (*ptr)
		*ptr++ = '\0';
	else
		ptr = NULL;

	return (token);
}
/**
 * parse - Tokenizes a line and stores the tokens in a 2D array.
 * @args: Pointer to the pointer that will hold the array of tokens.
 * @line: The input line to be tokenized.
 * @size: The size of the input line buffer.
 * @delims: The delimiters used to tokenize the line.
 *
 * Return: 1 on success, 0 on memory allocation failure.
 */
size_t parse(char ***args, char *line, size_t size, const char *delims)
{
	char *token;
	size_t len = size / 2 + size % 2 + 1;
	size_t i;

	*args = malloc(len * sizeof(char *));
	if (!*args)
		return (1);

	token = _strtok(line, delims);
	for (i = 0; token; i++)
	{
		(*args)[i] = malloc((_strlen(token) + 1) * sizeof(char));
		/* if (!(*args)[i])
		{
			free_vec(*args);
			return (0);
		} */

		_strcpy((*args)[i], token);
		token = _strtok(NULL, delims);
	}

	line = NULL;
	(*args)[i] = NULL;
	return (1);
}
