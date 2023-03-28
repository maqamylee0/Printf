#include "main.h"

/**
 * print_buff - ouputs character by character to stdout
 * @buff: string to print
 * @buff_loc: index on buff string
 *
 * Return: nothing
 */
void print_buff(char *buff, unsigned long int *buff_loc)
{
	int i;

	i = write(1, buff, *buff_loc);
	if (i == -1)
		exit(-1);
	free(buff);
	*buff_loc = 0;
}
