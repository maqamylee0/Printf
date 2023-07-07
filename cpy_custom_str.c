#include "main.h"

int cpy_custom_str(va_list args, char *buff, unsigned long int *buff_loc)
{
    int i, count = 0;
    char *s = va_arg(args, char *);

    if (!s)
    {
        char *null = "(null)";

        for (i = 0; null[i]; i++)
        {
            buff_check(buff, buff_loc);
            buff[*buff_loc] = null[i];
            *buff_loc = *buff_loc + 1;
            count++;
        }
    }
    else
    {
        for (i = 0; s[i]; i++)
        {
            if (s[i] < ' ' || s[i] >= 127)
            {
                buff_check(buff, buff_loc);
                buff[*buff_loc] = '\\';
                *buff_loc = *buff_loc + 1;
                count++;
                buff_check(buff, buff_loc);
                buff[*buff_loc] = 'x';
                *buff_loc = *buff_loc + 1;
                count++;
                buff_check(buff, buff_loc);
                buff[*buff_loc] = ((s[i] >> 4) & 0xF) < 10 ? ((s[i] >> 4) & 0xF) + '0' : ((s[i] >> 4) & 0xF) + 'A' - 10;
                *buff_loc = *buff_loc + 1;
                count++;
                buff_check(buff, buff_loc);
                buff[*buff_loc] = (s[i] & 0xF) < 10 ? (s[i] & 0xF) + '0' : (s[i] & 0xF) + 'A' - 10;
                *buff_loc = *buff_loc + 1;
                count++;
            }
            else
            {
                buff_check(buff, buff_loc);
                buff[*buff_loc] = s[i];
                *buff_loc = *buff_loc + 1;
                count++;
            }
        }
    }
    return count;
}

