#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int check_specifier(va_list args, const char *format,
int *i, char *buff, unsigned long int *buff_loc);
void print_buff(char *buff, unsigned long int *buff_loc);
void buff_check(char *buff, unsigned long int *buff_loc);
int print_percent(const char *format, int *i, char *buff,
unsigned long int *buff_loc);
int cpy_str(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_char(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_int(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_bin(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_short_unsigned_int(va_list args, char *buff,
unsigned long int *buff_loc);
int cpy_oct(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_hex(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_x_hex(va_list args, char *buff, unsigned long int *buff_loc);
int cpy_address(va_list args, char *buff, unsigned long int *buff_loc);

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
	int (*f)(va_list, char *, unsigned long int *);
} func_t;

#endif
