#include "main.h"

/**
 * _printf - prints formated output
 * @format: pointer to string
 *
 * Return: number of things printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, temp = 0, count = 0;
	va_list args;
	int (*f)(va_list);

<<<<<<< HEAD
	if (format == NULL || format[i] == '\0')
		return (-1);

	va_start(args, format);
=======
	va_start(args, format);

	/* ensures NULL pointer isnt parsed */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	/* prints each character of string */
>>>>>>> 14ca5e9cecbb7805eda6f642f8e560b6b4ddbd3b
	while (format[i])
	{
		if (format[i] != '%')
		{
			temp = write(1, &format[i], 1);
			count += temp;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				temp = f(args);
				count = count + temp;
				i = i + 2;
				continue;
			}
			if (format[i + 1] == '\0')
			{
				break;
			}
			if (format[i + 1] != '\0')
			{
				temp = write(1, &format[i + 1], 1);
				count += temp;
				i = i + 2;
				continue;
			}
		}
	}
	va_end(args);
	return (count);
}
