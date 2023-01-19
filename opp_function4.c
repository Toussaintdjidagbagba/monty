#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tm = *stack;
	(void) line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	tm->next = *stack;
	(*stack) = (*stack)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	var.MODE = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: Double linked list
 * @line_number: value in line exection
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
	var.MODE = 1;
}
