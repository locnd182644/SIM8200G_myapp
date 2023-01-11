#ifndef _APP_UPTIME_H_
#define _APP_UPTIME_H_

#include "app_common.h"

typedef struct
{
    /* the total number of seconds the system
    has been running since its last restart */
    uint32_t uptime;
    /* the total number of seconds the machine
    has been idle */
    uint32_t idletime;
} TIME_INFO_t;
TIME_INFO_t sys_time;

void uptime_read_all(void);
static int convert_string_to_int(char *);

#endif