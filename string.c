#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: the pointer to top the node
 * @line_number: the integer
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_er(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_er(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: the pointer to top the node
 * @ln: the integer
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tp = *stack;
	while (tp != NULL)
	{
		ascii = tp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tp = tp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: the pointer to top the node
 * @ln: the integer
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tp = *stack;
	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *stack;
	(*stack)->prev = tp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: the pointer to top the node
 * @ln: the integer
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tp = *stack;

	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *stack;
	tp->prev->next = NULL;
	tp->prev = NULL;
	(*stack)->prev = tp;
	(*stack) = tp;
}
