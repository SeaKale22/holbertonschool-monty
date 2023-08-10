#include "monty.h"
/**
 * free_stack- frees a stack
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
