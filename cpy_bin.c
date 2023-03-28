#include "main.h"

/**
 * cpy_bin - convert int to binary 
 * @args: argument list
 * @buff: buffer 
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 **/
int cpy_bin(va_list args, char *buff, unsigned long int *buff_loc)
{
	
	int count = 0;
	int num = va_arg(args, int);
	int rem;
	
	if (num < 2)
	{
		buff_check(buff, buff_loc);
                buff[*buff_loc] = (char)(num) + '0';
                *buff_loc = *buff_loc + 1;
                count++;
		return (char)(num) + '0';
	}
	while (num >= 2)
	{
		rem = num % 2;
		buff_check(buff, buff_loc);
		buff[*buff_loc] = (char)(rem) + '0';
		*buff_loc = *buff_loc + 1;
		count++;
		num /= 2;
	}
	buff_check(buff, buff_loc);
	buff[*buff_loc] = (char)(num) + '0';
	*buff_loc = *buff_loc + 1;
	count++;

	return (count);
}

