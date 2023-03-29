#include "main.h"

/**
 * cpy_x_hex - handles x
 * @args: argument list
 * @buff: buffer
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 */
int cpy_x_hex(va_list args, char *buff, unsigned long int *buff_loc)
{

	int count, len = 0;
	unsigned int num_1, num = va_arg(args, int);
	char *str;
	char hex[16] = "0123456789ABCDEF";
	int i;

	num_1 = num;
	if (num < 16)
	{
		buff[*buff_loc] = hex[num];
		*buff_loc = *buff_loc + 1;
		buff_check(buff, buff_loc);
		return (1);
	}
	for ( ; num_1 != 0; num_1 /= 16)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);

	count = len;

	for (i = len - 1; i >= 0; i--)
	{
		int rem = num % 16;

		num = num / 16;
		str[i] = hex[rem];
	}

	for (i = 0; i < len; i++)
	{
		buff[*buff_loc] = str[i];
		*buff_loc = *buff_loc + 1;
		buff_check(buff, buff_loc);
	}
	free(str);
	return (count);
}
