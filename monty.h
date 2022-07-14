#ifndef MONTY_H_
#define MONTY_H_


#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Extern Global Variable: data */
typedef struct data_s
{
	char *operand;
	FILE *file;
	char *line_alloc;
} data_t;

extern data_t data;

/* Helper Functions */
char* _strdup(const char* s);
int is_number(const char *str);
void free_stack(stack_t *top);

/* Function Prototypes */
void (*get_operations(const char *command))(stack_t **, unsigned int);
void push(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void print_all(stack_t **top, unsigned int line_number);
void print_top(stack_t **top, unsigned int line_number);

#endif /* MONTY_H_ */
