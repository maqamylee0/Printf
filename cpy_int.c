#include "main.h"

/**
 * cpy_int- prints an integer
 * @args: variadic parameter
 * @buff: string to hold copy
 * @buff_loc: pointer to current position
 *
 * Return: count
 */

int cpy_int(va_list args, char *buff, unsigned long int *buff_loc)
{
	int count = 0;
	unsigned int n;
	int div = 1;
	int i;

	int num = va_arg(args, int);
	

        if (!num)
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

	if (num < 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = '-';
		*buff_loc = *buff_loc + 1;
		count++;
		n = - num;
	}
	else
		n = num;
	for (; n / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = (char)(n / div) + '0' ;
		*buff_loc = *buff_loc + 1;
		count++;
		n %= div;
		div /= 10;
	}
	buff_check(buff, buff_loc);
	buff[*buff_loc] = '\0';
	*buff_loc = *buff_loc + 1;

	return (count);
}
