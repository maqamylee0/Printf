#include "main.h"

/**
 * _printf - prints formated output
 * @format: pointer to string
 *
 * Return: number of things printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	char *buff;
	unsigned long int buff_loc = 0;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	buff = malloc(1025);
	if (!buff)
		return (0);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += check_specifier(args, format, &i, buff, &buff_loc);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			print_buff(buff, &buff_loc);
			return (-1);
		}
		buff_check(buff, &buff_loc);
		buff[buff_loc] = format[i];
		buff_loc++;
		count++;
	}
	print_buff(buff, &buff_loc);
	va_end(args);
	return (count);
}
