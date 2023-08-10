#include "monty.h"

/**
 * op_push- pushes an element to the stack
 * @stack: the stack
 * @line_number: current line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int push_value;
	stack_t *new_node;

	argument = strtok(NULL, " \t\n"); /*get argument after push opcode*/
	if (!argument)
	{
		fprintf(stderr, "L%d: useage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_value = atoi(argument); /*convert argument to int*/
	/*create new node for stack*/
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack) /*update previous node of stack if exists*/
		(*stack)->prev = new_node;
	/*make new node new top of stack*/
	*stack = new_node;
}

/**
 * op_pall-pritns all values in stack, starting from the top
 * @stack: rhe stack
 * @line_number: current line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /*unsued parameter*/

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next; /*move to next node*/
	}
}
