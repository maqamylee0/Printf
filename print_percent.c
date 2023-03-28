#include "main.h"

/**
 * print_percent - outputs % if in consec places
 * @format: string holding specifier
 * @i: pointer to location of %
 * @buff: string to hold output
 * @buff_loc: current location in string
 *
 * Return: 1 (success) 0 (fail)
 */
int print_percent(const char *format, int *i,
char *buff, unsigned long int *buff_loc)
{
	if (format[*i + 1] == '%')
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = format[*i + 1];
		*buff_loc = *buff_loc + 1;
		*i = *i + 1;
		return (1);
	}
	return (0);
}
