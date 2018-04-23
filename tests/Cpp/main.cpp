#include <stdio.h>

#include "debug_print.h"

void debug_print_callback(char* debugMessage, unsigned int length) {
    printf("%s", debugMessage);
}

int main(void) {
    DBG_PRINT_DEBUG("Debug");
    DBG_PRINT_TRACE("Trace");
    DBG_PRINT_WARNING("Warning");
    DBG_PRINT_ERROR("Error");
    
    for (int i = 0; i < 5; i++) {
        DBG_PRINTF_DEBUG("Debug (%d)", i);
        DBG_PRINTF_TRACE("Trace (%d)", i);
        DBG_PRINTF_WARNING("Warning (%d)", i);
        DBG_PRINTF_ERROR("Error (%d)", i);
    }
    
    return 0;
}
