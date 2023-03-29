#include "main.h"

/**
 * cpy_bin - convert int to binary
 * @args: argument list
 * @buff: buffer
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 */
int cpy_bin(va_list args, char *buff, unsigned long int *buff_loc)
{

	int count = 0;
	int num = va_arg(args, int);
	int rem;
	char *str;
	int i = 0;

	if (num == 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = '0';
		*buff_loc = *buff_loc + 1;
		return (1);
	}
	str = malloc(sizeof(char) * num + 1);
	if (!str)
		return (-1)


	if (num < 2)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = (char)(num) + '0';
		*buff_loc = *buff_loc + 1;
		count++;
		free(str);
		return (count);
	}
	while (num > 0)
	{
		rem = num % 2;
		buff_check(buff, buff_loc);
		str[i++] = rem + '0';
		count++;
		num /= 2;
	}

	str[i] = '\0';
	*buff_loc = *buff_loc + 1;
	i--;

	while (i >= 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = str[i--];
		*buff_loc = *buff_loc + 1;
	}

	return (count);
}
