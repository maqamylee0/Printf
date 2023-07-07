#include "main.h"

/**
 * check_specifier - checks if character is valid specifier
 * and assigns appropriate function for its printing
 * @args: item from va_list
 * @format: format string
 * @i: pointer to positionof %
 * @buff: buffer holding output string
 * @buff_loc: current position in buff
 *
 * Return: count
 */
int check_specifier(va_list args, const char *format,
int *i, char *buff, unsigned long int *buff_loc)
{
	int j, count = 0, match = 0;

	func_t print[] = {{"c", cpy_char}, {"s", cpy_str}, {"d", cpy_int},
	{"i", cpy_int}, {"b", cpy_bin}, {"o", cpy_oct}, {"x", cpy_hex},
	{"X", cpy_x_hex}, {"u", cpy_short_unsigned_int}, {"p", cpy_address},
	{"S", cpy_custom_str}, {NULL, NULL}};

	if (print_percent(format, i, buff, buff_loc))
	{
		count++;
		match = 1;
	}

	j = 0;
	while (print[j].p != NULL)
	{
		if (print[j].p[0] == format[*i + 1])
		{
			count += (*print[j].f)(args, buff, buff_loc);
			*i = *i + 1;
			match = 1;
			break;
		}
		j++;
	}
	if (match == 0)
	{
		buff_check(buff, buff_loc);
		buff[*buff_loc] = format[*i];
		*buff_loc = *buff_loc + 1;
		count++;
	}
	return (count);
}
