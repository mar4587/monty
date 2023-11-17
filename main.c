#include "monty.h"

stack_t *head = NULL;

/**
 * main - The entry point
 * @argc: the argument count
 * @argv: list of argument
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_op(argv[1]);
	free_nod();

	return (0);
}

/**
 * create_node - This creates a node
 * @n: Number to go inside the node
 *
 * Return: a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nod - This frees nodes in the stack.
 */
void free_nod(void)
{
	stack_t *tp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tp = head;
		head = head->next;
		free(tp);
	}
}


/**
 * add_to_queue - This adds a node to the queue
 * @new_node: Pointer to the new node
 *
 * @ln: the line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tp->next != NULL)
		tp = tp->next;

	tp->next = *new_node;
	(*new_node)->prev = tp;

}
