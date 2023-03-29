#include "main.h"

/**
 * cpy_short_unsigned_int - prints a short unsigned int
 * @args: variadic parameter
 * @buff: string to hold copy
 * @buff_loc: pointer to current position
 *
 * Return: count
 */

int cpy_short_unsigned_int(va_list args, char *buff,
unsigned long int *buff_loc)
{
	int count = 0;
	unsigned short int n;
	int div = 1;
	int num = va_arg(args, int);

	n = (unsigned short int) num;

	for (; n / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = (char)(n / div) + '0';
		*buff_loc = *buff_loc + 1;
		count++;
		n %= div;
		div /= 10;
	}
	return (count);
}
