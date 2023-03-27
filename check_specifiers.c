#include "main.h"

/**
 * check_specifier - checks if character is valid specifier
 * and assigns appropriate function for its printing
 * @format: pointer to specifier
 *
 * Return: pointer to function
 */
int (*check_specifier(const char *format))(va_list)
{
	int i;

	func_t array[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"%", print_cent},
		{'\0', NULL}};

	for (i = 0; array[i].p != NULL; i++)
	{
		if (*(array[i].p) == *format)
		{
			return (array[i].f);
		}
	}
	return (NULL);
}
