/* MIT License
 *
 * Copyright (C) 2018 Saku Rautio
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include <debug_print.h>

static inline void _empty_debug_buffer(char* buffer)
{
    memset(buffer, '\0', DGB_PRINT_BUFFER_SIZE);
}

void debug_printf_ln(const char* color, const char* fileName, const char* funcName, unsigned int lineNumber, const char* fmt, ...)
{
    char parameterBuffer[DGB_PRINT_BUFFER_SIZE];
    char outgoingBuffer[DGB_PRINT_BUFFER_SIZE];
    va_list params;
    
    _empty_debug_buffer(parameterBuffer);
    _empty_debug_buffer(outgoingBuffer);
    
    va_start(params, fmt);
    vsnprintf(parameterBuffer, DGB_PRINT_BUFFER_SIZE, fmt, params);
    va_end(params);
    
    snprintf(outgoingBuffer, DGB_PRINT_BUFFER_SIZE, "%s[%s:%s():%u]: %s\r\n%s", color, fileName, funcName, lineNumber, parameterBuffer, ANSI_COLOR_RESET);
    
    debug_print_callback(outgoingBuffer, DGB_PRINT_BUFFER_SIZE);
}

void debug_print_ln(const char* color, const char* fileName, const char* funcName, unsigned int lineNumber, const char* message)
{
    char outgoingBuffer[DGB_PRINT_BUFFER_SIZE];
    
    _empty_debug_buffer(outgoingBuffer);
    
    snprintf(outgoingBuffer, DGB_PRINT_BUFFER_SIZE, "%s[%s:%s():%u]: %s\r\n%s", color, fileName, funcName, lineNumber, message, ANSI_COLOR_RESET);
    
    debug_print_callback(outgoingBuffer, DGB_PRINT_BUFFER_SIZE);
}
