#include "main.h"

/**
 * cpy_oct - convert int to oct
 * @args: argument list
 * @buff: buffer
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 */
int cpy_oct(va_list args, char *buff, unsigned long int *buff_loc)
{

	int count = 0;
	int num = va_arg(args, int);
	int rem;
	char str[100];
	int i = 0;

	if (num < 8)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = (char)(num) + '0';
		*buff_loc = *buff_loc + 1;
		count++;
		return (count);
	}
	while (num >= 8)
	{
		rem = num % 8;
		buff_check(buff, buff_loc);
		str[i++] = rem + '0';
		count++;
		num /= 8;
	}
	buff_check(buff, buff_loc);
	str[i] = num + '0';
	*buff_loc = *buff_loc + 1;
	count++;

	while (i >= 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = str[i--];
		*buff_loc = *buff_loc + 1;
	}

	return (count);
}
