# DebugPrint GCC
C library for debug printing with GCC.

## Usage
There are two types of macros. One for printing only a single message and other for printing a message with parameters.
`DBG_PRINTF_XXXX` for printing parametrized messages and `DBG_PRINT_XXXX` for printing single simple messages.

These two types of macros themselves are split into 4 parts, depending on the debugging level.
These levels and their coloured outputs are as follows:

| Level   | Colour |
| ------- | ------ |
| Debug   | Green  |
| Trace   | White  |
| Warning | Yellow |
| Error   | Red    |

Finally, you will need to implement the `void debug_print_callback(char* debugMessage, unsigned int length)`.   
This callback function is called in the debug print functions so that the user can decide where to and how to print the debug messages.

## Configuration
To enable/disable debug printing, define `DBG_PRINT_ENABLED` as 1 (for being enabled) or 0 (for being disabled).

To set the debug print message buffer size, define `DGB_PRINT_BUFFER_SIZE` with the size of your choosing, which is by default 512.

## License
This library is licensed under the MIT License. See the LICENSE file for details.

---
Saku Rautio, 2018
