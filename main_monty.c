#include "monty.h"
/**
 * main- a file intepreter for monty
 * @argc: arg count, should be 2
 * @argv: arg vector
 * Return: always 
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Useage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
