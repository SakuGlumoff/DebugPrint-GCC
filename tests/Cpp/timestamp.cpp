#include <stdio.h>
#include <time.h>

#include "debug_print.h"

int debug_print_callback(char* debugMessage, unsigned int length)
{
    printf("%s", debugMessage);
    return 0;
}

time_t debug_print_get_timestamp(void)
{
    return time(NULL);
}

int main(void)
{
    printf("--- Timestamp test start ---\n");

    DBG_PRINTF_DEBUG("Debug");
    DBG_PRINTF_TRACE("Trace");
    DBG_PRINTF_WARNING("Warning");
    DBG_PRINTF_ERROR("Error");

    for (int i = 0; i < 5; i++)
    {
        DBG_PRINTF_DEBUG("Debug (%d)", i);
        DBG_PRINTF_TRACE("Trace (%d)", i);
        DBG_PRINTF_WARNING("Warning (%d)", i);
        DBG_PRINTF_ERROR("Error (%d)", i);
    }

    printf("--- Timestamp test start ---\n");

    return 0;
}
