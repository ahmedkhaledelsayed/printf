#include "main.h"

/**
 * print_str - function that prints a string.
 * @args: the argument number
 * Return: integer for the lenght
 */

int print_str(va_list args)
{
	char *c;
	int i = 0, len = 0;

	c = va_arg(args, char *);
	if (c == NULL)
		c = "(null)";
	while (c[i])
	{
		write(1, &c[i], 1);
		len++;
		i++;
	}
	return (len);
}