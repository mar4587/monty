#include "monty.h"

/**
 * mul_nod - Adds the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void mul_nod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_er(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nod - Adds the top two elements of the stack.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void mod_nod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_er(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_er(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
