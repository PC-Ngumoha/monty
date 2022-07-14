#include "monty.h"


/**
 * main - main entry point of the program
 * @argc: count of command line arguments
 * @argv: vector of command line arguments
 *
 * Return: 0 (Success) or errno (Fail)
 */
int main(int argc, char **argv)
{
	FILE *code_file;
	size_t line_number = 1, length = 0;
	char *command, *token, *line = NULL;
	stack_t *prog_stack = NULL;
	void (*operation)(stack_t **, unsigned int);

	if (argc == 2)
	{
		code_file = fopen(argv[1], "r");
		if (!code_file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (getline(&line, &length, code_file) != -1)
		{
			line[strcspn(line, "\n")] = '\0';
			command = strtok(line, " ");
			token = strtok(NULL, " ");
			if (token != NULL)
				data = token;
			operation = get_operations(command);
			if (!operation)
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, command);
				exit(EXIT_FAILURE);
			}
			operation(&prog_stack, line_number);
			line_number++;
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	free(line), line = NULL;
	free_stack(prog_stack), fclose(code_file);
	return (EXIT_SUCCESS);
}
