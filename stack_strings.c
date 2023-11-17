#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
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
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
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
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
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
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
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
