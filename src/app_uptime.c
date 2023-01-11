#include "app_uptime.h"

#define _DB_read_

void uptime_read_all(void)
{
    int c;
    FILE *fp1;
    char tmp_buff[20];
    fp1 = fopen("/proc/uptime", "r");
    if (fp1)
    {
        fscanf(fp1, "%s", tmp_buff);
        fflush(fp1);
        fclose(fp1);
    }

    // take the positive integer
    uint8_t flg = 0;
    for (uint8_t i = 0; i < 20; i++)
    {
        if (tmp_buff[i] == '.')
        {
            flg = 1;
        }
        if (flg == 1)
        {
            tmp_buff[i] = 0;
        }
    }
    sys_time.uptime = convert_string_to_int(tmp_buff);

#ifdef _DB_read_
    printf("Uptime: %d s\n", sys_time.uptime);
#endif
}

static int convert_string_to_int(char *str)
{
    int val = 0;
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        val *= 10;
        val += (uint8_t)str[i] - 48;
    }
    return val;
}