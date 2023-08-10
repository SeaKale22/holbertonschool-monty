#include "monty.h"

/**
 * op_pop- removes top element of stack
 * @stack: stack
 * @line_number: line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL) /*stack is empty*/
	{
		fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *tmp = *stack; /*save current top element*/

	*stack = (*stack)->next; /*update top of stack*/
	if (*stack)
	{
		(*stack)->prev = NULL; /*update the new top elements prev pointer*/
	}
	free(tmp);
}
/**
 * op_swap- swaps top two elements of stack
 * @stack: stack
 * @line_number: line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int tmp = (*stack)->n; /*save value of top element*/

	(*stack)->n = (*stack)->next->n; /*update value of top element to value of second element*/
	(*stack)->next->n = tmp; /*update value of second element to saved value */
}
