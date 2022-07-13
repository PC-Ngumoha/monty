#include "monty.h"

/**
 * print_all - prints all the elements on the stack
 * @top: top of the stack
 * @line_number: number of line of code in editor
 *
 * Return: void
 */
void print_all(stack_t **top, unsigned int line_number)
{
	(void) line_number;

	while (*top != NULL)
	{
		printf("%d\n", (*top)->n);
		*top = (*top)->next;
	}
}
