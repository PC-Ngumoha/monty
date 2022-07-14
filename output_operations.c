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
	stack_t *curr = *top;

	(void) line_number;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
