#include "monty.h"

global_temp gt;

/**
 * free_gt - frees the global variables
 *
 * Return: no return
 */
void free_gt(void)
{
	free_dlistint(gt.head);
	free(gt.buffer);
	fclose(gt.fd);
}

/**
 * start_gt - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_gt(FILE *fd)
{
	gt.lifo = 1;
	gt.cont = 1;
	gt.arg = NULL;
	gt.head = NULL;
	gt.fd = fd;
	gt.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_gt(fd);
	nlines = getline(&gt.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(gt.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				printf( "L%u: ", gt.cont);
				printf( "unknown instruction %s\n", lines[0]);
				free_gt();
				exit(EXIT_FAILURE);
			}
			gt.arg = _strtoky(NULL, " \t\n");
			f(&gt.head, gt.cont);
		}
		nlines = getline(&gt.buffer, &size, fd);
		gt.cont++;
	}

	free_gt();

	return (0);
}
