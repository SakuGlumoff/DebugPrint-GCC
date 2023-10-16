/* MIT License
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

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

#ifndef DBG_PRINT_NEWLINE
/**
 * The new line sequence to print after each message
 */
#define DBG_PRINT_NEWLINE "\n"
#endif

#ifndef DBG_PRINT_ENABLE_TIMESTAMP
/**
 * Enable printing a timestamp
 */
#define DBG_PRINT_ENABLE_TIMESTAMP (0)
#endif

#ifndef DBG_PRINT_TIMESTAMP_LENGTH
/**
 * How long can the timestamp be in characters
 */
#define DBG_PRINT_TIMESTAMP_LENGTH (25)
#endif

#ifndef DBG_PRINT_TIMESTAMP_FORMAT
/**
 * How should the timestamp be formatted
 */
#define DBG_PRINT_TIMESTAMP_FORMAT "%Y-%m-%dT%H:%M:%S%z"
#endif

#ifndef DGB_PRINT_BUFFER_SIZE
/**
 * How large can the debug message be in characters
 */
#define DGB_PRINT_BUFFER_SIZE (512)
#endif /* DGB_PRINT_BUFFER_SIZE */

#ifndef DBG_PRINT_BUFFER_TOO_SMALL
/**
 * Error code for the debug buffer being too small
 */
#define DBG_PRINT_BUFFER_TOO_SMALL (0xDEAD)
#endif /* DBG_PRINT_BUFFER_TOO_SMALL */

////////////////////////////////////////
//// Callbacks
////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif

/**
* \brief Callback function to be implemented by the user.
*        This callback function will be called to send the debug message out.
*        You may implement your usage of the debug printing, be that
*        printing to a UART port or logging to a file.
*/
extern int debug_print_callback(char *debugMessage, unsigned int length);

#if DBG_PRINT_ENABLE_TIMESTAMP
#include <time.h>
/**
 * \brief Callback function to be implemented by the user.
 *        This callback function will be called to get a timestamp for the debug message.
 */
extern time_t debug_print_get_timestamp(void);
#endif /* DBG_PRINT_ENABLE_TIMESTAMP */

#ifdef __cplusplus
}
#endif

/////////////////////////////////////////
//// DebugPrint-API
/////////////////////////////////////////

#if DBG_PRINT_ENABLED
#define DBG_PRINTF_DEBUG(fmt, ...) debug_printf_ln(ANSI_COLOR_GREEN, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define DBG_PRINTF_TRACE(fmt, ...) debug_printf_ln(ANSI_COLOR_WHITE, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define DBG_PRINTF_WARNING(fmt, ...) debug_printf_ln(ANSI_COLOR_YELLOW, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define DBG_PRINTF_ERROR(fmt, ...) debug_printf_ln(ANSI_COLOR_RED, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define DBG_PRINTF_DEBUG(fmt, ...)
#define DBG_PRINTF_TRACE(fmt, ...)
#define DBG_PRINTF_WARNING(fmt, ...)
#define DBG_PRINTF_ERROR(fmt, ...)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/**
* \brief Debug-print a parameterized text.
*        This function adds the Windows style CR+LF to the end.
*/
int debug_printf_ln(const char *color, const char *fileName, const char *funcName, unsigned int lineNumber, const char *fmt, ...);

/**
* \brief Debug-print a parameterized text.
*        This function doesn't add the Windows style CR+LF to the end.
*/
int debug_printf(const char *color, const char *fileName, const char *funcName, unsigned int lineNumber, const char *fmt, ...);


#ifdef __cplusplus
}
#endif
#endif /* _DEBUG_PRINT_H_ */
