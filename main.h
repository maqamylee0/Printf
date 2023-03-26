#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int (*check_specifier(const char *format))(va_list);
int print_char(va_list args);
int print_str(va_list args);
int print_cent(va_list args);

/**
 * struct func - takes specifier
 * and appropriate print
 * @p: character to compare
 * @f: function that prints
 *
 * Description: takes a specifier to be compared
 * so appropriate printing action is taken
 */
typedef struct func
{
	char *p;
	int (*f)(va_list);
} func_t;

#endif
