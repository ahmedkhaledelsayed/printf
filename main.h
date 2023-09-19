#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct arg
{
	char *argt;
	int (*fun)();
} arg_t;

int _printf(const char *format, ...);
int _putchar(char a);
int print_ch(va_list args);
int print_int(va_list args);
int print_str(va_list args);

#endif