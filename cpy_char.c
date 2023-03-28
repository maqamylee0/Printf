#include "main.h"

/**
 * cpy_char - copy character to buff
 * @args: variadic parameter
 * @buff: string to hold copy
 * @buff_loc: pointer to current position in buff
 *
 * Return: 1 (success) 0 (fail)
 */
int cpy_char(va_list args, char *buff, unsigned long int *buff_loc)
{
	char c;

	c = va_arg(args, int);
	buff_check(buff, buff_loc);
	buff[*buff_loc] = c;
	*buff_loc = *buff_loc + 1;
	return (1);
}
