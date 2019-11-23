#include <stdio.h>

#include "debug_print.h"

int debug_print_callback(char* debugMessage, unsigned int length)
{
    printf("%s", debugMessage);
    return 0;
}

int main(void)
{
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
    return 0;
}
