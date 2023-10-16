CFLAGS = -Wall -g -I../../ -Og

BUILD_DIR = build

basic:
	mkdir -p $(BUILD_DIR)
	g++ $(CFLAGS) basic.cpp ../../debug_print.c -o $(BUILD_DIR)/basic.exe

timestamp:
	mkdir -p $(BUILD_DIR)
	g++ $(CFLAGS) -DDBG_PRINT_ENABLE_TIMESTAMP=1 timestamp.cpp ../../debug_print.c -o $(BUILD_DIR)/timestamp.exe

all: basic timestamp

clean:
	-rm -fR $(BUILD_DIR)
