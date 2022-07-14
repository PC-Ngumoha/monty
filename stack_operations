#include "monty.h"

/**
 * push - pushes a node to the top of the stack
 * @top: top of the stack
 * @line_number: current line in the editor where the code was typed in
 *
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_node;
	int push_data;

	if (is_number(data.operand) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(data.line_alloc), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	push_data = atoi(data.operand);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(data.line_alloc), fclose(data.file);
		exit(EXIT_FAILURE);
	}
	new_node->n = push_data;
	if (*top == NULL)
	{
		*top = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		(*top)->next = new_node;
		new_node->next = NULL;
		new_node->prev = *top;
		*top = new_node;
	}
}
