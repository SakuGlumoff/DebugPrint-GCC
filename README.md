# DebugPrint GCC

![](https://github.com/SakuRautio/DebugPrint-GCC/workflows/Tests/badge.svg)

## About

C library for debug printing with GCC.

## Usage

Use the `DBG_PRINTF_X` macro for printing, where `X` is the debug level.
These levels and their coloured outputs are as follows:

| Level   | Colour |
| ------- | ------ |
| Debug   | Green  |
| Trace   | White  |
| Warning | Yellow |
| Error   | Red    |

Finally, you will need to implement the `int debug_print_callback(char* debugMessage, unsigned int length)`.
This callback function is called in the debug print functions so that the user can decide where to and how to print the debug messages.

See the `debug_print.h` file for more info.

## Configuration

* Define `DBG_PRINT_ENABLED` to 1/0 enable/disable debug printing.
* Define `DGB_PRINT_BUFFER_SIZE` to set the debug print message buffer size.
* Define `DBG_PRINT_ENABLE_TIMESTAMP` to 1/0 to include/exclude timestamps in debug messages.
  * **NOTE**: You must implement `time_t debug_print_get_timestamp(void)` which returns the timestamp from the system.

## Output

The colour of the output depends on the used debug level but message format stays the same.

The output format is `[<filename>:<function name>():<line number>]: <message>`.
An example output would be: `[main.c:main():13]: Initializing`.

## License

This library is licensed under the MIT License. See the LICENSE file for details.

---
Saku Rautio, 2018
