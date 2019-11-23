CFLAGS = -Wall -g -I../../ -Og

BUILD_DIR = build

all:
	mkdir $(BUILD_DIR)
	g++ $(CFLAGS) main.cpp ../../debug_print.c -o $(BUILD_DIR)/main.exe

clean:
	-rm -fR $(BUILD_DIR)
