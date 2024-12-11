CC = gcc
CFLAGS = -fPIC
LIB_NAME = libsort.so
SRC_DIR = libsort
EXE_NAME = exe
MAIN_SRC = src/main.c

.PHONY: all build clean

all: build

build: $(LIB_NAME) $(EXE_NAME)

$(LIB_NAME): $(SRC_DIR)/*.c
	$(CC) -shared -o $@ $(CFLAGS) $^

$(EXE_NAME): $(MAIN_SRC)
	$(CC) -o $@ $< -L. -lsort -Wl,-rpath=.

clean:
	rm -f $(LIB_NAME) $(EXE_NAME)
