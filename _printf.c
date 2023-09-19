#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: pointer to string
 * Return: integer for the lenght
 */
int _printf(const char *format, ...)
{
	int index1 = 0, index2, len = 0;
	va_list vaargs;

	arg_t objs[] = {
		{"c", print_ch}, 
		{"s", print_str}, 
		{"d", print_int}, 
		{"i", print_int}, 
		{NULL, NULL}
	};
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	va_start(vaargs, format);
	for (index1 = 0; format[index1] != '\0'; index1++)
	{
		if (format[index1] != '%')
		{
			len += write(1, &format[index1], 1);
		}
		else
		{
			index1++;
			for (index2 = 0; objs[index2].argt != NULL; index2++)
			{
				if (format[index1] == '%')
				{
					len += write(1, "%", 1);
					break;
				}

				else if (*(objs[index2].argt) == format[index1])
				{
					len = objs[index2].fun(vaargs) + len;
					if (len == -1)
					{
						return (-1);
					}
					break;
				}
			}
		}
	}
	va_end(vaargs);
	return (len);
}