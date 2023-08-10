#include "monty.h"
/**
 * is_valid_int- checks if passed argument is a valid integer for opcode push
 * @str: string to be checked
 * Return: true or false
 */
bool is_valid_int(const char *str)
{
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
