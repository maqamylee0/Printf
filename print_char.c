#include "main.h"

/**
 * print_char - outputs character to stdo
 *@args: variadic parameter
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	int count = 0;

	if (c)
	{
		count = write(1, &c, 1);
		return (count);
	}
	return (0);
}
