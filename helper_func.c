#include "monty.h"

/**
 * _strdup - duplicates a string in memory
 * @s: string to duplicate
 *
 * Return: duplicate of @s
 */
char *_strdup(const char *s)
{
	size_t slen = strlen(s);
	char *result = malloc(slen + 1);

	if (result == NULL)
	{
		return (NULL);
	}
	memcpy(result, s, slen + 1);
	return (result);
}
