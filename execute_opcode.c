#include "monty.h"
/**
 * execute_opcode- executes function for given opcode
 * @stack: doubly linked list as the stack
 * @opcode: the opcode to execute
 * @line_number: the current line number
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
	};

	int num_opcodes = sizeof(opcodes) / sizeof(opcodes[0]);
	int i;

	for (i = 0; i < num_opcodes; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	/*opcode not found*/
	fprintf(stderr, "Line %d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
