#include "main.h"
/**
 * print_int - function that prints an integer.
 * @args: the argument number
 * Return: integer for the lenght
 */

int print_int(va_list args)
{
	char digit;
	unsigned int temp;
	int input;
	int di = 1;
	int len = 0;

	input = va_arg(args, int);
	if (input < 0)
	{
		len += write(1, "-", 1);
		input = input * -1;
	}

	while (input / di > 9)
	{
		di = 10 * di;
	}
	temp = input;
	while (di)
	{
		digit = (temp / di) + '0';
		len = write(1, &digit, 1) + len;
		temp = temp % di;
		di = di / 10;
	}
	return (len);
}