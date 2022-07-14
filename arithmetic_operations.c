#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @top: top of the stack
 * @line_number: number of line in editor
 *
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	stack_t *popped;
	int length;

	length = stack_length(*top);
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(data.line_alloc), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	else if (length < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(data.line_alloc), fclose(data.file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		popped = *top;
		*top = (*top)->prev;
		(*top)->next = NULL;
		popped->prev = NULL;
		/* Performing The Addition */
		(*top)->n += popped->n;
		free(popped);
	}
}
