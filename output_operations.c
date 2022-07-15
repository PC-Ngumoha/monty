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
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			fprintf(stdout, "%d\n", curr->n);
			curr = curr->prev;
		}
	}
}

/**
 * print_top - prints the contents at the top of the stack
 * @top: top of the stack
 * @line_number: number of line of code in the editor
 *
 * Return: void
 */
void print_top(stack_t **top, unsigned int line_number)
{
	if (*top != NULL)
	{
		fprintf(stdout, "%d\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(data.line), fclose(data.file);
		exit(EXIT_FAILURE);
	}
}
