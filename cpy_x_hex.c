#include "main.h"

/**
 * cpy_x_hex - outputs unsigned hex in capital
 * @args: argument list
 * @buff: buffer
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 */
int cpy_x_hex(va_list args, char *buff, unsigned long int *buff_loc)
{

	int count = 0;
	int num = va_arg(args, int);
	int rem;
	char str[100];
	int i = 0;

	if (num == 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = '0';
		*buff_loc = *buff_loc + 1;
		return (1);
	}
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
		{
			str[i++] = rem + '0';
		}
		else
		{
			str[i++] = rem - 10 + 'A';
		}
		num /= 16;
	}
	count = i;

	while (i > 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = str[--i];
		*buff_loc = *buff_loc + 1;
	}

	return (count);
}
