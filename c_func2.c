#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nod - Swaps the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void swap_nod(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_er(8, line_number, "swap");
	tp = (*stack)->next;
	(*stack)->next = tp->next;
	if (tp->next != NULL)
		tp->next->prev = *stack;
	tp->next = *stack;
	(*stack)->prev = tp;
	tp->prev = NULL;
	*stack = tp;
}

/**
 * add_nod - Adds the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void add_nod(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_er(8, line_number, "add");

	(*stack) = (*stack)->next;
	tot = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nod - Adds the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void sub_nod(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_er(8, line_number, "sub");


	(*stack) = (*stack)->next;
	tot = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nod - Adds the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void div_nod(stack_t **stack, unsigned int line_number)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_er(8, line_number, "div");

	if ((*stack)->n == 0)
		more_er(9, line_number);
	(*stack) = (*stack)->next;
	tot = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
