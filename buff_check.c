#include "main.h"

/**
 * buff_check - checks if buff string is full.
 * sends to output and resets index to 0
 * allowing for new data to be written without loss of data
 * @buff: string to be worked on
 * @buff_loc: index
 *
 * Return: nothing
 */
void buff_check(char *buff, unsigned long int *buff_loc)
{
	if (*buff_loc == 1300)
	{
		print_buff(buff, buff_loc);
		*buff_loc = 0;
	}
}
