#include "main.h"

/**
 * print_int- prints an integer
 * description: prints an integer
 * @args: list of arguments
 * Return: number of bytes used
 */
int print_int(va_list args)
{
	int str[40];
	int i = 0;
	int count = 0;
	int temp = 0;
	int num = 0;

	num = va_arg(args, int);
	temp = num;
	if (num < 0)
		num = -num;
	while (num != 0)
	{
		str[i++] = (num % 10);
		num /= 10;
	}
	if (temp < 0)
		str[i++] = '-';
	count += i;
	i--;
	while (i >= 0)
	{
		if (str[i] != '-')
			_putchar(str[i--] + '0');
		else
			_putchar(str[i--]);
	}
	return (count);
}
