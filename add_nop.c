#include "monty.h"
/**
 * op_add- adds top two elements of stack
 * @stack: the stack
 * @line_number: line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *tmp = *stack;

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * op_nop- does nothing
 * @stack: the stack
 * @line_number: line number
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
