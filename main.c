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

	if (argc == 2)
	{
		code_file = fopen(argv[1], "r");
		if (!code_file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	free_stack(prog_stack);
	fclose(code_file);
	return (EXIT_SUCCESS);
}
