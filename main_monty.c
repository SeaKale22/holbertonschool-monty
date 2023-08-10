#include "monty.h"

/**
 * main- a file intepreter for monty
 * @argc: arg count, should be 2
 * @argv: arg vector
 * Return: always 
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	FILE *monty_file;
	stack_t *stack = NULL;

	if (argc != 2) /*checks if argc is two */
	{
		fprintf(stderr, "Useage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r"); /*opens and reads from the file*/
	if (!monty_file) /*fopen failed*/
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*read each line from monty file*/
	while (getline(&line, &len, monty_file) != -1)
	{
		line_number++;
		/*Tokenize the line to extract opconde and arguments*/
		char *opcode = strtok(line, DELIMS);
		if (!opcode) /*empty line, skip*/
			continue;
		execute_opcode(&stack, opcode, line_number);
	}
	/*clean up */
	fclose(monty_file);
	free(line);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
