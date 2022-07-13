#include "monty.h"

char *data;

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

	if (!result)
		return (NULL);
	memcpy(result, s, slen + 1);
	return (result);
}

/**
 * is_number - determines if str is an integer
 * @str: string parameter
 *
 * Return: 1 (Success) or 0 (Fail)
 */
int is_number(const char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/**
 * free_stack - frees up the memory occupied by the stack
 * @top: top of the stack
 *
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *curr;

	while (top != NULL)
	{
		curr = top;
		top = top->next;
		free(curr);
	}
}
