/* MIT License
 *
 * Copyright (C) 2018 Saku Rautio
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#include <string.h>
#include <ansi_colors.h>

/////////////////////////////////////////
//// Configurations
/////////////////////////////////////////

#ifndef DBG_PRINT_ENABLED
/**
 * Enable debug printing
 */
#define DBG_PRINT_ENABLED (1)
#endif /* DBG_PRINT_ENABLED */

#ifndef DGB_PRINT_BUFFER_SIZE
/**
 * How large can the debug message be in characters
 */
#define DGB_PRINT_BUFFER_SIZE (512)
#endif /* DGB_PRINT_BUFFER_SIZE */

////////////////////////////////////////
//// Callbacks
////////////////////////////////////////

/**
 * \brief Callback function to be implemented by the user.
 *        This callback function will be called to send the debug message out.
 *        You may implement your usage of the debug printing, be that
 *        printing to a UART port or logging to a file.
 */
extern void debug_print_callback(char* debugMessage, unsigned int length);

/////////////////////////////////////////
//// DebugPrint-API
/////////////////////////////////////////

#if DBG_PRINT_ENABLED
#define DBG_PRINTF_DEBUG(fmt, ...) debug_printf_ln(ANSI_COLOR_GREEN, __FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define DBG_PRINT_DEBUG(message) debug_print_ln(ANSI_COLOR_GREEN, __FILE__, __FUNCTION__, __LINE__, message)
#define DBG_PRINTF_TRACE(fmt, ...) debug_printf_ln(ANSI_COLOR_WHITE, __FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define DBG_PRINT_TRACE(message) debug_print_ln(ANSI_COLOR_WHITE, __FILE__, __FUNCTION__, __LINE__, message)
#define DBG_PRINTF_WARNING(fmt, ...) debug_printf_ln(ANSI_COLOR_YELLOW, __FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define DBG_PRINT_WARNING(message) debug_print_ln(ANSI_COLOR_YELLOW, __FILE__, __FUNCTION__, __LINE__, message)
#define DBG_PRINTF_ERROR(fmt, ...) debug_printf_ln(ANSI_COLOR_RED, __FILE__, __FUNCTION__, __LINE__, fmt, ## __VA_ARGS__)
#define DBG_PRINT_ERROR(message) debug_print_ln(ANSI_COLOR_RED, __FILE__, __FUNCTION__, __LINE__, message)
#else
#define DBG_PRINTF_DEBUG(fmt, ...)
#define DBG_PRINT_DEBUG(message)
#define DBG_PRINTF_TRACE(fmt, ...)
#define DBG_PRINT_TRACE(message)
#define DBG_PRINTF_WARNING(fmt, ...)
#define DBG_PRINT_WARNING(message)
#define DBG_PRINTF_ERROR(fmt, ...)
#define DBG_PRINT_ERROR(message)
#endif

/**
 * \brief Debug-print a parameterized text.
 *        This function adds the Windows style CR+LF to the end.
 */
void debug_printf_ln(const char* color, const char* fileName, const char* funcName, unsigned int lineNumber, const char* fmt, ...);

/**
 * \brief Debug-print a non-parameterized text.
 *        This function adds the Windows style CR+LF to the end.
 */
void debug_print_ln(const char* color, const char* fileName, const char* funcName, unsigned int lineNumber, const char* message);

#endif /* _DEBUG_PRINT_H_ */