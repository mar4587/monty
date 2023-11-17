#include "monty.h"

/**
 * err - This function prints appropiate error messages
 * determined by their error code
 * @error_code: The error codes are
 *
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			num1 = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num1, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}

/**
 * more_er - This handles errors
 * @error_code: The error codes are:
 *
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_er(int error_code, ...)
{
	va_list ag;
	char *op;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num1 = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num1, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}

/**
 * string_er - This handles errors
 * @error_code: The error codes are:
 *
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> tack is empty
 */
void string_er(int error_code, ...)
{
	va_list ag;
	int num1;

	va_start(ag, error_code);
	num1 = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num1);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num1);
			break;
		default:
			break;
	}
	free_nod();
	exit(EXIT_FAILURE);
}
