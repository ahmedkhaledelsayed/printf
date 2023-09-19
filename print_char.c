#include "main.h"

/**
 * print_ch - function that prints an character.
 * @args: the argument number
 * Return: integer for the lenght
 */
int print_ch(va_list args)
{
	char ch = va_arg(args, int);

	write(1, &ch, 1);
	return (1);
}