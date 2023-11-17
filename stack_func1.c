#include "monty.h"


/**
 * add_to_stk - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stk(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tp = head;
	head = *new_node;
	head->next = tp;
	tp->prev = head;
}


/**
 * print_stk - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tp = *stack;
	while (tp != NULL)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL)
		more_er(7, line_number);

	tp = *stack;
	*stack = tp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_er(6, line_number);
	printf("%d\n", (*stack)->n);
}
