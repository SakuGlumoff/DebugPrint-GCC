INCLUDES = \
-I../../

CFLAGS = -Wall -g $(INCLUDES) -Og

BUILD_DIR = build

all:
	mkdir $(BUILD_DIR)
	gcc $(CFLAGS) main.c ../../debug_print.c -o $(BUILD_DIR)/main.exe

clean:
	-rm -fR $(BUILD_DIR)
