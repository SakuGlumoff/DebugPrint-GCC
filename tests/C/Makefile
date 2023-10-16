CFLAGS = -Wall -g -I../../ -Og

BUILD_DIR = build

basic:
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) basic.c ../../debug_print.c -o $(BUILD_DIR)/basic.exe

timestamp:
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -DDBG_PRINT_ENABLE_TIMESTAMP=1 timestamp.c ../../debug_print.c -o $(BUILD_DIR)/timestamp.exe

all: basic timestamp

clean:
	-rm -fR $(BUILD_DIR)
