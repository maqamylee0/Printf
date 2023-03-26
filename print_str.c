#include "main.h"

/**
 * print_str - outputs string to stdout
 *@args: variadic parameter
 *
 * Return: number of characters printed (Success)
 * or -1 (failure)
 */
int print_str(va_list args)
{
	int i;
	int count = 0;
	int temp;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);

	while (str[i])
	{
		temp = write(1, &str[i], 1);
		count = count + temp;
		i = i + 1;
	}

	return (count);
}
