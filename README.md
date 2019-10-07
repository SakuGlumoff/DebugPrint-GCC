# DebugPrint GCC

## About

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

Finally, you will need to implement the `int debug_print_callback(char* debugMessage, unsigned int length)`.
This callback function is called in the debug print functions so that the user can decide where to and how to print the debug messages.

## Configuration

* Define `DBG_PRINT_ENABLED` to 1/0 enable/disable debug printing.
* Define `DGB_PRINT_BUFFER_SIZE` to set the debug print message buffer size.

## Output

The colour of the output depends on the used debug level but message format stays the same.

The output format is `[<filename>:<function name>():<line number>]: <message>`.
An example output would be:

## License

This library is licensed under the MIT License. See the LICENSE file for details.

---
Saku Rautio, 2018
