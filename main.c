#include "monty.h"

sg vars;

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&vars) != 0)
		return (EXIT_FAILURE);

	vars.file = fopen(av[1], "r");
	if (!vars.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&vars.buff, &vars.tmp, vars.file) != EOF)
	{
		opcode = strtok(vars.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&vars, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		vars.line_number++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
