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
	ssize_t num_read;
	size_t length = 0, line_count = 1;
	char *command, *token, *line = NULL;
	void (*operation)(stack_t **, unsigned int);
	stack_t *prog_stack = NULL;

	if (argc == 2)
	{
		code_file = fopen(argv[1], "r");
		if (!code_file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while ((num_read = getline(&line, &length, code_file)) >= 0)
		{
			token = strtok(line, " ");
			command = _strdup(token), token = strtok(NULL, " ");
			if (token != NULL)
				data = _strdup(token);
			operation = get_operations(command);
			if (!operation)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						line_count, command);
				exit(EXIT_FAILURE);
			}
			operation(&prog_stack, line_count);
			line_count++;
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	free(buffer), buffer = NULL;
	fclose(code_file);
	return (EXIT_SUCCESS);
}
