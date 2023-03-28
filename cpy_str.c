#include "main.h"

/**
 * cpy_str - copy string to buff
 * @args: variadic parameter
 * @buff: string to hold copy
 * @buff_loc: pointer to current position in buff
 *
 * Return: count
 */
int cpy_str(va_list args, char *buff, unsigned long int *buff_loc)
{
	int i, count = 0;
	char *s = va_arg(args, char *);

	if (!s)
	{
		char *null = "(null)";

		for (i = 0; null[i]; i++)
		{
			buff_check(buff, buff_loc);
			buff[*buff_loc] = null[i];
			*buff_loc = *buff_loc + 1;
			count++;
		}
	}
	else
	{
		for (i = 0; s[i]; i++)
		{
			buff_check(buff, buff_loc);
			buff[*buff_loc] = s[i];
			*buff_loc = *buff_loc + 1;
			count++;
		}
	}
	return (count);
}
