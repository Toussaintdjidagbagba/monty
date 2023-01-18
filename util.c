#include "monty.h"

/**
 * start_vars - initialise struct global
 * @vars: struct global to initialize
 * Return: 0 Success, 1 Failed
 */
int start_vars(sg *vars)
{
	vars->file = NULL;
	vars->buff = NULL;
	vars->tmp = 0;
	vars->dict = create_instru();
	if (vars->dict == NULL)
		return (EXIT_FAILURE);
	vars->head = NULL;
	vars->line_number = 1;
	vars->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * create_dic - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_dic()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_funct - Call Functions
 * @vars: struct global 
 * @opcode: Command to execute
 * Return: None
 */
int call_funct(sg *vars, char *opcode)
{
	int i;

	for (i = 0; vars->dict[i].opcode; i++)
		if (strcmp(opcode, vars->dict[i].opcode) == 0)
		{
			if (!vars->dict[i].f)
				return (EXIT_SUCCESS);
			vars->dict[i].f(&vars->head, vars->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			vars->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (vars.buff != NULL)
		free(vars.buff);
	if (vars.file != NULL)
		fclose(vars.file);
	free(vars.dict);
	if (vars.head != NULL)
	{
		while (vars.head->next != NULL)
		{
			vars.head = vars.head->next;
			free(vars.head->prev);
		}
		free(vars.head);
	}
}

/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
