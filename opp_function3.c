#include "monty.h"

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}


/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of
 * the stack, followed by a new line.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 0 && (*stack)->n < 128)
	{
		printf("%c\n", (*stack)->n);
		return;
	}else{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!isascii((tmp)->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
